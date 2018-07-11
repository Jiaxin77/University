data 	segment
n 		db 3 dup(?)
buff 	dw 20 dup(10,-1,2,0,4,-50,5,15,77,29) ;200字
data 	ends
code 	segment
		assume cs:code,ds:data
start:	mov ax,data
		mov ds,ax
		
		mov cx,200 ; 计数
		xor bx,bx;清零
		xor dx,dx
		lea si,buff 
		sub si,2	;便于循环
find:   add si,2
		cmp word ptr[si],0 ;和0比较
		jz  zero
		jl  negative
		jg  positive
zero: 	inc bh
		jmp next
negative:inc bl
		 jmp next
positive:inc dh
		 jmp next
next:		loop find
		
		mov n,dh
		mov n+1,bh
		mov n+2,bl
		
		mov ax,4c00h
		int 21h
code	ends
		end start

