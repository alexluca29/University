[bits 32]

section .text 

extern  _printf
extern _exit

global  _main 

_main: 
		mov eax,[a]
		mov ebx,[b]
		add eax,ebx
		push DWORD eax
		push DWORD format
		call _printf
		add esp,8
		
        
        push    0
        call    _exit
        ret 

section .data
a dd 1
b dd 2
format db "The sum is:%d",0
