assume ds:data,cs:code
data segment
	s db 1,5,3,8,2,9
	len EQU $-s
	d1 db len DUP (?)
	d2 db len DUP (?)
data ends
code segment
start:
	mov dx,data
	mov ax,dx
	
	mov cx,len
	jcxz final
	mov si,0
	bucla:
		mov al,byte ptr s[si]
		test al,00000001b
		jnz impar
		par:
			mov byte ptr d1[si],al
			jmp peste
		impar:
			mov byte ptr d2[si],al
		peste:
			inc si
			loop bucla
	
	
	final:
		mov ax,4c00h
		int 21h
code ends
end start