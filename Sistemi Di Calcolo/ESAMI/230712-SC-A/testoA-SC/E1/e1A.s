.globl adler32

adler32:
	pushl %esi
	pushl %edi
	pushl %ebx
	pushl %ebp
	subl $8, %esp # call + &k

	movl 28(%esp), %edx # appoggio
	movl 32(%esp), %ecx # appoggio

	cmpl $0, %edx
	jne E1
	jmp EE
E1:	cmpl $0, %ecx
	jne E2
	jmp EE

E2:	leal 4(%esp), %eax
	movl %eax, (%esp)
	call get_adler_constant
	movl $1, %ebx
	movl $0, %ebp

	xorl %edi, %edi
F:	cmpl 32(%esp), %edi
	jge E
	movl 28(%esp), %eax
	movb (%eax, %edi, 1), %cl
	xorl %eax, %eax
	movb %cl, %al
	addl %ebx, %eax
	movl %eax, %edx
	shrl $31, %edx # oppure shrl ?
	idivl 4(%esp)

	movb %dl, %bl

	movl %ebp, %eax
	addl %ebx, %eax
	movl %eax, %edx
	shrl $31, %edx
	idivl 4(%esp)

	movl %edx, %ebp

	incl %edi
	jmp F

E:	shll $16, %ebp
	orl %ebp, %ebx
	movl %ebx, %eax

	addl $8, %esp
	popl %ebp
	popl %ebx
	popl %edi
	popl %esi
	ret

EE:	xorl %eax, %eax
	addl $8, %esp
	popl %ebp
	popl %ebx
	popl %edi
	popl %esi
	ret
