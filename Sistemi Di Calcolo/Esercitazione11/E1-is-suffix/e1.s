.globl is_suffix

is_suffix:
	pushl %esi
	pushl %edi
	movl 12(%esp), %esi
	movl 16(%esp), %edi
W1:	cmpb $0, (%esi)
	je W2
	incl %esi
	jmp W1
W2:	cmpb $0, (%edi)
	je W3
	incl %edi
	jmp W2
W3:	cmpl %esi, 12(%esp)
	je L
	cmpl %edi, 16(%esp)
	je L
	decl %esi
	decl %edi
	movb (%esi), %cl
	cmpb (%edi), %cl
	jne L
	jmp W3
L:	movl %esi, %ecx
	movb (%esi), %dl
	cmpl %ecx, 12(%esp)
	sete %cl
	cmpb (%edi), %dl
	sete %dl
	xorl %eax, %eax
	cmpb %dl, %cl
	sete %al
	cmpb $1, %cl
	sete %al
	popl %edi
	popl %esi
	ret
