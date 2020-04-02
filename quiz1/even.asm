global evens_and_odds

section .text

;prologue
evens_and_odds:
    push rbp
	mov rbp, rsp
    cmp rcx, 0 ;size
    je rexit


next:
    sub rcx, 1 ;decrease size by 1 byte
    cmp rcx, -1
    je rexit
    mov eax, dword[rdi] ;move rdi to eax for quotient
    cdq
    mov r9w, 2 ;modulus 2
    push rdx
    idiv r9w 
    cmp edx, 0 ;reminder in edx
    pop rdx
    je even
    jmp odd
    

even:
    push rax
    mov eax, dword[rdi]
    mov dword[rsi], eax
    pop rax
    add rsi, 4
    add rdi, 4 
    jmp next

odd:
    push rax
    mov eax, dword[rdi]
    mov dword[rdx], eax
    pop rax
    add rdx, 4
    add rdi, 4
    jmp next

rexit: ;epilogue
    pop rbp
    ret