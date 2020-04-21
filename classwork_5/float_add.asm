
global sum
section .text
;note : rdi = address of source array
; rsi = array size
sum:
    push rbp
    mov rsp, rbp
    movss xmm1, dword[rdi]  ;move the value in rdi to xmm1
    add rdi, 4              ;go to the next address in array
    addss xmm0, xmm1        ;add the float numbers
    sub rsi, 1              ;decrement to keep track of loop 
    cmp rsi, 0              ;loop condition
    jne sum                 ;jump

rexit:
    pop rbp
    ret
