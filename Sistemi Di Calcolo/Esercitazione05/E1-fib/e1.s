.globl fib

fib:
	pushl %esi
	pushl %edi
	subl $4, %esp
	movl 16(%esp), %esi
	cmpl $2, %esi
	jge E1
	movl $1, %eax
	jmp E
E1:	subl $1, %esi
	movl %esi, (%esp)
	call fib
	movl %eax, %edi

	subl $1, %esi
	movl %esi, (%esp)
	call fib
	addl %edi, %eax
	
E:	addl $4, %esp
	popl %edi
	popl %esi
	ret


