assume DS:data,CS:code
data segment
	a DB 01101000b
	b DB 00100100b
	c DB 11000111b
	d DB 10010110b
data ends
code segment
start:
	mov AX,data
	mov DS,AX
	
	mov AX,0
	mov BL,a
	and BL,01110000b		;bx=0 110 0000b
	mov cl,4
	shr bl,cl			;bl=00000110
	add AL,BL			;ax=a
	
	mov BL,b
	and BL,01110000b
	mov cl,4
	shr bL,cl
	add AL,BL
	
	mov BL,c
	and BL,01110000b
	mov cl,4
	shr bL,cl
	add AL,BL
	
	mov BL,d
	and BL,01110000b
	mov cl,4
	shr bL,cl
	add AL,BL
	
	mov AX,4c00h
	int 21h
code ends
end start
	
	
	
