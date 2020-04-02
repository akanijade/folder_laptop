global evens_and_odds


section .text

;prologue
evens_and_odds:
    push rbp
	mov rbp, rsp
	mov r15, 0
    cmp rcx, 0 ;size
    je rexit


next:
    sub rcx, 1 ;decrease size by 1 byte
    cmp rcx, -1
    je rexit
    push rdx
    mov eax, dword[rdi] ;move rdi to eax for quotient
    cdq
    mov r9w, 2 ;modulus 2
    idiv r9w 
    cmp edx, 0 ;reminder in edx
    pop rdx
    je even
    jmp odd
    

even:
	inc r15
    mov eax, dword[rdi]
    mov dword[rsi], eax
    add rsi, 4
    add rdi, 4
    jmp next

odd:
    mov eax, dword[rdi]
    mov dword[rdx], eax
    add rdx, 4
    add rdi, 4
    jmp next

rexit: ;epilogue
	mov rax, r15
    pop rbp
    ret
