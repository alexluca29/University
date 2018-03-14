%include "msdn_defs.inc"

[bits 32]

section .text 

%define BYTES_TO_READ						1024

extern  _printf
extern _exit

extern CreateFileA, ReadFile, WriteFile, SetFilePointer, CloseHandle
extern GetLastError

global  _main 

_main: 
		;HANDLE CreateFileA(
		;	FileName,
		;	GENERIC_READ | GENERIC_WRITE,
		;	0,
		;	NULL,
		;	OPEN_EXISTING,
		;	FILE_ATTRIBUTE_NORMAL,
		;	NULL)
        
		push dword NULL
		push dword FILE_ATTRIBUTE_NORMAL
		push dword OPEN_EXISTING
		push dword NULL
		push dword 0
		push dword GENERIC_READ | GENERIC_WRITE
		push dword FileName
		
		call CreateFileA
		
        ; in case of failure, CreateFileA returns INVALID_HANDLE_VALUE
		cmp		eax, INVALID_HANDLE_VALUE
		je		.error

		mov		[hFile], eax  ; save handle in variable

		;BOOL ReadFile(
			;	Handle, ; returned by createfile
			;	Buffer  ; variabila definita unde se salveaza ce am citit din fisier
			;	noOfBytesToRead ; dimensiunea sirului
			;	noOfBytesRead ; adresa unei variabile in care se va completa cate caractere a citit
			; NULL)

        ; in case of failure, ReadFile returns 0
		
		push dword NULL
		push dword bytesRead
		push dword 1024
		push dword buf
		push dword [hFile]
		call ReadFile
		
		cmp		eax, 0
		je		.finish

		push dword buf
		call _printf
		add esp,4

		;BOOL WriteFile(
		;	Handle ; returned by create file, value!
		;	Buffer ; variabila definita care se va scrie in fisier
		;	noOfBytesToWrite ; dimensiunea sirului - cat se va scrie in fisier
		;	noOfBytesWritten ; adresa unei variabile in care se va completa cate caractere a scris
		;	NULL)
        
        ; in case of failure, WriteFile returns 0
		
		push dword NULL
		push dword bytesWritten
		push dword len
		push dword buf_out
		push dword [hFile]
		call WriteFile
		
		cmp eax,0
		jz		.error

		; BOOL CloseHandle(
		;    handle) ; returned by CreateFile
        
		push dword [hFile]
		call CloseHandle
		
		jmp .success
	.error:

        call	GetLastError  ; obtain error code for last operation
        
		push	eax           ; eax = error code - see "msdn system error codes" for details
		push	fail_str
		call	_printf
        add     esp, 4*2
        
        jmp .finish
        
    .success:
        push    DWORD success_str
        call    _printf
        
	.finish:

        push    0
        call    _exit
        ret 

section .data

hFile:			dd		0
buf:			resb	BYTES_TO_READ
bytesRead:		dd		0
bytesWritten:	dd		0
FileName:		db		'abc.txt', 0
fail_str:		db		'Failed with error code %d', 0xA, 0
success_str:    db      'Execution successfull!',0xA, 0
buf_out 		db 		'Ana are mere',0
len 			equ		$-buf_out
