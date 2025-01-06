;Seg type
segment .text

;Entry point
global _ft_strcmp

;Includes

;Code
_ft_strcmp:
    xor rax, rax
    xor rcx, rcx
    xor r8, r8

while:
    movzx rax, BYTE[rdi + rcx]
    movzx r8, BYTE[rsi + rcx]

    ;check null
    cmp rax, 0
    cmp r8, 0

    jz break

    cmp rax, r8
    jne break

    inc rcx
    jmp while

break:
    sub rax, r8
    ret