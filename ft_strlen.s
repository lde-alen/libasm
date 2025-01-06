;Seg type
segment .text

;Entry point
global _ft_strlen

;Includes

;Code
_ft_strlen:
    xor rax, rax; set return value to 0
    xor rcx, rcx ;set counter to 0

while:
	cmp BYTE[rdi + rcx], 0 ; cmp with value 0 meaning searching for null
	je break ; jumps to break
	inc rcx
	jmp while ; end while and jump to whatever is speficied 

break:
	mov rax, rcx ; copy rcx to rax
	ret ; return (auto return rax)
