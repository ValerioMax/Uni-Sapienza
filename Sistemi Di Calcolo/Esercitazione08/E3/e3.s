.globl count_digits

count_digits:
	movl 4(%esp), %edx
	xorl %eax, %eax

W:	cmpb $0, (%edx)
	je E
	cmpb $48, (%edx)
	jl E1
	cmpb $57, (%edx)
	jg E1
	incl %eax
E1:	incl %edx
	jmp W
E:	ret