assume ds:data,cs:code
data segment
	msg db 'Numele fisierului: $'
	maxFileName db 12
	lFileName db ?
	fileName db 12 dup(?)
	getErrorMsg db 'Can.t get file attributes $'
	out_sir db '000000'
	zece dw 10
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	
	;afisare mesaj fisier
	mov ah,09h
	mov dx,offset msg
	int 21h
	
	;citire de la tastatura
	mov ah,0ah
	mov dx,offset maxFileName
	int 21h
	
	;transformare nume fisier in ASCII
	mov al,lFileName
	xor ah,ah
	mov si,ax
	mov fileName[si],0
	
	;get file attributes
	mov ah,43h
	mov al,0
	mov cx,0
	mov dl,fileName	
	int 21h
	jc getAttrError
	
	;display file attributes(located in cx) (atribute:1234 =>"1234")
	;mov si,cx
	;mov byte ptr [si],0
	;mov ah,02h
	;mov dl,byte ptr [si]
	;int 21h
	
	;mov dl,cl
	;add dl,'0'
	;mov ah,02h
	;int 21h
	;jmp endPrg
	
	mov di,offset out_sir + 6
	mov ax,cx ;(put the attr in ax)
	mov dx,0
	std
	repeta:
	div zece
	mov bx,ax
	mov al,dl
	stosb
	mov ax,bx
	cmp ax,0
	jne repeta
	
	getAttrError:
			; print getErrorMsg
			mov ah, 09h
			mov dx, offset getErrorMsg
			int 21h
			jmp endPrg
	endPrg:
		mov ax,4c00h
		int 21h
code ends
end start
	