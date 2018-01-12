	.text
	.intel_syntax noprefix
	.file	"postlab.cpp"
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
	.globl	_ZN3carC2Ev
	.align	16, 0x90
	.type	_ZN3carC2Ev,@function
_ZN3carC2Ev:                            # @_ZN3carC2Ev
	.cfi_startproc
# BB#0:
	sub	rsp, 24
.Ltmp1:
	.cfi_def_cfa_offset 32
	mov	qword ptr [rsp + 16], rdi
	mov	rdi, qword ptr [rsp + 16]
	mov	rax, rdi
	add	rax, 8
	mov	qword ptr [rsp + 8], rdi # 8-byte Spill
	mov	rdi, rax
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	mov	rax, qword ptr [rsp + 8] # 8-byte Reload
	mov	dword ptr [rax], 4
	mov	dword ptr [rax + 4], 2400
	add	rsp, 24
	ret
.Lfunc_end1:
	.size	_ZN3carC2Ev, .Lfunc_end1-_ZN3carC2Ev
	.cfi_endproc

	.globl	_ZN3car3dirB5cxx11Ev
	.align	16, 0x90
	.type	_ZN3car3dirB5cxx11Ev,@function
_ZN3car3dirB5cxx11Ev:                   # @_ZN3car3dirB5cxx11Ev
	.cfi_startproc
# BB#0:
	sub	rsp, 40
.Ltmp2:
	.cfi_def_cfa_offset 48
	mov	rax, rdi
	movabs	rcx, .L.str
	mov	qword ptr [rsp + 32], rsi
	mov	rsi, qword ptr [rsp + 32]
	mov	rdx, rsi
	add	rdx, 8
	mov	qword ptr [rsp + 24], rdi # 8-byte Spill
	mov	rdi, rdx
	mov	qword ptr [rsp + 16], rsi # 8-byte Spill
	mov	rsi, rcx
	mov	qword ptr [rsp + 8], rax # 8-byte Spill
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEPKc
	mov	rcx, qword ptr [rsp + 16] # 8-byte Reload
	add	rcx, 8
	mov	rdi, qword ptr [rsp + 24] # 8-byte Reload
	mov	rsi, rcx
	mov	qword ptr [rsp], rax    # 8-byte Spill
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_
	mov	rax, qword ptr [rsp + 8] # 8-byte Reload
	add	rsp, 40
	ret
.Lfunc_end2:
	.size	_ZN3car3dirB5cxx11Ev, .Lfunc_end2-_ZN3car3dirB5cxx11Ev
	.cfi_endproc

	.globl	_ZN3car6driverEv
	.align	16, 0x90
	.type	_ZN3car6driverEv,@function
_ZN3car6driverEv:                       # @_ZN3car6driverEv
	.cfi_startproc
# BB#0:
	mov	al, 1
	mov	qword ptr [rsp - 8], rdi
	and	al, 1
	movzx	eax, al
	ret
.Lfunc_end3:
	.size	_ZN3car6driverEv, .Lfunc_end3-_ZN3car6driverEv
	.cfi_endproc

	.globl	_ZN3car7crashesENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.align	16, 0x90
	.type	_ZN3car7crashesENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,@function
_ZN3car7crashesENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE: # @_ZN3car7crashesENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 3, __gxx_personality_v0
	.cfi_lsda 3, .Lexception0
# BB#0:
	sub	rsp, 88
.Ltmp9:
	.cfi_def_cfa_offset 96
	mov	qword ptr [rsp + 80], rdi
	lea	rdi, [rsp + 48]
	mov	qword ptr [rsp + 24], rdi # 8-byte Spill
	mov	qword ptr [rsp + 16], rsi # 8-byte Spill
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
.Ltmp3:
	mov	rdi, qword ptr [rsp + 24] # 8-byte Reload
	mov	rsi, qword ptr [rsp + 16] # 8-byte Reload
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_
.Ltmp4:
	mov	qword ptr [rsp + 8], rax # 8-byte Spill
	jmp	.LBB4_1
.LBB4_1:
	lea	rdi, [rsp + 48]
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	add	rsp, 88
	ret
.LBB4_2:
.Ltmp5:
	mov	ecx, edx
	mov	qword ptr [rsp + 40], rax
	mov	dword ptr [rsp + 36], ecx
.Ltmp6:
	lea	rdi, [rsp + 48]
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.Ltmp7:
	jmp	.LBB4_3
.LBB4_3:
	jmp	.LBB4_4
.LBB4_4:
	mov	rdi, qword ptr [rsp + 40]
	call	_Unwind_Resume
.LBB4_5:
.Ltmp8:
	mov	ecx, edx
	mov	rdi, rax
	mov	dword ptr [rsp + 4], ecx # 4-byte Spill
	call	__clang_call_terminate
.Lfunc_end4:
	.size	_ZN3car7crashesENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .Lfunc_end4-_ZN3car7crashesENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.align	4
