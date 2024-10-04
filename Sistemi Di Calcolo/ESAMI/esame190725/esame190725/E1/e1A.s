.globl most_freq_char

most_freq_char:
	pushl %esi
	pushl %edi
	pushl %ebx
	pushl %ebp
	subl $8, %esp
	movl 28(%esp), %ebp
	movl 32(%esp), %edi
	movl %edi, (%esp)
	movl $256, 4(%esp)
	call clear

W:	cmpb $0, (%ebp)
	je E0
	xorl %ebx, %ebx
	movb (%ebp), %bl
	incl (%edi, %ebx, 4)
	incl %ebp
	jmp W

E0:	xorl %ecx, %ecx
	xorl %esi, %esi
F:	cmpl $256, %ecx
	jge E
	movl (%edi, %ecx, 4), %edx
	cmpl (%edi, %esi, 4), %edx
	jle E1
	movl %ecx, %esi
E1:	incl %ecx
	jmp F
E:	movl %esi, %eax
	addl $8, %esp
	popl %ebp
	popl %ebx
	popl %edi
	popl %esi
	ret
