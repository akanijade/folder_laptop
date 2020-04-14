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
    mov r9d, 0              ;sum of source array
    mov r8d, 0              ;sum of tmp array
    mov eax, 0  
    cmp rdx, 0              ;exiting condition
    je rexit
    push rdi

next:
    add r9d, dword[rdi]     ;sum up elements in rdi to find average
    add rdi, 4              ;move to the next address in rdi
    sub r15, 1              ;decrease size by 1 byte
    cmp r15, 0              ;loop condition
    jne next  
    pop rdi

avg:
    push rdx                ;preserve the first address of the array
    mov eax, r9d            ;the sum of source array
    mov ebx, edx            ;the diviser (the size of the array = edx)
    cdq                     ;change rdx to 0 
    idiv ebx                ;divide by size
    pop rdx
    push r14
    push rsi
mult:
    mov ecx, dword[rdi]     ;mov value from rdi to rsi
    sub ecx, eax            ;subtract each element in rdi with average
    imul ecx, ecx           ;square each element 
    mov dword[rsi], ecx     ;move value to tmp array
    add rsi, 4              ;move to the next index
    add rdi, 4              ;move to the next index
    sub r14, 1
    cmp r14, 0              ;loop condition
    jne mult
    pop rsi
    pop r14   

sum: 
    add r8d, dword[rsi]     ;sum up the value in tmp array
    add rsi, 4              ;moving to the next index
    sub r14, 1              
    cmp r14, 0              ;loop condition
    jne sum

divide:
    mov eax, r8d            ;move the sum value into eax
    mov ebx, edx            ;the diviser (size of the array = edx)
    cdq                     ;make rdx 0
    idiv ebx                ;divide by the number of elements
    
rexit:
    mov rsp, rbp
    pop rbp
    ret
    