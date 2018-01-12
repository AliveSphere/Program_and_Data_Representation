; Charles Buyas, cjb8qf, 3-27-16, mathlib.s
;
; In product: 
; rdi is the number being multiplied
; rsi is the number of times to add it
;
; In power:
;
; 

	global mathlibpro
	section .text

mathlibpro:	
	xor	rax, rax
	xor	r10, r10	
product:
	cmp	r10, rsi
	je	done
	add	rax, rdi
	inc	r10
	jmp	product

	global mathlibpow
	section .text
	

mathlibpow:	
	xor	rax, rax
	add	rax, 1
	xor	r11, r11
power:
	cmp	r11, rsi
	je	done
	push	rsi
	mov	rsi, rax
	call	mathlibpro
	pop	rsi
	dec	rsi
	call 	power
done:	
	ret
