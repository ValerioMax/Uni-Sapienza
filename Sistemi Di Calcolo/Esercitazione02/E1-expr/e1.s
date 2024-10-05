.globl f

f:	movl $5, %eax
	imull $2, %eax
	subl $5, %eax
	imull $3, %eax
	incl %eax
	ret