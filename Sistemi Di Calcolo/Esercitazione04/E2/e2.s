.globl find

find:
	pushl %ebx
	movl 8(%esp), %eax
	movl 12(%esp), %ecx
	movl 16(%esp), %edx
	movl $0, %ebx
F:	cmpl %ecx, %ebx
	jge E1
	incl %ebx
	cmpl %edx, (%eax, %ebx, 4)
	jne F
	movl $1, %eax
	popl %ebx
	ret
E1: movl $0, %eax
	popl %ebx
	ret
