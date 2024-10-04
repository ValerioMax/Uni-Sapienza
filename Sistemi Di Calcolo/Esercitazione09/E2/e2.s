.globl crc32b

crc32b:
	pushl %esi
	pushl %edi
	pushl %ebx
	pushl %ebp
	subl $8, %esp
	movl 28(%esp), %esi
	movl 32(%esp), %edi
	xorl %ecx, %ecx
	notl %ecx
	movl %ecx, %ebp
W:	cmpl $0, %edi
	jle E
	decl %edi
	movsbl (%esi), %ecx
	incl %esi
	xorl %ebp, %ecx
	leal (%ebx), %eax
	movl %eax, (%esp)
	andl $0xFF, %ecx
	movl %ecx, 4(%esp)
	call get_constant
	sarl $8, %ebp
	xorl %ebx, %ebp
	jmp W
E:	xorl %eax, %eax
	notl %eax
	xorl %ebp, %eax
	addl $8, %esp
	popl %ebp
	popl %ebx
	popl %edi
	popl %esi	
	ret
