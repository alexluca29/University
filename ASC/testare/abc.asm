assume cs:code,ds:data
data segment
	lFileName db ?
	maxFileName db 12
	giveName db 'Give the name of the file: $'
	fileName db 12 dup (?)
	zece dw 10
	buffer db 100 dup (?), '$'
	openErrorMsg db 'File does not exist.$'
	readErrorMsg db 'Can.t read the file.$'
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
	
	jc openError
	
	mov bx,ax
	
	goOn:
		mov ah,3fh
		mov cx,100
		mov dx,offset buffer
		int 21h
		
		jc readError
		
		mov si, ax
		mov buffer[si], '$'
		
		mov ah,09h
		int 21h
		cmp si,100
		je goOn
		
	jmp endPrg 	; jump over the error handling code

	openError:		; print the openErrorMsg string using function 09h of interrupt 21h
		mov ah, 09h
		mov dx, offset openErrorMsg
		int 21h
		jmp endPrg 

	readError:		; print the readErrorMsg string using function 09h of interrupt 21h
		mov ah, 09h
		mov dx, offset readErrorMsg
		int 21h 

	endPrg:
		mov ax,4c00h
		int 21h
	
code ends
end start
		
		
	
	