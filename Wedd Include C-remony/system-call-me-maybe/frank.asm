;-----------------------------------------------------------------------------------------------------------;
; Creates a new folder only using System calls.                                                             ;
; Runs on 64-bit Linux only.                                                                                ;
; Prints whether you have successfully created a folder or if you have incorrect arguments                  ;
;-----------------------------------------------------------------------------------------------------------;

global main



section .text

main: 
        cmp     rdi, 2                  ; must have 1 argument
        jne     inputError              ; jump to inputError block if argument amount != 1

        mov     r12, [rsi +0x8]         ; move first argument value to r12


        mov     rax, 83                 ; sys_mkdir system call
        mov     rdi, r12                ; making the pathname for new folder user input
        mov     rsi, 777                ; setting the mode to standard (700 = restrictef to user owner)
        syscall

        jmp     printSuccess            ; jump to printSuccess block

inputError:                             ; print the inputErrorInfo Statement to the command line 
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, inputErrorInfo     ; setting rsi to the msg
        mov     rdx, 57                 ; message size is 57 bytes
        syscall
        jmp     endProgram              ; jump to endProgram block

printSuccess:                           ; print the createdFolderMsg statement to command line
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, createdFolderMsg   ; setting rsi to the msg
        mov     rdx, 32                 ; message size is 32 bytes
        syscall
        jmp     endProgram              ; jump to end program block

inputErrorInfo:
        db "Function requires exactly 1 argument: <new folder name>", 10

createdFolderMsg:
        db "Successfully created new Folder", 10

endProgram:
        mov     rax, 60
        xor     rdi, rdi
        syscall


