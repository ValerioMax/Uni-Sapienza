.globl f

f:	movl 4(%esp), %eax
	movl 8(%esp), %ecx
	movl %eax, %edx
	addl %ecx, %eax
	subl %ecx, %edx
	imull %edx, %eax
	ret
