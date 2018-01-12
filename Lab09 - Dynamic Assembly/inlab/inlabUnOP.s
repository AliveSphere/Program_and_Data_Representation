	.text
	.intel_syntax noprefix
	.file	"inlab.cpp"
	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp2:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	movabs	rdi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	movabs	rdi, _ZNSt8ios_base4InitD1Ev
	movabs	rsi, _ZStL8__ioinit
	movabs	rdx, __dso_handle
	call	__cxa_atexit
	mov	dword ptr [rbp - 4], eax # 4-byte Spill
	add	rsp, 16
	pop	rbp
	ret
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc

	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp5:
	.cfi_def_cfa_register rbp
	sub	rsp, 32
	movabs	rdi, _ZSt3cin
	lea	rsi, [rbp - 8]
	mov	dword ptr [rbp - 4], 0
	mov	dword ptr [rbp - 12], 0
	call	_ZNSirsERi
	mov	qword ptr [rbp - 24], rax # 8-byte Spill
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 8], 1
	jle	.LBB1_6
# BB#2:                                 #   in Loop: Header=BB1_1 Depth=1
	mov	eax, 2
	mov	ecx, dword ptr [rbp - 8]
	mov	dword ptr [rbp - 28], eax # 4-byte Spill
	mov	eax, ecx
	cdq
	mov	ecx, dword ptr [rbp - 28] # 4-byte Reload
	idiv	ecx
	cmp	edx, 0
	je	.LBB1_4
# BB#3:                                 #   in Loop: Header=BB1_1 Depth=1
	mov	eax, dword ptr [rbp - 12]
	add	eax, 1
	mov	dword ptr [rbp - 12], eax
	imul	eax, dword ptr [rbp - 8], 3
	add	eax, 1
	mov	dword ptr [rbp - 8], eax
	jmp	.LBB1_5
.LBB1_4:                                #   in Loop: Header=BB1_1 Depth=1
	mov	eax, 2
	mov	ecx, dword ptr [rbp - 12]
	add	ecx, 1
	mov	dword ptr [rbp - 12], ecx
	mov	ecx, dword ptr [rbp - 8]
	mov	dword ptr [rbp - 32], eax # 4-byte Spill
	mov	eax, ecx
	cdq
	mov	ecx, dword ptr [rbp - 32] # 4-byte Reload
	idiv	ecx
	mov	dword ptr [rbp - 8], eax
.LBB1_5:                                #   in Loop: Header=BB1_1 Depth=1
	jmp	.LBB1_1
.LBB1_6:
	xor	eax, eax
	add	rsp, 32
	pop	rbp
	ret
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_inlab.cpp,@function
_GLOBAL__sub_I_inlab.cpp:               # @_GLOBAL__sub_I_inlab.cpp
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp6:
	.cfi_def_cfa_offset 16
.Ltmp7:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp8:
	.cfi_def_cfa_register rbp
	call	__cxx_global_var_init
	pop	rbp
	ret
.Lfunc_end2:
	.size	_GLOBAL__sub_I_inlab.cpp, .Lfunc_end2-_GLOBAL__sub_I_inlab.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_inlab.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
