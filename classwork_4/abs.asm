global absolute_asm

section .text
;note: rdi = value to convert

absolute_asm:
    push rbp        
    mov rbp, rsp
    mov eax, edi        ;move the first parameter to eax
    cmp eax, 0          ;compare if value is less than 0
    jl two              ;jump to two if it's less than 0
    jmp rexit           ;jump to rexit if it's greater than 0
   
two:
	xor eax, 0xFFFFFFFF     ;use logical exclusive or to flip the bits in eax
	add eax, 1              ;adding 1 to the end of least significant bit
 
rexit: ;epilogue
    pop rbp                 
    ret                     ;exit
