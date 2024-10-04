.globl init_matrix

init_matrix:
	pushl %esi
	pushl %edi
	pushl %ebx
	pushl %ebp
	subl $8, %esp

	xorl %esi, %esi
F1:	cmpl 32(%esp), %esi
	jae E
	xorl %edi, %edi
F2:	cmpl 32(%esp), %edi
	jae P
	movl %esi, (%esp)
	movl %edi, 4(%esp)
	call value
	movl 28(%esp), %ecx
	movl (%ecx, %esi, 4), %ecx # metto in ecx il puntatore all'i-esima riga
	movw %ax, (%ecx, %edi, 2)
	incl %edi
	jmp F2
	
P:	incl %esi
	jmp F1
E:	addl $8, %esp
	popl %ebp
	popl %ebx
	popl %edi
	popl %esi
	ret
