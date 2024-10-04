.globl rc4_encrypt

rc4_encrypt:
	pushl %esi
	pushl %edi
	pushl %ebx
	pushl %ebp

	subl $20, %esp # spazio call + 4 per &rnd

	xorl %esi, %esi # n
	xorl %edi, %edi # i
	xorb %bl, %bl # j
	movl 44(%esp), %ebp
W:	cmpb $0, (%ebp)
	je E
	incl %edi
	andl $255, %edi
	movl 40(%esp), %eax # appoggio
	movb (%eax, %edi, 1), %cl # appoggio
	addb %cl, %bl
	
	movl 40(%esp), %eax # appoggio
	movl %eax, (%esp)
	movl %edi, 4(%esp)
	movb %bl, 8(%esp)
	leal 16(%esp), %eax # appoggio
	movl %eax, 12(%esp)
	call rc4_helper

	movl 16(%esp), %eax # appoggio
	xorb (%ebp), %al
	movl 48(%esp), %ecx # appoggio
	movb %al, (%ecx, %esi, 1)
	incl %ebp
	incl %esi
	jmp W

E:	addl $20, %esp
	popl %ebp
	popl %ebx
	popl %edi
	popl %esi
	
	ret
