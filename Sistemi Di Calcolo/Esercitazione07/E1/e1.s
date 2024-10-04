.globl binsearch

binsearch:
	pushl %ebx
	pushl %esi
	pushl %edi
	movl 16(%esp), %ebx
	movl 20(%esp), %esi
	movl 24(%esp), %edi
	xorl %ecx, %ecx
	movl %esi, %edx
W:	cmpl %edx, %ecx
	jge E
	movl %ecx, %eax
	addl %edx, %eax
	sarl $1, %eax
	cmpl %edi, (%ebx, %eax, 4)
	jne E1
	movl $1, %eax
	jmp L
E1:	cmpl %edi, (%ebx, %eax, 4)
	jle E2
	movl %eax, %edx
	jmp W
E2:	movl %eax, %ecx
	incl %ecx
	jmp W
E:	xorl %eax, %eax
L:	popl %edi
	popl %esi
	popl %ebx
	ret
