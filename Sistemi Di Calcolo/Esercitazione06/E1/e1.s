.globl list_add_first

list_add_first:
	pushl %ebx
	pushl %esi
	subl $4, %esp
	movl 16(%esp), %ebx
	movl (%ebx), %esi
	movl $8, (%esp)
	call malloc #NOTA: malloc come altre funzioni sporcano qualche registro quindi usare quelli speciali
	cmpl $0, %eax
	jne E1
	movl $1, %eax
	jmp E
E1:	movw 20(%esp), %dx
	movw %dx, (%eax)
	movl %esi, 4(%eax)
	movl %eax, (%ebx)
	xorl %eax, %eax
E:	addl $4, %esp
	popl %esi
	popl %ebx
	ret