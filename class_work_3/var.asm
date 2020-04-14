global variance

section .text

;rdi = source array address
;rsi = temporary array address
;rdx = size of source array
;prologue

variance:
    push rbp
    mov rbp, rsp
    mov r15, rdx            ;keep size of array
    mov r14, rdx
    mov r8d, 0              ;keep the sum of all (x - mean) 
    ;mov r8d, dword[rdi]    ;keep size of array
    mov r9d, 0
    mov r8d, 0
    mov eax, 0
    cmp rdx, 0
    je rexit
    push rdi

next:
    add r9d, dword[rdi]     ;sum up elements in rdi
    add rdi, 4              ;move to the next address in rdi
    sub r15, 1              ;decrease size by 1 byte
    cmp r15, 0              ;loop condition
    jne next  
    pop rdi

avg:
    push rdx
    mov eax, r9d
    mov ebx, edx
    cdq        
    idiv ebx                ;divide by size
    pop rdx
    push r14

mult:
    mov ecx, dword[rdi]     ;mov value from rdi to rsi
    sub ecx, eax            ;subtract each element in rdi with average
    imul ecx, ecx           ;square each element 
    mov dword[rsi], ecx     ;move value to tmp array
    add rsi, 4              ;move to the next index
    add rdi, 4              ;move to the next index
    sub r14, 1
    cmp r14, 0
    jne mult
    pop r14
sum: 
    add r8d, dword[rsi]
    add rsi, 4
    sub r14, 1
    cmp r14, 0
    jne sum

;divide:
;    push rdx
;    mov eax, dword[r8d]
;    mov ebx, edx
;    cdq 
;    idiv ebx
;    pop rdx

  
 
rexit: 
    mov eax, r8d
    pop rbp
    ret
    