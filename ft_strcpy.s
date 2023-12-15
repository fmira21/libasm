section	.text
	global	_ft_strcpy

_ft_strcpy:                                     ; rdi = s1, rsi = s2
        xor rcx, rcx                            ; counter = 0
        xor r8, r8                              ; buffer register = 0
copy:
        mov r8b, byte[rsi + rcx]                ; move the current byte of the source string (initial pointer + counter) to the buffer
        mov byte[rdi + rcx], r8b                ; move the current byte of the source string from the buffer to the byte with the same index (initial pointer + counter) to the destination string
        cmp r8b, 0                              ; compare the current byte with zero (null terminator)
        je exit                                 ; if equal - exit
        inc rcx                                 ; counter++
        jmp copy                                ; again
exit:
    mov rax, rdi                                ; mov the ready destination string to the rax
    ret