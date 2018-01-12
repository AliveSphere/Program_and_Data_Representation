	.text
	.intel_syntax noprefix
	.file	"inlab.cpp"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp0:
	.cfi_def_cfa_offset 16
	lea	rsi, [rsp + 4]
	mov	edi, _ZSt3cin
	call	_ZNSirsERi
	mov	eax, dword ptr [rsp + 4]
	cmp	eax, 2
	jl	.LBB0_6
	.align	16, 0x90
.LBB0_1:                                # %.lr.ph
                                        # =>This Inner Loop Header: Depth=1
	test	al, 1
	jne	.LBB0_2
# BB#3:                                 #   in Loop: Header=BB0_1 Depth=1
	mov	ecx, eax
	shr	ecx, 31
	add	ecx, eax
	sar	ecx
	mov	eax, ecx
	jmp	.LBB0_4
	.align	16, 0x90
.LBB0_2:                                #   in Loop: Header=BB0_1 Depth=1
	lea	eax, [rax + 2*rax + 1]
.LBB0_4:                                # %.backedge
                                        #   in Loop: Header=BB0_1 Depth=1
	cmp	eax, 1
	jg	.LBB0_1
# BB#5:                                 # %._crit_edge.loopexit
	mov	dword ptr [rsp + 4], eax
.LBB0_6:                                # %._crit_edge
	xor	eax, eax
	pop	rcx
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_inlab.cpp,@function
_GLOBAL__sub_I_inlab.cpp:               # @_GLOBAL__sub_I_inlab.cpp
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp1:
	.cfi_def_cfa_offset 16
	mov	edi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	edi, _ZNSt8ios_base4InitD1Ev
	mov	esi, _ZStL8__ioinit
	mov	edx, __dso_handle
	pop	rax
	jmp	__cxa_atexit            # TAILCALL
.Lfunc_end1:
	.size	_GLOBAL__sub_I_inlab.cpp, .Lfunc_end1-_GLOBAL__sub_I_inlab.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_inlab.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
