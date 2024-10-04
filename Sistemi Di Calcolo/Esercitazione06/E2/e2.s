.globl list_equal

list_equal:
	pushl %esi
	movl 8(%esp), %eax
	movl 12(%esp), %edx
W:	cmpl $0, %eax
	je E3
	cmpl $0, %edx
	je E3
	movw (%eax), %cx
	movw (%edx), %si
	cmpw %cx, %si
	je E1
	xorl %eax, %eax
	jmp E
E1:	movl 4(%eax), %eax
	movl 4(%edx), %edx
	jmp W

E3:	cmpl $0, %eax
	jne E2
	cmpl $0, %edx
	jne E2
	movl $1, %eax
	jmp E
E2:	movl $0, %eax
E:	popl %esi
	ret
