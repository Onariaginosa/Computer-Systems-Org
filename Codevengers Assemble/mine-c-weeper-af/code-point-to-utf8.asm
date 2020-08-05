			global	main
			extern	puts
			extern	sscanf
			extern	printf
			extern	emit_utf_8

			section	.text
main:
			cmp rdi, 1				; check for at least 1 argument
			jle argumentsError

			push 	rdi
			push    rsi
        	sub     rsp, 8                  ; must align stack before call
			jmp 	resetLoop

argumentLoop: 
			push rdi
			push rsi
			sub rsp, 8

			mov rdi, [rsi]					; set rdi to the code_point_string
			mov r13, rdi					; set r13 to the code_point_string
			mov rsi, codePointFormat		; set rsi to the codePointFormat
			mov rdx, codePoint				; set rdx to the codePoint
			call sscanf						; called sscanf(code_point_string, codePointFormat, codePoint)

			cmp rax, 1						; if the result does not equal 1
			jne printWrongFormat			; jump to printWrongFormat
			mov rdi, [codePoint]			; else move codePoint value to rdi
			call emit_utf_8					; call emit_utf_8(codePoint)

resetLoop:
			add     rsp, 8                  ; restore %rsp to pre-aligned value
        	pop     rsi                     ; restore registers puts used
       		pop     rdi

        	add     rsi, 8                  ; point to next argument
        	dec     rdi                     ; count down
        	jnz     argumentLoop            ; if not done counting keep going

			jmp finished


printWrongFormat:
			mov rsi, r13
			mov rdi, incorrectFormat		;print the incorrect
			
			xor	rax, rax		  ; printf is special: needs rax to be 0.
			call	printf
			jmp resetLoop

finished:
			mov rdi, emptyLine	 			; print an a new line
			xor	rax, rax					; printf is special: needs rax to be 0.
			call	printf
			ret

argumentsError:		; basic print argument Error
			mov	rdi, argumentsRequiredMessage 
			call	puts

			mov	rdi, argumentDescription
			call	puts

			xor	rax, rax
			inc	rax

			pop r12
			ret

			section	.data
			; The following definitions are here to get you started and to standardize
			; error messages but of course, feel free to define more as needed.
argumentsRequiredMessage:
			db	"This program requires one or more command line arguments,", 0
argumentDescription:	db	"one for each code point to encode as UTF-8.", 0
incorrectFormat:	db	"(%s incorrect format)", 0
codePointFormat:	db	"U+%6X", 0
emptyLine:          db  "", 10

			section	.bss
codePoint:		resb	8			; The code point from sscanf should go here.
