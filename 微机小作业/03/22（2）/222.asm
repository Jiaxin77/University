data 	segment
x 		dw 5
result 	dw 0
data 	ends
stack 	segment stack
		dw 500h dup(?)	;堆栈空间
stack	ends
code 	segment
		assume cs:code,ds:data
start:	 
	 mov ax,data
	 mov ds,ax
	 mov ax,x
	 mov dx,x
	 call jisuan
	 mov result,ax
	 
	 mov dx,result
	;用debug看寄存器dx中的值
	 
	 mov ax,4c00h
	 int 21h
	 
jisuan proc
	push cx
	push dx
	
	mov bl,3
	mov bh,5
s:	mul dx	;x^2
	mul bl	;3x^2
	mov cx,ax
	mov ax,x
	mul bh	;5x
	add cx,ax
	sub cx,8
	mov ax,cx
	pop dx
	pop cx
	ret
jisuan endp

code ends 
end start



	 