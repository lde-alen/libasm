;Seg type
segment .text

;Entry point
global _ft_strdup

;Includes
extern _malloc
extern _ft_strcpy
extern _ft_strlen

;Code
_ft_strdup:
	call	_ft_strlen

	push	rdi
	inc		rax
	mov		rdi, rax
	call	_malloc
	pop		rsi
	mov		rdi, rax 
	call	_ft_strcpy
	ret
