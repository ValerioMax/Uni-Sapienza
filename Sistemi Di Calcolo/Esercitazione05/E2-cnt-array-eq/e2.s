.globl counteq

counteq:
	pushl %ebx
	pushl %edi
	pushl %ebp
	pushl %esi
	movl 20(%esp), %edi
	movl 24(%esp), %esi
	movl 28(%esp), %ebp
	xorl %ecx, %ecx
	xorl %eax, %eax
F:	cmpl %ebp, %ecx
	jge E1
	movw (%edi, %ecx, 2), %bx
	movw (%esi, %ecx, 2), %dx
	cmpw %dx, %bx
	jne E2
	incl %eax
E2:	incl %ecx
	jmp F
E1:	popl %esi
	popl %ebp
	popl %edi
	popl %ebx
	ret


