data 	segment
result 	db 45 dup(?)
row	   	db 0
line  	db 0
total	dw 9
data 	ends
code 	segment
		assume cs:code,ds:data
start: 	mov ax,data
		mov ds,ax
		
		mov bx,1;行
		mov cx,total ;外层循环次数为9
		
L1:		mov ss,cx ;存好外层循环
		mov di,1;列
		mov cx,bx ;内层循环次数为行数
		
L2:		
		;用于计算存在result的哪里 (row-1)*9+line-1
		mov si,bx 
		sub si,1
		mov ax,si
		mul total
		mov si,ax
		add si,di
		sub si,1
	
		;用于计算结果
		mov ax,bx 
		mul di ;隐含寻址，放在ax中
		mov result[si],al
		jmp cont
cont:	inc di ;列数+1
		loop l2
		mov cx,ss ;恢复外层循环次数
		inc bx	;行数+1
		loop l1
		
		;
		
		mov ax,4c00h
		int 21h
code 	ends
		end	start
