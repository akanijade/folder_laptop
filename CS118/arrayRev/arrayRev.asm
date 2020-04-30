global rev_array_asm

section .text

;prologue

rev_array_asm:
	push rbp
	mov rbp, rsp
	push r11
	cmp rdx, 0                 ;comparing if size = 0
	je rexit                   ;jump to exit
	;cmp rdi, 0
	;je rexit 
    mov r11, rdx				;keep track size
	sub rdx, 1                 ;subtract one from size to get length	
    imul rdx, 4					;multiply size * 4
	add rdi, rdx				;get last address
    
next:
    mov eax, dword [rdi]              ;swap
	mov dword [rsi], eax
	sub rdi, 4						
	add rsi, 4
	sub r11, 1
	cmp r11, 0
	jne next

rexit: ;epilogue
	pop r11
	pop rbp
	ret