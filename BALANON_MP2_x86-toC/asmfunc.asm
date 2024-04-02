;assembly part using x86-64

section .data
incA dq 0.001			;increment value of vector A
incB dq 0.1				;increment value of vector B
decN dq 1.0				;minus 1
dq0 dq 0.0
sdot dq	0.0

section .text
bits 64
default rel			;to handle address relocation

;asm function for dot product
global asmDotProduct

asmDotProduct:
	;1st para (xmm0) = vecA
	;2nd para (xmm1) = vecB
	;3rd para (xmm2) = n (vector size)
	;return register = xmm0 (also 1st para)

	DotProductLoop:
	vmulsd xmm6, xmm0, xmm1		;xmm6 = vecA*vecB
	movsd xmm7, [sdot]			;xmm7 = curr sdot
	addsd xmm7, xmm6
	movsd [sdot], xmm7
	addsd xmm0, [incA]			;inc vecA
	addsd xmm1, [incB]			;inc vecB

	subsd xmm2, [decN]
	ucomisd xmm2, [dq0]			;compare(iteration, 0)
	JNE DotProductLoop
	
	movsd xmm0, [sdot]

	ret