section .text
    global _ft_strcmp
_ft_strcmp:                 ;rsi = s1, rdi = s2
    xor rax, rax            ;rax = 0
    xor rcx, rcx            ;rcx = 0
compare:
    mov al, [rdi]       ;Move the current byte of the s1 to the top of the RAX register (lower AX, 4 bytes from the very beginning)
    mov cl, [rsi]       ;Move the current byte of the s2 to the top of the RСX register (lower СX, 4 bytes from the very beginning)
    cmp ax, 0
    je substract
    cmp al, cl
    jne substract
    inc rdi
    inc rsi
    jmp compare
substract:
    sub rax, rcx      ; substract the value of the second string byte from rax content
    ret                 ; return the rax content

