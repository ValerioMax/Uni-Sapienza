.globl min

min:	movl 4(%esp), %eax
		movl 8(%esp), %ecx
		movl 12(%esp), %edx
		cmpl %ecx, %eax
		jge E1
		cmpl %edx, %eax
		jge E2
		ret
	E2:	movl %edx, %eax
		ret
	E1:	cmpl %edx, %ecx
		jge E3
		movl %ecx, %eax
		ret
	E3: movl %edx, %eax
		ret
