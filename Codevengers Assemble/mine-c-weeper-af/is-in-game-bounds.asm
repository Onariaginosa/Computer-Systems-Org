			global	is_in_game_bounds

			section	.text
is_in_game_bounds:
			; rdi is the is_in_game
			; esi is the int x
			; edx is the int y

			cmp esi, 0 			; if esi is less than 0 jump to false
			jl false			

			cmp edx, 0			; if edx is less than 0 jump to false
			jl false

			mov rax, rdi		; move rdi to rax
        	mov eax, [rax]		; move first address in rax(aka width) to eax

			cmp eax, esi		; compare width and x
			jle false			; if width is less than or equal to x jump to false

			mov rax, rdi			; move rdi to rax
        	mov eax, [rax + 0x4]    ; move second address in rax(aka height) to eax

			cmp eax, edx        ; compare height and y
			jle false			; if height is less than of equal to y jump to false

			jmp true 			; return true if you made it this far

true:
			mov	rax, 1			; return true
			ret

false:
			xor	rax, rax		; return false
			ret