GCC_except_table4:
.Lexception0:
	.byte	255                     # @LPStart Encoding = omit
	.byte	3                       # @TType Encoding = udata4
	.byte	73                      # @TType base offset
	.byte	3                       # Call site Encoding = udata4
	.byte	65                      # Call site table length
	.long	.Lfunc_begin0-.Lfunc_begin0 # >> Call Site 1 <<
	.long	.Ltmp3-.Lfunc_begin0    #   Call between .Lfunc_begin0 and .Ltmp3
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.long	.Ltmp3-.Lfunc_begin0    # >> Call Site 2 <<
	.long	.Ltmp4-.Ltmp3           #   Call between .Ltmp3 and .Ltmp4
	.long	.Ltmp5-.Lfunc_begin0    #     jumps to .Ltmp5
	.byte	0                       #   On action: cleanup
	.long	.Ltmp4-.Lfunc_begin0    # >> Call Site 3 <<
	.long	.Ltmp6-.Ltmp4           #   Call between .Ltmp4 and .Ltmp6
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.long	.Ltmp6-.Lfunc_begin0    # >> Call Site 4 <<
	.long	.Ltmp7-.Ltmp6           #   Call between .Ltmp6 and .Ltmp7
	.long	.Ltmp8-.Lfunc_begin0    #     jumps to .Ltmp8
	.byte	1                       #   On action: 1
	.long	.Ltmp7-.Lfunc_begin0    # >> Call Site 5 <<
	.long	.Lfunc_end4-.Ltmp7      #   Call between .Ltmp7 and .Lfunc_end4
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.byte	1                       # >> Action Record 1 <<
                                        #   Catch TypeInfo 1
	.byte	0                       #   No further actions
                                        # >> Catch TypeInfos <<
	.long	0                       # TypeInfo 1
	.align	4

	.section	.text.__clang_call_terminate,"axG",@progbits,__clang_call_terminate,comdat
	.hidden	__clang_call_terminate
	.weak	__clang_call_terminate
	.align	16, 0x90
	.type	__clang_call_terminate,@function
__clang_call_terminate:                 # @__clang_call_terminate
# BB#0:
	push	rax
	call	__cxa_begin_catch
	mov	qword ptr [rsp], rax    # 8-byte Spill
	call	_ZSt9terminatev
.Lfunc_end5:
	.size	__clang_call_terminate, .Lfunc_end5-__clang_call_terminate

	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 3, __gxx_personality_v0
	.cfi_lsda 3, .Lexception1
# BB#0:
	sub	rsp, 152
.Ltmp30:
	.cfi_def_cfa_offset 160
	lea	rdi, [rsp + 112]
	call	_ZN3carC1Ev
	lea	rdi, [rsp + 72]
	mov	qword ptr [rsp + 16], rdi # 8-byte Spill
	call	_ZNSaIcEC1Ev
.Ltmp10:
	mov	eax, .L.str.1
	mov	esi, eax
	lea	rdi, [rsp + 80]
	mov	rdx, qword ptr [rsp + 16] # 8-byte Reload
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
.Ltmp11:
	jmp	.LBB6_1
.LBB6_1:
.Ltmp12:
	lea	rdi, [rsp + 112]
	lea	rsi, [rsp + 80]
	call	_ZN3car7crashesENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.Ltmp13:
	jmp	.LBB6_2
.LBB6_2:
.Ltmp17:
	lea	rdi, [rsp + 80]
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.Ltmp18:
	jmp	.LBB6_3
.LBB6_3:
	lea	rdi, [rsp + 72]
	call	_ZNSaIcED1Ev
.Ltmp20:
	lea	rdi, [rsp + 112]
	call	_ZN3car6driverEv
.Ltmp21:
	mov	byte ptr [rsp + 15], al # 1-byte Spill
	jmp	.LBB6_4
.LBB6_4:
.Ltmp22:
	lea	rdi, [rsp + 24]
	lea	rsi, [rsp + 112]
	call	_ZN3car3dirB5cxx11Ev
.Ltmp23:
	jmp	.LBB6_5
.LBB6_5:
.Ltmp24:
	lea	rdi, [rsp + 24]
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.Ltmp25:
	jmp	.LBB6_6
.LBB6_6:
	lea	rdi, [rsp + 112]
	call	_ZN3carD2Ev
	xor	eax, eax
	add	rsp, 152
	ret
.LBB6_7:
.Ltmp19:
	mov	ecx, edx
	mov	qword ptr [rsp + 64], rax
	mov	dword ptr [rsp + 60], ecx
	jmp	.LBB6_10
.LBB6_8:
.Ltmp14:
	mov	ecx, edx
	mov	qword ptr [rsp + 64], rax
	mov	dword ptr [rsp + 60], ecx
.Ltmp15:
	lea	rdi, [rsp + 80]
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.Ltmp16:
	jmp	.LBB6_9
.LBB6_9:
	jmp	.LBB6_10
.LBB6_10:
	lea	rdi, [rsp + 72]
	call	_ZNSaIcED1Ev
	jmp	.LBB6_12
