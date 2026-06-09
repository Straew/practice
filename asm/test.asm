.global _start
.intel_syntax noprefix

_start:
    
    mov rax, 1 #write
    mov rdi, 1 #write intruction
    lea rsi, [hello_world] 
    mov rdx, 14 #string limit
    syscall #system call

    mov rax, 60 #exit safely
    mov rdi, 69 #executes but doesnt print 
    syscall

hello_world:
    .asciz "Hello World\n"
