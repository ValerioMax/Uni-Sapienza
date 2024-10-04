.globl clone

clone:
	pushl %edi
	pushl %esi
	subl $12, %esp
	movl 24(%esp), %edi
	movl 28(%esp), %esi
	movl %esi, (%esp)
	call malloc
	cmpl $0, %eax
	jne E1
	xorl %eax, %eax
	jmp E
E1:	movl %eax, (%esp)
	movl %edi, 4(%esp)
	movl %esi, 8(%esp)
	call memcpy
E:	addl $12, %esp
	popl %esi
	popl %edi
	ret
