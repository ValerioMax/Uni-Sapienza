.globl lcm

lcm:
	pushl %esi
	pushl %edi
	pushl %ebx
	movl 16(%esp), %edi
	movl 20(%esp), %esi
	movl %esi, %eax
	cmpl %esi, %edi
	cmovgl %edi, %eax
	movl %eax, %ebx
W:	movl %eax, %edx
	sarl $31, %edx
	idivl %edi

	cmpl $0, %edx
	cmovel $1, %ecx

	movl %ebx, %eax
	movl %eax, %edx
	sarl $31, %edx
	idivl %esi

	cmpl $0, %edx
	cmovel $1, %edx

	movl %ebx, %eax

	cmpl %ecx, %edx
	jne E1
	cmpb $1, %ch
	jne E1
	jmp E

E1:	incl %eax
	incl %ebx
	jmp W
E:	popl %ebx
	popl %edi
	popl %esi
	ret


