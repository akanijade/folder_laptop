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
    ;mov r8d, dword[rdx]            ;keep size of array
    mov r9d, 0
    mov r8d, 0
    mov eax, 0
    cmp rdx, 0
    je rexit
    
next:
    
    add r9d, dword[rdi]     ;sum up elements in rdi
    add rdi, 4              ;move to the next address in rdi
    sub r15, 1              ;decrease size by 1 byte
    cmp r15, 0              ;loop condition
    jne next  
    
avg:
    push rdx
    ;mov edx, 0
    mov eax, r9d
    mov ebx, edx
    cdq        
    idiv ebx                ;divide by size
    pop rdx

mult:
    mov ecx, dword[rdi]     ;mov value from rdi to rsi
    sub ecx, eax
    imul ecx, ecx
    mov dword[rsi], ecx
    add rsi, 4
    add rdi, 4
    sub r14, 1
    cmp r14, 0
    jne mult
  
 
rexit: 
    pop rbp
    ret
    