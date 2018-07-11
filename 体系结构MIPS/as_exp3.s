.text
main:
ADDIU  $r1,$r0,A #将向量A存入R1
ADDIU  $r2,$r0,B #将向量B存入R2
ADDIU  $r3,$r0,0 #用于放结果
ADDIU  $r4,$r0,10 #用于计数
loop:
LW	   $r5,0($r1)
LW	   $r6,0($r2)
ADDI   $r2,$r2,4
ADDI   $r1,$r1,4
MUL    $r7,$r5,$r6
ADDI   $r4,$r4,-1
ADD    $r3,$r3,$r7
BGTZ   $r4,loop #大于0转移

TEQ $r0,$r0

.data
A: 
.word 1,2,3,4,5,6,7,8,9,10
B:
.word 10,9,8,7,6,5,4,3,2,1
