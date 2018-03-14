assume DS:data,CS:code
data segment
	g DB 77
	h DB 40
data ends
code segment
start:
	mov AX,data
	mov DS,AX
	mov AL,g
	mov DL,2
	mul DL		;AX:=AL*2
	mov BX,AX	
	mov AL,h
	mov DL,5
	mul DL		;AX:=AL*5
	sub BX,AX
	mov CX,BX
	add CX,80
	mov AX,4c00h
	int 21h
code ends
end start
	