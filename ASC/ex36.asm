assume DS:data,CS:code
data segment
	e DW 5
	f DW 11
	g DW 4
data ends
code segment
start:
	mov AX,data
	mov DS,AX
	mov AX,e 
	add AX,f
	mul g		;DX:AX=(e+f)*g
	mov AX,4c00h
	int 21h
code ends
end start