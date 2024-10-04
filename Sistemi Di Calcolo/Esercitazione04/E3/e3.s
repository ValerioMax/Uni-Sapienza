.globl my_strcmp

my_strcmp:
	movl 4(%esp), %eax
	movl 8(%esp), %ecx
W:	movb (%eax), %dl
	cmpb $0, %dl
	je E1
	cmpb %dl, (%ecx)
	jne E1
	incl %eax
	incl %ecx
	jmp W
E1:	movb %dl, %al
	subb (%ecx), %al
	ret
	