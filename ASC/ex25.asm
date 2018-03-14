assume DS:data,CS:code
data segment
	a DB 28
	b DB 32
	c DB 126
	d DB 17
data ends
code segment
start: mov AX,data
	   mov DS,AX
	   mov AL,c
	   sub AL,a
	   sub AL,d
	   mov BL,AL  ;(c-a-d)
	   mov AL,c 
	   sub AL,b  ;c-b
	   add BL,AL ;BL:=BL+AL
	   sub BL,a
	   mov AX,4c00h
	   int 21h
code ends
end start
	   
	   
	   
	   
	   