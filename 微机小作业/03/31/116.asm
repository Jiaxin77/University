
datas segment
information		db 100 dup(20 dup(0));存储学生信息，
grade 			db 100 dup(7 dup(0)); 只能存1位小数(6,7)
average_grade	db 2 dup(0);整数，小数
n0				db 0;90-100
n1				db 0;80-90
n2				db 0;70-80
n3				db 0;60-70
n4				db 0;不及格
number			db 3 dup(0);学生总数
stack			segment stack
				dw 500h dup(?)	;堆栈空间
stack			ends

student_number	db 'the number of students(1-99,0-quit):',0dh,0ah,'$'
student_inform	db 'the information of students(class-num-name):',0dh,0ah,'$'
student_grade	db 'the grade of this student(0.0-100.0):',0dh,0ah,'$'

average_grade_out db 0dh,0ah,'average_grade:',0dh,0ah,'$'
grade_num1		db 0dh,0ah,'90-100:',0dh,0ah,'$'
grade_num2		db 0dh,0ah,'80-90:',0dh,0ah,'$'
grade_num3		db 0dh,0ah,'70-80:',0dh,0ah,'$'
grade_num4		db 0dh,0ah,'60-70:',0dh,0ah,'$'
grade_num5		db 0dh,0ah,'<60:',0dh,0ah,'$'
grade_rank		db 0dh,0ah,'Grade rank:',0dh,0ah,'$'
huiche			db 0dh,0ah,'$'

datas ends

codes segment
	assume cs:codes,ds:datas
start:
	mov ax,datas
	mov ds,ax
	
	mov si,0 ;指向每个学生信息
	mov di,0 ;指向每个学生成绩
	mov cx,100;初始化学生数
	
	;学生总数
	mov dx,offset student_number;用户输入
	mov ah,09
	int 21h;用于显示
	
	call store_studentNum;调用存储总数函数,结果存入cx中
	cmp cx,0
	je quit
input:
	mov dx,offset student_inform
	mov ah,09
	int 21h
	
	call store_studentInform
	
	add si,20;指向下一学生，每个信息占位20
	
	mov dx,offset student_grade
	mov ah,09
	int 21h
	
	call store_studentGrade
	
	add di,7	;指向下个成绩，每个成绩占位7
	
	loop input;输入所有学生信息
	
	call sort;排序
	call average_select;平均成绩
	
	call sort_result;排序结果
quit:	
	mov ax,4c00h
	int 21h
	
;函数部分	
store_studentNum proc ;学生数存在cx中
	push ax
	push bx
	xor bx,bx;bx为正在录入第几位数,此处先清零
	
 p1:
	mov ah,01h	
	int 21h	;读取输入的单个字符
	cmp al,0dh ;是否输入回车
	je p2
	and al,0fh ;转bcd
	mov number[bx],al
	inc bx
	jmp p1	;继续读取
	
p2:
	cmp bx,2 ;bx是否大于2，数据录入到什么地步
	
	jz p3;等于2，录入完毕
	mov al,number	;小于2
	jmp p4
	
p3:
	mov ah,number;高位放al
	mov al,number+1
	aad		;BCD转二进制
p4:
	mov number+2,al
	xor cx,cx
	mov cl,number+2

	pop bx
	pop ax
	ret
store_studentNum endp
	
	
store_studentInform proc
	push ax
	push bx
	push dx
	
	mov al,18
	mov information[si],al
	
	lea dx,information[si]
	
	
	mov ah,0ah
	int 21h	;读取字符串
	
	;字符串中位置1自动读取了字符串的长度
	mov bl,information[si+1]	;传入字符串长度
	mov al,':'
	mov information[si+bx+2],al  ;将回车换成''
	mov information[si+19],'$';最后一个字符换成'$'，便于输出
	
	pop dx
	pop bx
	pop ax
	ret
	store_studentInform endp
	
store_studentGrade proc
	push ax
	push bx
	push cx
	push dx
	
	xor bx,bx	;bx为正在录入第几位数
	xor cx,cx	;cx为记录的小数点前的位数
	mov dx,di
	
d0:
	mov ah,01h
	int 21h	;读取输入的单个字符
	cmp al,0dh ;是否为回车
	jz d2
	cmp al,'.' ;是否为小数点
	jnz d1;	不是小数点
	mov bx,cx	
	inc bx ;记录小数点位置
d1:
	push di
	mov di,dx
	mov grade[di],al
	pop di
	
	inc cx ;记录输入字符的个数
	inc dx
	jmp d0
d2:
	cmp bx,0
	jnz d3	;有小数点
	cmp cx,3
	jz d4;等于100
	cmp cx,2
	jz d5 ;输入数目为2位数
	;否则为个位数
d6: 	;处理个位数


	mov al,grade[di]
	sub al,'0'
	mov grade[di+5],al;整数占0-5
	jmp gout
d5:		;处理两位数
	mov ah,grade[di]
	and ah,0fh	;取低4位
	mov al,grade[di+1]
	and al,0fh
	aad
	mov grade[di+5],al
	jmp gout
d4:		;处理100
	mov al,100
	mov grade[di+5],al
	jmp gout
d3:	;处理小数部分
	mov al,grade[di+bx]
	sub al,'0'
	mov grade[di+6],al;6,7为小数
	cmp bx,4
	jz d4;如果.在第四位，则整数部分为100
	jg gout;整数大于3位数
	cmp bx,3
	jz d5 ;如果.在第三位，则整数为两位数
	jmp d6 ;否则为个位数
