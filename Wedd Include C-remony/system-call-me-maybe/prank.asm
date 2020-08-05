;----------------------------------------------------------------------------------------------------------;
; Creates a new folder and file using system calls.                                                        ;
; Prank: you don't have access to the folder, and you can only read a joke in the file                     ;
; Runs on 64-bit Linux only.                                                                               ;
; Prints whether you have successfully created a folder and file or if you have incorrect arguments        ;
; ---------------------------------------------------------------------------------------------------------;

global main

section .text

main: 
        cmp     rdi, 3                  ; must have 2 argument
        jne     inputError              ; jump to inputError block if argument amount != 2

        mov     r12, [rsi +0x8]         ; move first argument value to r12
        mov     r13, [rsi +0x10]        ; move second argument value to r13

        mov     rax, 83                 ; sys_mkdir system call
        mov     rdi, r12                ; making the pathname for new folder user input
        mov     rsi, 000                ; setting the permissions to inaccessible
        syscall

        mov     rax, 2                  ; sys_open
        mov     rdi, r13                ; the file name is the 2nd argument
        mov     rsi, 66                 ; used the write flag(1) and the create flag(64) to open 
                                        ; file or create the file if it does not already exist and 
                                        ; write into it.
        mov     rdx, 0444               ; set permissions to read for owner group and other
        syscall

        push    rax                     
        mov     rdi, rax                ; file to write to is the one just opened
        mov     rax, 1                  ; sys_write
        mov     rsi, fileText           ; write the prank text to the new file
        mov     rdx, 55                 ; specifies the byte size of the message
        syscall

        mov     rax, 3                  ; sys_close close the opened file
        pop     rdi
        syscall
        
        jmp     printSuccess            ; jump to printSuccess block

inputError:                             ; print the inputErrorInfo Statement to the command line 
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, inputErrorInfo     ; setting rsi to the msg
        mov     rdx, 64                 ; message size is 80 bytes
        syscall
        jmp     endProgram              ; jump to endProgram block

printSuccess:                           ; print the createdFolderMsg statement to command line
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, createdFolderMsg   ; setting rsi to the msg
        mov     rdx, 51                 ; message size is 42 bytes
        syscall
        jmp     endProgram              ; jump to end program block

inputErrorInfo:
        db "Function requires exactly 2 argument: <new folder> <new file>", 10  ; 80 bytes

createdFolderMsg:
        db "Successfully created new folder and file.", 10                      ; 51 bytes
endProgram:
        mov     rax, 60
        xor     rdi, rdi
        syscall

section .data

fileText: db "Is your refrigerator running? Go on and catch it then!",10,0      ; 55 bytes




