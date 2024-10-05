.globl fib

fib:
	movl 4(%esp), %eax
	movl $0, %ecx
	movl $1, %edx
	cmpl $0, %eax
	jne E1
	movl %ecx, %eax
	ret
E1:	cmpl $1, %eax
	jne E2
	movl %edx, %eax
	ret
E2:	cmpl $1, %eax
	jbe E3
	decl %eax
	addl %edx, %ecx
	addl %edx, %ecx
	subl %ecx, %edx
	negl %edx
	subl %edx, %ecx
	jmp E2
E3:	movl %edx, %eax
	ret
