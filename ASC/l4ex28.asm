assume DS:data,CS:code
data segment
	a DW 5
	b DB 4
	c DW 7
	x DW ?
data ends
code segment
start:
	mov AX,data
	mov DS,AX
	mov AX,a
	mov BX,100
	imul BX			;DX:AX=AX*100
	mov CX,DX
	mov BX,AX
	mov AL,b
	cbw				;AX=b(word)
	cwd				;DX:AX=b
	add BX,AX
	adc CX,DX		;CX:BX=(a*100+b)
	mov AL,b
	cbw				;AX=b
	add AX,c		;AX=b+c
	sbb AX,1		;AX=b+c-1
	mov x,AX ;si mov si idiv
	mov DX,CX
	mov AX,BX
	idiv x			;DX:AX/x=AX 
					;DX:AX%x=DX
	mov AX,4c00h
	int 21h
code ends
end start
	
	
	