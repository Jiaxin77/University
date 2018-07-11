.text
main:
ADDIU $r1,$r0,A #存放初始数组
ADDIU $r3,$r0,9 #计数 外层循环

loop0:
ADDIU $r2,$r0,0 #已经有几个数位置定了
loop1:
LW    $r4,0($r1) #取第一个数
LW    $r5,4($r1) #取下一个数
DSUB  $r6,$r4,$r5 #比较大小
BLEZ  $r6,unswitch #若r6<=0即r4<=r5，则不交换位置
switch1:
SW    $r5,0($r1)
SW    $r4,4($r1)
unswitch:
ADDI  $r2,$r2,1 #已经定下的数+1
ADDI  $r1,$r1,4 #r1指向下一个数  ##
DSUB  $r21,$r3,$r2 #还有数位置未定，则循环
BGTZ  $r21,loop1  #R21>0时转移，继续   
ADDI  $r8,$r0,-4
ADDI  $r3,$r3,-1##
MUL   $r9,$r2,$r8 
ADD   $r1,$r1,$r9 #r1指向最开始
BGTZ  $r3,loop0
output:

LW    $r10,0($r1) 
LW    $r11,4($r1)
LW    $r12,8($r1)
LW    $r13,12($r1)
LW    $r14,16($r1)
LW    $r15,20($r1)
LW    $r16,24($r1)
LW    $r17,28($r1)
LW    $r18,32($r1)
LW    $r19,36($r1)


TEQ  $r0,$r0
.data
A:
.word 4,6,10,2,3,3,5,1,9,7

 #排完应该是 1,2,3,3,4,5,6,7,9,10

