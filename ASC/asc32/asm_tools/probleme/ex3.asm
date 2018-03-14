[bits 32]

section .text 

extern  _printf
extern _exit

global  _main 

_main:
	mov esi,0
	mov ecx,len
	bucla:
		mov eax,a[esi]
		cmp eax,0
		jl negativ
		add [s],eax
		add esi,4
		loop bucla
		jmp final
		negativ:
			neg eax
			add [s],eax
			add esi,4
			loop bucla
	final:
		push DWORD [s]
		push DWORD format
		call _printf
		add esp,8
		
		push    0
		call    _exit
		ret
	
section .data
a dd 1,-10,5,2,5,0,-9,17
len EQU ($-a)/4
s dd 0
format db "The sum is:%d",0
