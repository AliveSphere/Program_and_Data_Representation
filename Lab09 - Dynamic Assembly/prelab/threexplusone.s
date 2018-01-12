; Charles Buyas, cjb8qf, 4-10-17, threexplusone.s 
;
;
;
; Optimizations:
; - shifted the bits instead of doing division
; - changed imul and add to a lea command
;     imul	rdi, 3
;     add	rdi, 1
; - made a recurse subroutine that called even
; - reduced the number of lines of code used
; - used the 'test' function to see if it was odd
;
	
	global threexplusone
	section .text

threexplusone:
	xor	rax, rax
	xor	r10, r10
even:
	cmp	rdi, 1
	je	done
	test	rdi, 1
	jne	odd
	inc	rax
	shr	rdi, 1
	jmp	recurse
odd:
	inc	rax
	lea	rdi, [3*edi+1]
recurse:
	call	even
done:
	ret
