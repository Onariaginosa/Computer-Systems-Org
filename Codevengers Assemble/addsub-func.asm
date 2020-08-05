			global	main
			extern	atoi
			extern	strlen
			extern	strncmp
			extern	printf
			extern	puts
			global add
			global subtract

			section	.text
add:
			mov rax, rdi          ; move first argument into rax
			add rax, rsi		  ; rdi + rsi
			ret

subtract:
			mov rax, rdi          ; move first argument into rax
			sub rax, rsi		  ; rdi - rsi
			ret

			; Just like with any other programming language,
			; feel free to define additional helper functions
			; if needed.

main:
			cmp	rdi, 4
			jne	incorrectArgumentCount

			mov	r12, [rsi +0x8]   			; setting first commandline arg to be r12
			mov	r13, [rsi +0x10] 			; setting second commandline arg to be r12
			mov r14, [rsi +0x10 +0x8]		; setting third commandline arg to be r12




			push	r12			; The necessity of these will depend on implementation;
			push	r13			; this is mainly a reminder to preserve any callee-save
			push	r14			; registers that you might use.
			push    r15
convertArguments:

			mov	rdi, r12          ; atoi(string_to_convert) <--- r12
			call	atoi		  ; Result will be in rax (calling convention!).
			mov r12, rax		  ; move result into r12

			mov rdi, r14		  ; atoi (string_to_convert) <--- r13
			call atoi
			mov r14, rax          ; move result into r13

checkOperatorLength:
			mov rdi, r13	      ; checking the length of r13
			call strlen
			cmp rax, 1			  ; compare length of r13 to 1
			jne	incorrectOperator; if length of r13 is not 1, jump to incorrectOperator

checkOperators:
			mov rdi, r13   		  ; set rdi to r13
			mov rsi, plusOperator ; set rsi to plusOperator
			mov rdx, 1			  ; length of comparison is 1
			call strncmp		  ; compare r13 and plus operator
			cmp rax, 0
			je callAdd		  ; if equal jump to addNumbers

			mov rdi, r13   		  ; set rdi to r13
			mov rsi, minusOperator ; set rsi to minusOperator
			mov rdx, 1			  ; length of comparison is 1
			call strncmp		  ; compare r13 and minus operator
			cmp rax, 0
			je callSubtract	  ; if equal jump to subtractNumbers

			jmp incorrectOperator  ; if equal to neither jump to incorrectOperator 
callAdd:
			mov rdi, r12
			mov rsi, r14
			call add
			mov r15, rax
			jmp printResult

callSubtract:
			mov rdi, r12
			mov rsi, r14
			call subtract
			mov r15, rax
			jmp printResult

printResult:
			mov	rdi, resultFormat ; printf(resultFormat, number, ...) <--- args in rdi then rsi
			mov	rsi, r12		  ; first %d arg
			mov rdx, r13		  ; %s arg	
			mov rcx, r14		  ; second %d arg	
			mov r8,  r15		  ; third %d arg
			xor	rax, rax		  ; printf is special: needs rax to be 0.
			call	printf

finished:
			pop r15
			pop	r14
			pop	r13
			pop	r12
			ret
			
incorrectArgumentCount:
			mov	rdi, incorrectArgumentCountMessage
			call	puts
			ret

incorrectOperator:
			mov	rdi, incorrectOperatorMessage
			call	puts
			jmp	finished

			section	.data
plusOperator:		db	"+", 0
minusOperator:		db	"-", 0
resultFormat:		db	"%d %s %d = %d", 10, 0

incorrectArgumentCountMessage:
			db	"To use this program, either enter <number> + <number> or <number> - <number>.", 0

incorrectOperatorMessage:
			db	"This program only recognizes + or -.", 0
