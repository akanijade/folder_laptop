global absolute_asm

section .text
;note: rdi = value to convert

absolute_asm:
    push rbp
    mov rbp, rsp
    mov eax, edi
    cmp eax, 0    
    jl two
    jmp rexit
   
two:
	xor eax, 0xFFFFFFFF
	add eax, 1
 
rexit: ;epilogue
    pop rbp
    ret
