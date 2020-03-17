global rev_array_asm

section .text

;prologue
mov r11, 0
rev_array_asm:
    cmp rdx, 0                 ;comparing if size = 0
    je rexit                   ;jump to exit 
    add rdx, 1                 ;subtract one from size to get length
    add rdi, rdx               ;get the last address
    
next:
    mov rsi, [rdi]              ;mov first param
    add r11, 1
    mov rsi, r11
    sub rdx, 1
    jb next                     ;keep going

rexit: ;epilogue
ret