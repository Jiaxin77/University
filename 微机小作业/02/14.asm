data segment
a 	 dw 3
b 	 dw 4
c	 dw 5
data ends
code segment
	 assume cs:code,ds:data
start:mov ax,data
	   mov ds,ax
	   
	   mov ax,a; 
	   mov bx,b ;ax<-a
	   mov dx,c
	   
	   add ax,bx ;a+b
	   cmp c,ax; c-(a+b),有借位，cf=1，不跳
	   jnc false ;
	   
	   add bx,dx ;b+c
	   cmp a,bx;a-(b+c)
	   jnc false
	   
	   mov ax,a
	   add ax,dx ;a+c
	   cmp b,ax ;b-(a+c)
	   jnc false
	   
	   jmp over
	   

false:
	   xor ax,ax ;清零cf

over: 
	   mov ax,4c00h
	   int 21h
code   ends
       end start
	  
	 

		


