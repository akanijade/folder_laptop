
global sum
section .text
;note : edi = address of source array
; esi = array size
sum:
    push rbp
    mov rsp, rbp
    movss xmm0, dword[rdi]
    add rdi, 4
    addss xmm0, dword[rdi]
    sub rsi, 1
    cmp rsi, 0
    jne sum

rexit:
    pop rbp
    ret
