.file    "main.c"    ;Name of the original C source
.section    .rodata    ;Define a read-only part of memory
.align 8    ;Aligns variables and instructions within a 8-byte boundary
.LC0:        ;Initialize a local variable to hold the a string for printf
.string    "The prime factorization of %i = "    ;Initialize a string
.LC1:        ;Initialize a local variable to hold the a string for printf
.string    "\n"        ;Initialize a new line for printf output
.text        ;Declares as the start of the section of code
.globl    main    ;Tells assembler to add list of labels by object file
.type    main, @function    ;Tell assembler text in main is executable code
main:        ;Defines a subroutine called main
.LFB0:    ;Establishes local label for the start of the main function
.cfi_startproc    ;Call frame information for dwarf format debugging
pushq    %rbp    ;Save previous rbp value on the stack for state preserve
.cfi_def_cfa_offset 16    ;Offset for Computing Call Frame is now 16 bytes
.cfi_offset 6, -16    ;Save the previous value of sixth register at offset of -16
movq    %rsp, %rbp    ;Create a new stack frame for function by moving the stack pointer
.cfi_def_cfa_register 6    ;Computing Call Frame is now the sixth register
subq    $32, %rsp    ;Establishing space for local variables
movl    %edi, -20(%rbp)    ;Move value in edi into the address in RAM that is the value of rbp with an offset of -20
movq    %rsi, -32(%rbp)    ;Move value in rsi into the address in RAM that is the value of rbp with an offset of -32
movq    %fs:40, %rax    ;Move the address of the memory address at offset 40 in the segment selected by the Far Segment into the rax register
movq    %rax, -8(%rbp)    ;Move value in rax into the address in RAM that is the value of rbp with an offset of -8
xorl    %eax, %eax    ;Clears eax register for temporary calculations
movl    $100, -12(%rbp)    ;Initialize variable to find its prime factors by loading the value 100 into the address in RAM that is the value of rbp with an offset of -12
movl    -12(%rbp), %eax    ;Move the value from the address in RAM that is the value in rbp with an offset of -12 into the eax register
movl    %eax, %esi    ;Move the value from the eax register to the esi register
movl    $.LC0, %edi    ;Effectively appending .LC0 value to the string value in the edi register
movl    $0, %eax    ;Resets the eax register to 0 by loading the value 0 into the eax register
call    printf    ;This part is from the library function name printf
leaq    -12(%rbp), %rax    ;Load effective address from the value in RAM that is the value in rbp with an offset of -12 into the rax register
movq    %rax, %rdi    ;Move the value from the rax register into the rdi register
call    outputPrimeFactor    ;Jumps to prime factor function
movl    $.LC1, %edi    ;Effectively appending .LC1 value to the string value in the edi register
call    puts    ;Takes a string and displays to standard output (POSIX)
movl    $0, %eax    ;Resets the eax register to 0 by loading the value 0 into the eax register
movq    -8(%rbp), %rdx    ;Move the value from the address in RAM that is the value in rbp with an offset of -8 into the rdx register
xorq    %fs:40, %rdx    ;Performs a check to make sure original stack pointer value
je    .L3    ;Conditionally jump to L3 when zero flag is set
call    __stack_chk_fail    ;The stack is corrupted, trigger fault
.L3:    ;Subroutine to return control back to the Operating System
leave    ;Releases the stack frame that was setup for the main function
.cfi_def_cfa 7, 8    Computes CFA by taking the address from the seventh register and add an offset of 8
ret    ;Pops the original address from the stack
.cfi_endproc    ;Closes the function’s unwind entry opened by startproc
.LFE0:    ;Establishes local label for the end of the main function
.size    main, .-main    ;Defines the size of the main function
.section    .rodata    ;Define this as a read-only part of memory
.LC2:        ;Holds the string value for one part of the appending string
.string    "%i x "    ;Initialize a string for output to screen
.LC3:        ;Holds the string value for second part of the appending string
.string    "%i"    ;Initialize a string for output to screen
.text        ;Declares as the start of the section of code
.globl    outputPrimeFactor    ;Tells assembler to add list of labels by object file
.type    outputPrimeFactor, @function    ;Tell assembler text in outputPrimeFactor is executable code
outputPrimeFactor:    ;Defines a subroutine called outputPrimeFactor
.LFB1:    ;Label that sets up memory allocation for the outputPrimeFactor function
.cfi_startproc    ;Call frame information for dwarf format debugging
pushq    %rbp    ;Save rbp register on the stack for setting up stack frame
.cfi_def_cfa_offset 16    ;Offset for Computing Call Frame is now 16 bytes
.cfi_offset 6, -16    ;Save the previous value of sixth register at offset of -16
movq    %rsp, %rbp    ;Create a new stack frame for function by moving the stack pointer
.cfi_def_cfa_register 6    ;Computing Call Frame is now the sixth register
subq    $32, %rsp    ;Establishing space for local variables
movq    %rdi, -24(%rbp)    ;Move the value from the rdi register to the address in RAM that is the value of the rbp register offset by -24
movl    $2, -4(%rbp)    ;Loads the value 2 to the address in RAM that is the value of the rbp register offset by -4
jmp    .L5    ;Unconditionally jumps to label L5
.L8:        ;Perform inner loop operation to determine conditional branching
movq    -24(%rbp), %rax    ;Move the value from the address in RAM that is the value in rbp with an offset of -24 into the rax register
movl    (%rax), %eax    ;Move the value from the address in RAM in rax into the eax register
cltd        ;Sign-extends eax register to double long
idivl    -4(%rbp)    ;Perform a division with eax and eac register on the value at the address in RAM that is the value in rbp
movl    %eax, %edx    ;Move the value from the eax register to the edx register
movq    -24(%rbp), %rax    ;Move the value from the address in RAM that is the value in rbp with an offset of -24 into the rax register
movl    %edx, (%rax)    ;Move value in edx register into the address in RAM that is the value of rax
movq    -24(%rbp), %rax    ;Move the value from the address in RAM that is the value in rbp with an offset of -24 into the rax register
movl    (%rax), %eax    ;Move the value from the address in RAM that is the value in rax into the eax register
cltd                    ;Sign-extends eax register to double long
idivl    -4(%rbp)    ;Perform a division with eax and eac register on the value at the address in RAM that is the value in rbp
testl    %eax, %eax    ;Sets flags whether eax register is 0, positive or negative
jle    .L7    ;Conditionally jump to label L7 when flags are less than or equal to 0
movl    -4(%rbp), %eax    ;Move the value from the address in RAM that is the value in rbp with an offset of -4 into the eax register
movl    %eax, %esi    ;Move the value from the eax register into the esi register
movl    $.LC2, %edi    ;Effectively appending .LC2 value to the string value in the edi register
movl    $0, %eax    ;Resets the eax register to 0
call    printf    ;This part is from the library function name printf
jmp    .L6    ;Unconditionally jumps to label L6
.L7:    ;Instructions for branching if conditional
movl    -4(%rbp), %eax    ;Move the value from the address in RAM that is the value in rbp with an offset of -4 into the eax register
movl    %eax, %esi        ;Move the value from the eax register into the esi register
movl    $.LC3, %edi    ;Effectively appending .LC3 value to the string value in the edi register
movl    $0, %eax    ;Resets the eax register to 0 by loading the value 0 into the eax register
call    printf    ;This part is from the library function name printf
.L6:    ;Instructions for branching else conditional
movq    -24(%rbp), %rax    ;Move the value from the address in RAM that is the value in rbp with an offset of -24 into the rdx register
movl    (%rax), %eax    Move the value from the address in RAM in rax into the eax register
cltd    ;Sign-extends eax register to double long
idivl    -4(%rbp)    ;Perform a division with eax and eac register on the value at the address in RAM that is the value in rbp
movl    %edx, %eax    ;Move the value from the edx register into the eax register
testl    %eax, %eax    ;Sets flags whether eax register is 0, positive or negative
je    .L8    ;Jumps to label L8 when zero flag is set. Looping back
addl    $1, -4(%rbp)    ;Adds the value 1 to the value of the address from rbp with 4 offset
.L5:    ;Cleans up memory after the outputPrimeFactor function finishes
movq    -24(%rbp), %rax    ;Take value from the address in rbp register with an offset of -24 and put it into rax register
movl    (%rax), %eax ;Put value from address of whole rax into eax part
cmpl    -4(%rbp), %eax    ;Performs a comparison between eax register and offset of bottom stack frame
jge    .L6    ;Conditionally jump to label L6 when flags are greater than or equal to 0
nop    ;Performs no operation and takes up space in instruction stream
leave    ;Releases the stack frame that was setup for the outputPrimeFactor function
.cfi_def_cfa 7, 8    ;Computes CFA by taking the address from the seventh register and add an offset of 8
ret        ;Pops the address of the main function from the stack
.cfi_endproc    ;Closes the function’s unwind entry opened by startproc
.LFE1:    ;Label that contains metadata for outputPrimeFactor function
.size    outputPrimeFactor, .-outputPrimeFactor    ;Defines the size of the main function
.ident    "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"    ;Identifies the version of the Operating System that it is compiled to
.section    .note.GNU-stack,"",@progbits    ;Linker knows to not require executable stack
