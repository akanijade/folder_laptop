global evens_and_odds


section .text
;note: rdi = source array address
;      rsi = even array address
;      rdx = odd array address
;      rcx = size of source array
;prologue
evens_and_odds:
    push rbp
	mov rbp, rsp
	mov r15, 0          ;n is number of even numbers
    cmp rcx, 0          ;size
    je rexit


next:
    sub rcx, 1          ;decrease size by 1 byte
    cmp rcx, -1         ;exiting condition
    je rexit
    push rdx            ;save because cdq will overwrite rdx to null
    mov eax, dword[rdi] ;move rdi to eax for quotient
    cdq
    mov r9w, 2          ;modulus 2
    idiv r9w 
    cmp edx, 0          ;reminder in edx and check if it's evens 
    pop rdx
    je even             ;if even, jump to even
    jmp odd             ;else jump to odd
    

even:
	inc r15              ;increment size of n
    mov eax, dword[rdi]  ;dereferencing 4 bytes
    mov dword[rsi], eax
    add rsi, 4           ;moving to the next index for even array
    add rdi, 4           ;moving to the next index for source array
    jmp next

odd:
    mov eax, dword[rdi]
    mov dword[rdx], eax
    add rdx, 4          ;move to next index for odd array
    add rdi, 4          ;move to next index for source array
    jmp next

rexit: ;epilogue
	mov rax, r15        ;move value n to rax for return
    pop rbp
    ret
