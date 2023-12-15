section .text                       ;rdi = file descriptor, rsi = buffer, rdx = byte count
        global _ft_read
        extern ___error
_ft_read:
    mov rax, 0x2000003               ;Read system call, addressing to the rax
    syscall                         ;Execute system call from rax
    jc error
    ret
error:
    push rax
    call ___error                   ;Get errno address: !NB! Mac - extern __error. Linux - extern __errno_location + ... WRT ..plt - linux routine for external calls
    pop qword[rax]
    mov rax, -1
    ret                             ;Return rax