[bits 32]

section .text 

extern  _printf
extern _exit

global  _main 

_main: 
	mov eax,[a]
	mov ebx,[b]
	cmp eax,ebx
	jz final
	
	bucla:
		cmp eax,ebx
		je final
		jg greater
		jmp peste
		greater:
			sub eax,ebx
		peste:
			sub ebx,eax
		loop bucla
		
	final:
		mov [gcd],eax
		
	push DWORD [gcd]
	push DWORD format
	call _printf
	add esp,8
	
	push    0
    call    _exit
    ret 
	
section .data
a dd 15
b dd 40
gcd dd 0
format db "The gcd is:%d",0