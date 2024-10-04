.globl div_vectors

div_vectors:
	pushl %esi
	pushl %edi
	pushl %ebx
	pushl %ebp
	subl $4, %esp
	
	xorl %eax, %eax
	cmpl $0, 24(%esp)
	jne E1
	jmp END
E1:	cmpl $0, 28(%esp)
	jne E2
	jmp END
E2: cmpl $0, 32(%esp)
	jne E3
	jmp END

E3: movl 32(%esp), %eax
	imull $4, %eax # controllare sizeof(int)
	movl %eax, (%esp)
	call malloc
	movl %eax, %ebp

	xorl %ecx, %ecx
F:	cmpl 32(%esp), %ecx
	jge END1
	movl 24(%esp), %esi
	movl 28(%esp), %edi
	movl (%esi, %ecx, 4), %eax
	movl %eax, %edx
	shrl $31, %edx
	idivl (%edi, %ecx, 4)
	movl %eax, (%ebp, %ecx, 4)
	incl %ecx
	jmp F
END1:
	movl %ebp, %eax
END:
	addl $4, %esp
	popl %ebp
	popl %ebx
	popl %edi
	popl %esi
	ret
	
