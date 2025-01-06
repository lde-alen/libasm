;Seg type
segment .text

;Entry point
global _ft_strcpy

;Includes

;Code
_ft_strcpy:
    xor rax, rax
    xor rcx, rcx

while:
    mov al, [rsi + rcx]
    mov [rdi + rcx], al
    inc rcx
    cmp al, 0
    jne while

mov rax, rdi
ret