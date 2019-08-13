TITLE Elementary Arithmetic   (ElemetaryArithmetic.asm)

; Author:  Andrew Clos
; Last Modified:  6/25/2019
; OSU email address: closa@oregonstate.edu
; Course number/section: 271-400
; Assignment Number: 1          Due Date:  7/7/2019
; Description: This program will introduce the programmer, get twi numbers from the user
;              and then compute and display the sum, difference, quotient and remainder of
;              those numbers.


INCLUDE Irvine32.inc

.data

intro_1		BYTE	"Hi, my name is Andrew Clos and this is Elementary Arithmetic.", 0
intro_2		BYTE	"Enter two numbers and I'll show you the sum, difference, product, quotient and remainder.", 0
exCred_1	BYTE	"**EC: Compares the two inputs to determine if second number is less than the first.", 0
exCred_2	BYTE	"**EC: Displays the squared values of each user input.", 0
prompt_1	BYTE	"Please enter first number: ", 0
prompt_2	BYTE	"Please enter the second number: ", 0
prompt_3	BYTE	"Second number cannot be zero!", 0
prompt_4	BYTE	"First number is smaller than second number, not allowed!", 0
goodBye		BYTE	"Goodbye!", 0

;entered by user or calculated by program
userNum_1	DWORD	?		
userNum_2	DWORD	?			
valSum 		DWORD	?
valDiff 	DWORD	?
valProd 	DWORD	?
valQuot 	DWORD	?
valRemain	DWORD	?
valSquare1	DWORD	?
valSquare2	DWORD	?

;strings for display in equations / operators
operPlus	BYTE	" + ", 0
operDiff	BYTE	" - ", 0
operProd	BYTE	" x ", 0
operQuot	BYTE	" / ", 0
operRemain	BYTE	" remainder ", 0
operEquals	BYTE	" = ", 0
operSquare	BYTE	" squared = ", 0

.code						
main PROC
;display programmer introduction, explain extra credit
	mov		edx, OFFSET intro_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET exCred_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET exCred_2
	call	WriteString
	call	CrLf
	mov		edx, OFFSET intro_2
	call	WriteString
	call	CrLf

; prompt for numbers 1 and 2, store as variables, input validation (0)
Reprompt:
	mov		edx, OFFSET prompt_1
	call	WriteString
	call	ReadInt
	mov		userNum_1, eax
	mov		edx, OFFSET prompt_2
	call	WriteString
	call	ReadInt
	jz		Illegal1				;if zero, jump
	mov		userNum_2, eax
; Compares user nums and jumps to re-prompt for entry if first < second
	mov		eax, userNum_1
	cmp		eax, userNum_2
	jl		Illegal2
	jge		Continue
; jumped to if second integer entered is 0.
Illegal1:
	mov		edx, OFFSET prompt_3
	call	WriteString
	call	CrLf
	jge		Reprompt
; jumped to if first user num < second user num
Illegal2:
	mov		edx, OFFSET prompt_4
	call	WriteString
	call	CrLf
	jge		Reprompt

Continue:
; calculate sum, diff, product, quotient and remainder, and squares
	;sum
	mov		eax, userNum_1
	add		eax, userNum_2
	mov		valSum, eax
	;diff
	mov		eax, userNum_1
	sub		eax, userNum_2
	mov		valDiff, eax
	;product
	mov		eax, userNum_1
	mov		ebx, userNum_2
	mul		ebx
	mov		valProd, eax
	;quotient and remainder
	cdq
	mov		eax, userNum_1
	mov		ebx, userNum_2
	div		ebx
	mov		valQuot, eax
	mov		valRemain, edx
	;squares
	mov		eax, userNum_1
	mov		ebx, userNum_1
	mul		ebx
	mov		valSquare1, eax
	mov		eax, userNum_2
	mov		ebx, userNum_2
	mul		ebx
	mov		valSquare2, eax
; display equations and values
	; sum
	mov		eax, userNum_1
	call	WriteDec
	mov		edx, OFFSET operPlus
	call	WriteString
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET operEquals
	call	WriteString
	mov		eax, valSum
	call	WriteDec
	call	CrLf
	; difference
	mov		eax, userNum_1
	call	WriteDec
	mov		edx, OFFSET operDiff
	call	WriteString
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET operEquals
	call	WriteString
	mov		eax, valDiff
	call	WriteDec
	call	CrLf
	; product
	mov		eax, userNum_1
	call	WriteDec
	mov		edx, OFFSET operProd
	call	WriteString
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET operEquals
	call	WriteString
	mov		eax, valProd
	call	WriteDec
	call	CrLf
	; quotient and remainder
	mov		eax, userNum_1
	call	WriteDec
	mov		edx, OFFSET operQuot
	call	WriteString
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET operEquals
	call	WriteString
	mov		eax, valQuot
	call	WriteDec
	mov		edx, OFFSET operRemain
	call	WriteString
	mov		eax, valRemain
	call	WriteDec
	call	CrLf
	; squares
	mov		eax, userNum_1
	call	WriteDec
	mov		edx, OFFSET operSquare
	call	WriteString
	mov		eax, valSquare1
	call	WriteDec
	call	CrLf
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET operSquare
	call	WriteString
	mov		eax, valSquare2
	call	WriteDec
	call	CrLf
;say goodbye
	mov		edx, OFFSET goodBye
	call	WriteString
	call	CrLf
	exit	
main ENDP

END main
