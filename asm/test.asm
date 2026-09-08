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


mhve5srnsatf5sj
kgfbm0nmkcw9ka1
sl.u.AGsDj6Lwbzm6YHy56Eq0omiSyj0885g4KSon7BdBfam7Jwns69OFlvHroGyJUtC2VrJedw3hffbsCRDV2laZL72YgrsLH
