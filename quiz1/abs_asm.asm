global absolute_asm

section .text
;note: rdi = value to convert

absolute_asm:
    push rbp
	mov rbp, rsp
	cdq
    xor eax, edx
    sub eax, edx

rexit: ;epilogue
    pop rbp
    ret