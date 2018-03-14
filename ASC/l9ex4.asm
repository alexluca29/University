assume cs:code,ds:data
data segment
	s dw 16,4532,6311,222
	result db 30 dup(?)
data ends

PUBLIC result
EXTRN Change:PROC

code segment
start:
	mov ax,data
	mov ds,ax
	
	mov ax,offset s
	call Change
	
	mov ah,09h
	lea dx,result
	int 21h
	
	mov ax,4c00h
	int 21h
code ends
end start