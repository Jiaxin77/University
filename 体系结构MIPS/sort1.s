.text
main:
ADDIU $r1,$r0,A #存放初始数组
ADDIU $r3,$r0,9 #计数

loop1:
ADDIU $r6,$r0,0 #初始化R6
LW    $r4,0($r1) #取第一个数
LW    $r5,4($r1) #取下一个数
DSUB  $r6,$r4,$r5 #比较大小
BLEZ  $r6,unswitch #若r6<=0即r4<=r5，则不交换位置
switch1:
SW    $r5,0($r1)
SW    $r6,4($r1)
unswitch:
ADDI  $r1,$r1,4 #r1指向下一个数
ADDI  $r3,$r3,-1 #计数-1
BGTZ  $r3,loop1  #R3>0时转移，继续

output:
ADDI  $r1,$r1,-40 #R1指向初始
ADDIU $r2,$r0,10 #计数
loopOP:
LI    $v0,1   #打印整数
LW    $a0,0($r1)
syscall
ADDI  $r1,$r1,4
ADDI  $r2,$r2,-1
BGTZ  $r3,loopOP  

LI    $v0,10 #结束
syscall
TEQ   $r0,$r0

.data
A:
.word 4,6,10,2,3,3,5,1,9,7

 

