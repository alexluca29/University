assume DS:data,CS:code
data segment
	a DB 5
	b DD 8
	c DB 6
	d DB 4
	x DW ?
data ends
code segment
start:
	mov AX,data		; (a+b+c*d)/(9-a)
	mov DS,AX
	mov AL,a
	mov AH,0    ;AX=a
	mov DX,0	;DX=a
	mov CX,word ptr b
	mov BX,word ptr b+2
	add CX,AX
	adc BX,DX	;BX:CX=a+b
	mov AL,c
	mul d		;AX=c*d
	mov DX,0	;DX:AX=c*d
	add CX,AX
	adc BX,DX	;BX:CX=a+b+c*d
	mov AL,9
	sub AL,a	;AL=9-a	
	mov AH,0	;AX=9-a
	mov x,AX
	mov DX,BX
	mov AX,CX
	div x		;AX=DX:AX/x
	mov AX,4c00h
	int 21h
code ends
end start