.LBB6_11:
.Ltmp26:
	mov	ecx, edx
	mov	qword ptr [rsp + 64], rax
	mov	dword ptr [rsp + 60], ecx
.LBB6_12:
.Ltmp27:
	lea	rdi, [rsp + 112]
	call	_ZN3carD2Ev
.Ltmp28:
	jmp	.LBB6_13
.LBB6_13:
	jmp	.LBB6_14
.LBB6_14:
	mov	rdi, qword ptr [rsp + 64]
	call	_Unwind_Resume
.LBB6_15:
.Ltmp29:
	mov	ecx, edx
	mov	rdi, rax
	mov	dword ptr [rsp + 8], ecx # 4-byte Spill
	call	__clang_call_terminate
.Lfunc_end6:
	.size	main, .Lfunc_end6-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.align	4
GCC_except_table6:
.Lexception1:
	.byte	255                     # @LPStart Encoding = omit
	.byte	3                       # @TType Encoding = udata4
	.asciz	"\360"                  # @TType base offset
	.byte	3                       # Call site Encoding = udata4
	.byte	104                     # Call site table length
	.long	.Lfunc_begin1-.Lfunc_begin1 # >> Call Site 1 <<
	.long	.Ltmp10-.Lfunc_begin1   #   Call between .Lfunc_begin1 and .Ltmp10
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.long	.Ltmp10-.Lfunc_begin1   # >> Call Site 2 <<
	.long	.Ltmp11-.Ltmp10         #   Call between .Ltmp10 and .Ltmp11
	.long	.Ltmp19-.Lfunc_begin1   #     jumps to .Ltmp19
	.byte	0                       #   On action: cleanup
	.long	.Ltmp12-.Lfunc_begin1   # >> Call Site 3 <<
	.long	.Ltmp13-.Ltmp12         #   Call between .Ltmp12 and .Ltmp13
	.long	.Ltmp14-.Lfunc_begin1   #     jumps to .Ltmp14
	.byte	0                       #   On action: cleanup
	.long	.Ltmp17-.Lfunc_begin1   # >> Call Site 4 <<
	.long	.Ltmp18-.Ltmp17         #   Call between .Ltmp17 and .Ltmp18
	.long	.Ltmp19-.Lfunc_begin1   #     jumps to .Ltmp19
	.byte	0                       #   On action: cleanup
	.long	.Ltmp20-.Lfunc_begin1   # >> Call Site 5 <<
	.long	.Ltmp25-.Ltmp20         #   Call between .Ltmp20 and .Ltmp25
	.long	.Ltmp26-.Lfunc_begin1   #     jumps to .Ltmp26
	.byte	0                       #   On action: cleanup
	.long	.Ltmp25-.Lfunc_begin1   # >> Call Site 6 <<
	.long	.Ltmp15-.Ltmp25         #   Call between .Ltmp25 and .Ltmp15
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.long	.Ltmp15-.Lfunc_begin1   # >> Call Site 7 <<
	.long	.Ltmp28-.Ltmp15         #   Call between .Ltmp15 and .Ltmp28
	.long	.Ltmp29-.Lfunc_begin1   #     jumps to .Ltmp29
	.byte	1                       #   On action: 1
	.long	.Ltmp28-.Lfunc_begin1   # >> Call Site 8 <<
	.long	.Lfunc_end6-.Ltmp28     #   Call between .Ltmp28 and .Lfunc_end6
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.byte	1                       # >> Action Record 1 <<
                                        #   Catch TypeInfo 1
	.byte	0                       #   No further actions
                                        # >> Catch TypeInfos <<
	.long	0                       # TypeInfo 1
	.align	4

	.section	.text._ZN3carD2Ev,"axG",@progbits,_ZN3carD2Ev,comdat
	.weak	_ZN3carD2Ev
	.align	16, 0x90
	.type	_ZN3carD2Ev,@function
_ZN3carD2Ev:                            # @_ZN3carD2Ev
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp31:
	.cfi_def_cfa_offset 16
	mov	qword ptr [rsp], rdi
	mov	rdi, qword ptr [rsp]
	add	rdi, 8
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	pop	rax
	ret
.Lfunc_end7:
	.size	_ZN3carD2Ev, .Lfunc_end7-_ZN3carD2Ev
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_postlab.cpp,@function
_GLOBAL__sub_I_postlab.cpp:             # @_GLOBAL__sub_I_postlab.cpp
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp32:
	.cfi_def_cfa_offset 16
	call	__cxx_global_var_init
	pop	rax
	ret
.Lfunc_end8:
	.size	_GLOBAL__sub_I_postlab.cpp, .Lfunc_end8-_GLOBAL__sub_I_postlab.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"EAST"
	.size	.L.str, 5

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Four crashes"
	.size	.L.str.1, 13

	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_postlab.cpp

	.globl	_ZN3carC1Ev
	.type	_ZN3carC1Ev,@function
_ZN3carC1Ev = _ZN3carC2Ev
	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
