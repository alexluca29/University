[bits 32]

section .text 

extern  _printf
extern _exit
extern __time32
extern _getchar

global  _main 

_main:
		push k
		call __time32
		add esp,4
		mov [var],eax
		
		bucla:
			call _getchar
			
			cmp eax,'$'
			je final
			
			mov eax,[var]
			and eax,00000000111111111111111100000000b
			shr eax,8
			mul ax
			add eax,[k]
			mov [var],eax
			
			push    DWORD  eax
			push 	DWORD  format
			call    _printf
			add     esp, 8
			
			loop bucla
		final:
			push    0
			call    _exit
			ret 

section .data
var dd 0
k dd 12345
format db "%d ",0

