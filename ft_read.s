;Seg type
segment .text

;Entry point
global _ft_read

;Includes
extern ___error

;Code
_ft_read:
    mov rax, 0x2000003
    xor rcx, rcx

    syscall
    jc error
    ret

error:
    mov r8, rax
    call ___error
    mov [rax], r8
    mov rax, -1
    ret