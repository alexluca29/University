assume cs:code,ds:data

data segment
x db 16
data ends

EXTRN result:BYTE
PUBLIC Change

code segment
	Change PROC
		push ds
		pop es
		;ax = s
		mov di,offset result
		mov si,ax
		
		bucla:
			LODSW
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
			
		mov al,'$'
		stosb
		
		ret
		Change ENDP
		
code ends
end