gout:
	pop dx
	pop cx
	pop bx
	pop ax
	ret
store_studentGrade endp

sort proc	;书上p97 冒泡排序
	push ax
	push bx
	push cx
	push dx
	push si
	push di
	
	xor dx,dx	;清零
	mov cl,number+2;报错
	
Loop1:
	mov dx,cx	;存下外层循环，以防被破坏
	xor di,di
	xor si,si
Loop2:;先比整数再比小数
	mov al,grade[di+5]
	cmp al,grade[di+12]	;同后面一个数比较
	jg next	;大于
	jl swap1	;小于，交换
	mov al,grade[di+6];比较小数部分
	cmp al,grade[di+13]
	jge next
	jl swap1
swap1:
	mov bx,si	;当前数information所在位置
swapStill:	;交换information
	mov al,information[bx+2]
	xchg al,information[bx+22]
	mov information[bx+2],al
	inc bx
	cmp al,'$';是否到最后
	jnz swapStill
	
	push bx
	mov bx,0
swap2:	;交换成绩
	mov al,grade[di+bx]
	xchg al,grade[di+bx+7]
	mov grade[di+bx],al
	inc bx	;一位一位交换位数
	cmp bx,7;是否全部交换 
	jnz swap2
	pop bx
next:	;比较下一个
	add si,20
	add di,7
	loop Loop2
	mov cx,dx; 恢复外层循环
	loop Loop1
	
	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	
	ret
sort endp

average_select proc
	push ax
	push bx
	push cx
	push dx
	push si
	push di
	
	mov bx,0
	mov cx,0
	mov cl,number+2	;cl中保存学生人数
	mov di,0
	mov si,0
	
s1:
	mov al,grade[di+5]
	
	cmp al,100
	jz F90;等于100，也到90-100
	cmp al,90
	jge F90
	cmp al,80
	jge F80
	cmp al,70
	jge F70	
	cmp al,60
	jge F60
	mov dl,n4	;小于60
	inc dl 
	mov n4,dl
	jmp snext
snext:	;平均成绩，处理方式：整数部分*10+小数部分(小数部分里面存的只是数，所以是*10之后的)，结果先除以10再除学生人数
	mov al,grade[di+5];整数部分
	mov dl,10
	mul dl
	mov dl,grade[di+6]
	mov dh,0
	add ax,dx
	add bx,ax	;bx中放总值
	jmp s2
F90:
	mov dl,n0
	inc dl	;++
	mov n0,dl
	jmp snext
F80:
	mov dl,n1
	inc dl
	mov n1,dl
	jmp snext
F70:
	mov dl,n2
	inc dl 
	mov n2,dl
	jmp snext
F60:
	mov dl,n3
	inc dl
	mov n3,dl
	jmp snext

s2:
	add di,7
	loop s1
	
	mov dx,offset average_grade_out
	mov ah,09
	int 21h

	mov ax,bx
	mov dx,0
	mov cx,0
	
	
	mov cl,number+2
	div cx;除人数
	mov cl,10
	div cl

	call show;打印整数部分
	push ax
	mov dl,'.'
	mov ah,2	;输出单个字符
	int 21h
	pop ax
	mov al,ah
	call show
	
	mov dx,offset grade_num1;打印>90
	mov ah,09
	int 21h
	mov al,n0
	call show
	mov dx,offset grade_num2
	mov ah,09
	int 21h
	mov al,n1
	call show
	mov dx,offset grade_num3
	mov ah,09
	int 21h
	mov al,n2
	call show
	mov dx,offset grade_num4
	mov ah,09
	int 21h
	mov al,n3
	call show
	mov dx,offset grade_num5
	mov ah,09
	int 21h
	mov al,n4
	call show
sout:
	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret
	
average_select endp

sort_result proc	;排序结果
	push ax
	push bx
	push cx
	push dx
	push si
	push di
	
	mov dx,offset grade_rank	
	mov ah,09
	int 21h
	
	mov cx,0
	mov cl,number+2	;存学生人数
	mov di,0
	mov si,0
sr1:
	lea dx,information;貌似不加offset
	add dx,si
	add dx,2
	mov ah,09
	int 21h
	
	mov dx,offset huiche
	mov ah,09
	int 21h
	
	mov  grade [di+5],'$'
	mov dx,offset grade
	add dx,di
	mov ah,09
	int 21h
	
	mov dx,offset huiche
	mov ah,09
	int 21h
	
	mov dx,offset huiche
	mov ah,09
	int 21h
	
	add si,20
	add di,7
	loop sr1	
	
	
	pop di
	pop si
	pop dx
	pop bx
	pop ax
	
	ret
sort_result endp


show proc	;将二进制数输出的函数
		push ax
		push dx
		push cx
		push bx
		
		mov cl,100
		mov ah,0
		div cl		
		mov bx,ax
		cmp al,0
		jz x1	;商为0，原数小于100
		
		mov dl,al
		add dl,30h
		mov ah,2
		int 21h
x1:
		mov al,bh
		mov ah,0
		mov cl,10
		div cl
		mov bx,ax;保存余数
		
		cmp al,0
		jz x2;商为0，原数小于10
		
		mov dl,al
		add dl,30h
		mov ah,2
		int 21h
x2:	
		mov dl,bh
		add dl,30h
		mov ah,2
		int 21h
		
		pop bx 
		pop cx
		pop dx
		pop ax
		ret
show endp

codes ends
end start
	

	
	
	
	
	
	