global add_array_asm

section .text

;prologue
add_array_asm:
push rbp
mov rbp, rsp
push rcx
xor rax, rax ; init rax to zero
cmp rdi, 0
je rexit
cmp rsi, 0
je rexit

mov rcx, rsi
sub rcx, 1  

myloop:
add eax, dword [rdi] ; p is a pointer, *p (dereferencing pointer)
add rdi, 4
sub rcx, 1
cmp rcx, 0
jge myloop


rexit: ;epilogue
pop rcx
pop rbp
ret