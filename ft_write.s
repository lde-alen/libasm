;Seg type
segment .text

;Entry point
global _ft_write

;Includes
extern ___error

;Code
_ft_write:
    mov rax, 0x2000004 ; write syscall number 0x2000000 is the base then depends on waht you want to do PS: linux this is 1... lol
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