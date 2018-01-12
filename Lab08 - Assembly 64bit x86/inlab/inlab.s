	.text
	.intel_syntax noprefix
	.file	"inlab.cpp"
	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp0:
	.cfi_def_cfa_offset 16
	movabs	rdi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	movabs	rdi, _ZNSt8ios_base4InitD1Ev
	movabs	rsi, _ZStL8__ioinit
	movabs	rdx, __dso_handle
	call	__cxa_atexit
	mov	dword ptr [rsp + 4], eax # 4-byte Spill
	pop	rax
	ret
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc

	.text
	.globl	_Z6array1Pi
	.align	16, 0x90
	.type	_Z6array1Pi,@function
_Z6array1Pi:                            # @_Z6array1Pi
	.cfi_startproc
# BB#0:
	mov	qword ptr [rsp - 8], rdi
	mov	rdi, qword ptr [rsp - 8]
	mov	eax, dword ptr [rdi + 8]
	mov	dword ptr [rsp - 12], eax
	mov	rdi, qword ptr [rsp - 8]
	mov	eax, dword ptr [rdi]
	mov	rdi, qword ptr [rsp - 8]
	add	eax, dword ptr [rdi + 4]
	ret
.Lfunc_end1:
	.size	_Z6array1Pi, .Lfunc_end1-_Z6array1Pi
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	sub	rsp, 40
.Ltmp1:
	.cfi_def_cfa_offset 48
	lea	rdi, [rsp + 16]
	mov	dword ptr [rsp + 36], 0
	mov	rax, qword ptr [.L_ZZ4mainE1a]
	mov	qword ptr [rsp + 16], rax
	mov	rax, qword ptr [.L_ZZ4mainE1a+8]
	mov	qword ptr [rsp + 24], rax
	call	_Z6array1Pi
	xor	ecx, ecx
	mov	dword ptr [rsp + 12], eax # 4-byte Spill
	mov	eax, ecx
	add	rsp, 40
	ret
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_inlab.cpp,@function
_GLOBAL__sub_I_inlab.cpp:               # @_GLOBAL__sub_I_inlab.cpp
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp2:
	.cfi_def_cfa_offset 16
	call	__cxx_global_var_init
	pop	rax
	ret
.Lfunc_end3:
	.size	_GLOBAL__sub_I_inlab.cpp, .Lfunc_end3-_GLOBAL__sub_I_inlab.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L_ZZ4mainE1a,@object   # @_ZZ4mainE1a
	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.L_ZZ4mainE1a:
	.long	2                       # 0x2
	.long	4                       # 0x4
	.long	5                       # 0x5
	.long	6                       # 0x6
	.size	.L_ZZ4mainE1a, 16

	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_inlab.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
