ASSUME DS:data,CS:code
data segment
	sir DW 12345,20778,4596
	len equ $-sir
	d DB len*4 DUP(?)
	x DB 10
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	
	mov si,offset sir
	mov ax,SEG sir
	mov ds,ax
	
	mov di,offset d
	mov ax,seg d 
	mov es,ax
	
	CLD
	mov cx,len
	
	bucla:
		LODSW 		 ;div 10 ah=rest al=cat care e impartit din nou
		imparte:
			div x
			mov bl,al
			mov al,ah
			STOSB
			mov ah,0
			mov al,bl
			cmp al,0
			loop imparte
		loop bucla
	mov ax,4c00h
	int 21h
code ends
end start