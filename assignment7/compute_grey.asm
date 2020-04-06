global compute_grey


section		.text

;rdi will contain a uint32_t* 


compute_grey:
	mov	ebx, 0			;serve as a accumulator
		
	mov	eax, dword [rdi] 	;get the unsigend integer
	and	eax, 0xff000000		;do an and operation	
	shr	eax, 24			;shift it so it's in the lower 8 bits
	add	ebx, eax		;add to the accumulator	
	
	mov	eax, dword [rdi]	;get the unsigned integer again
	and	eax, 0x00ff0000		;do an and operation
	shr	eax, 16			;shift it so it's in the lower 8 bits
	add	ebx, eax		;add to the accumulator

	mov	eax, dword [rdi]	;get the unsigned integer
	and	eax, 0x0000ff00		;do an and operation
	shr	eax, 8			;shift it so it's in the lower 8 bits
	add	ebx, eax		;added to the accumulator

;set up for division
	mov	eax, ebx		;put the dividend in eax because of convention
	mov	edx, 0			;zero out edx for reminder, if this is not done there'd be compilation error
	mov	ebx, 3			;put the divisor in any register of your choice, just choose ebx
	div	ebx			;divide eax/ebx where the quotient will be in eax and reminder in edx
	ret				;return 	
