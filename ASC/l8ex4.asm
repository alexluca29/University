assume ds:data,cs:code
data segment
	s1 db 'Sunday $'
	s2 db 'Monday $'
	s3 db 'Tuesday $'
	s4 db 'Wednesday $'
	s5 db 'Thurday $'
	s6 db 'Friday $'
	s7 db 'Saturday $'
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	
	;get current date
	mov ah,2Ah	
	int 21h
	
	;print the day (dl)
	mov ah,02h
	int 21h
	
	mov ah,02h
	mov dl,dh
	int 21h
	
	mov ah,02h
	mov dl,cl
	int 21h
	
	mov ah,02h
	mov dl,ch
	int 21h
	
	cmp al,0
	je sunday
	
	cmp al,1
	je monday
	
	cmp al,2
	je tuesday
	
	cmp al,3
	je wednesday
	
	cmp al,4
	je thursday
	
	cmp al,5
	je friday
	
	cmp al,6
	je saturday
	
	sunday:
		mov ah,09h
		mov dx,offset s1
		int 21h
		jmp final
		
	monday:
		mov ah,09h
		mov dx,offset s2
		int 21h
		jmp final
		
	tuesday:
		mov ah,09h
		mov dx,offset s3
		int 21h
		jmp final
		
	wednesday:
		mov ah,09h
		mov dx,offset s4
		int 21h
		jmp final
		
	thursday:
		mov ah,09h
		mov dx,offset s5
		int 21h
		jmp final
		
	friday:
		mov ah,09h
		mov dx,offset s6
		int 21h
		jmp final
		
	saturday:
		mov ah,09h
		mov dx,offset s7
		int 21h
		jmp final
		
	final:	
		mov ax,4c00h
		int 21h
code ends
end start