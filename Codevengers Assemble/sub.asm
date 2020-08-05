			global	main
			extern	atoi
			extern	printf
			extern	puts

			section	.text
main:
			cmp	rdi, 3
			jne	incorrectArgumentCount


			mov	r12, [rsi +0x8]   ; setting first commandline arg to be r12
			mov	r13, [rsi +0x10]  ; setting second commandline arg to be r12


			push	r12			  ; The necessity of these will depend on implementation;
			push	r13			  ; this is mainly a reminder to preserve any callee-save
			push	r14		      ; registers that you might use.

convertArguments:

			mov	rdi, r12          ; atoi(string_to_convert) <--- r12
			call	atoi		  ; Result will be in rax (calling convention!).
			mov r12, rax		  ; move result into r12

			mov rdi, r13		  ; atoi (string_to_convert) <--- r13
			call atoi
			mov r13, rax          ; move result into r13

subtractArguments:
			mov rax, r12          ; move first argument into rax
			sub rax, r13		  ; subtract r12 r13
			mov r14, rax		  ; move result into r14

printResult:
			mov	rdi, format		  ; printf(resultFormat, number, ...) <--- args in rdi then rsi
			mov	rsi, r12		  ; first %d arg
			mov rdx, r13		  ; second %d arg	
			mov rcx, r14		  ; third %d arg	
			xor	rax, rax		  ; printf is special: needs rax to be 0.
			call	printf

finished:
			pop	r14
			pop	r13
			pop	r12
			ret

incorrectArgumentCount:
			mov	rdi, incorrectArgumentCountMessage
			call	puts
			ret

			section	.data
incorrectArgumentCountMessage:
			db	"Two arguments are needed in order to perform subtraction.", 0
format:			db	"%d - %d = %d", 10, 0
