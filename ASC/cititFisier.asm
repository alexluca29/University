assume cs:code,ds:data
data segment
	lFileName db ?
	maxFileName db 12
	giveName db 'Give the name of the file: $'
	fileName db 12 dup (?)
	zece dw 10
	buffer db 100 dup (?), '$'
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	
	;afisare mesaj pt citire
	mov ah,09h
	mov dx,offset giveName
	int 21h
	
	mov ah,0ah
	mov dx,offset maxFileName
	int 21h
	
	mov al,lFileName
	mov ah,0
	mov si,ax
	mov fileName[si],0
	
	mov ah,3dh
	mov al,0
	mov dx,offset fileName
	int 21h
	
	mov bx,ax
	
	goOn:
		mov ah,3fh
		mov cx,100
		mov dx,offset buffer
		int 21h
		
		mov si, ax
		mov buffer[si], '$'
		
		mov ah,09h
		int 21h
		cmp si,100
		je goOn
		
	mov ax,4c00h
	int21h
	
code ends
end start
		
		
	
	