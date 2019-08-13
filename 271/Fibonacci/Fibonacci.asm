TITLE Fibonacci   (ElemetaryArithmetic.asm)

; Author:  Andrew Clos
; Last Modified:  7/9/2019
; OSU email address: closa@oregonstate.edu
; Course number/section: 271-400
; Assignment Number: 2          Due Date:  7/14/2019
; Description: 

INCLUDE Irvine32.inc

.data

intro_1			BYTE	"Fibonacci Numbers", 0
intro_2			BYTE	"Programmed by Andrew Clos", 0
greet_1			BYTE	"What's your name?", 0
greet_2 		BYTE	"Hello, ", 0
inst_1			BYTE	"Enter the number offset Fibonacci terms to be displayed.", 0
inst_2			BYTE	"Please enter an integer between 1 and 46: ", 0
warnGreater		BYTE	"Number entered is too large, please enter and intger equal to 46 or less:", 0
warnLesser		BYTE	"Number entered is too small, please enter and intger equal to 1 or greater:", 0
extraCredit		BYTE	"**EC: I attempted the extra credit by adding a printed tab character after each integer is printed.", 0
blanks			BYTE	"     ", 0
maxFib			DWORD	46   ;the max allowable value of the user entered Fibonacci value
minFib			DWORD	1    ;the min allowabe value of the user entered Fibonacci value
userFib			DWORD	47
eaxHolder		DWORD	0
edxHolder		DWORD	0
ecxHolder		DWORD	0
tabMake			BYTE 	9, 0
goodBye			BYTE	"Goodbye: ", 0
nameBuffer		BYTE	100 DUP(0)   ;input buffer
byteCount		DWORD	?           ;counter for user entered buffer length

.code						
main PROC

;************************************************************************
; Section:		Introduction
; Description:  Greets the user and prompts them for their name. Then, it
;               stores the user's name in a variable and prints their name
;               along with other greeting text to the console.
;************************************************************************

	mov			edx, OFFSET intro_1
	call		WriteString
	call		CrLf
	mov			edx, OFFSET intro_2
	call		WriteString
	call		CrLf
	mov			edx, OFFSET extraCredit
	call		WriteString
	call		CrLf
	mov			edx, OFFSET greet_1
	call		WriteString
	call		CrLf
	mov			edx,OFFSET nameBuffer   ;point to the name buffer
	mov			ecx,SIZEOF nameBuffer	;max characters for user name
	call		ReadString				;get the user's input
	mov			byteCount,eax
	mov			edx, OFFSET greet_2
	call		WriteString
	mov			edx, OFFSET nameBuffer
	call		WriteString
	call		CrLf

;************************************************************************
; Section:		displayInstructions  
; Description:  Displays two lines of instructions to the console.
;
;************************************************************************

	mov			edx, OFFSET inst_1
	call		WriteString
	call		CrLf
	mov			edx, OFFSET inst_2
	call		WriteString
	call		CrLf

;************************************************************************
; Section:		getUserInfo
; Description:  Reads the user entered value and utilizes compare and jump
;				functions to explain to the user if the value was above
;				or below the allowable range. The loop exits only when an
;				integer within the allowable range is entered.
;************************************************************************
	
BeginUserInput:
	call		ReadInt
	mov			userFib, eax
IsGreater:
	cmp			eax,maxFib
	jle			IsLesser
	mov			edx, OFFSET warnGreater
	call		WriteString
	jg			BeginUserInput
IsLesser:
	cmp			eax,minFib
	jge			EndUserInput	
	mov			edx, OFFSET warnLesser
	call		WriteString
	jmp			BeginUserInput
EndUserInput:

;************************************************************************
; Section:		displayFibs
; Description:  Uses a loop and several registers to add the Fibonacci
;				sequence, maintain counters for the loop and for to print
;				four integers per line.  Register values that are used
;				for loop counters and for Fibonacci terms are sometimes
;				stored in "holder" variables so that they may be used for
;				other purposes within the loop and then reset as needed.
;************************************************************************

	mov			ecx, userFib
	mov			ebx, 1
BeginFib:
	mov			eax, eaxHolder
	mov			edx, edxHolder
	mov			edx, eax   ;general concept: ebx serves 'temp' storage
	add			edx, ebx   ;edx serves as 'term 2' and eax serves as 'term 1'
	mov			eax, ebx
	mov			eaxHolder, eax
	mov			edxHolder, edx
	call		WriteDec
	mov			edx, OFFSET blanks  ;string of five "space" characters
	call		WriteString
	mov			al, tabMake   ;use AL buffer to hold character 9 "Tab"
	call		WriteChar
	mov			edx, edxHolder
	mov			eax, eaxHolder
	mov			ebx, edx
	;add section to make extra tab for smaller terms for better column alignment
	cmp			eax, 232
	jge			SkipTab
	mov			al, tabMake   ;use AL buffer to hold character 9 "Tab"
	call		WriteChar
SkipTab:
	;this mini-section is for printing 4 terms per line
	;begin by storing current loop counter value in variable
	mov			ecxHolder, ecx
	; the next three lines set up eax to be a positive incrementing loop counter
	mov			eax, userFib
	inc			eax
	sub			eax, ecx
	;the next 5 lines perform integer division and jump to print a new line once
	;4 terms have been printed.
	mov			edx, 0
	mov			ecx, 4
	div			ecx
	mov			eax, edx
	cmp			eax, 0
	jz			NewLine
EndNewLine:
	mov			ecx, ecxHolder
	loop		BeginFib 
	jmp			EndFib ;when ecx (loop counter reaches 0), this line executes
NewLine:
	call		CrLf
	cmp			eax, 0
	jz			EndNewLine
EndFib:

;************************************************************************
; Section:		goodbye  
; Description:  Prints a goodbye message to the console and uses the 
;			    nameBuffer variable again.
;************************************************************************

	call		CrLf
	mov			edx, OFFSET goodBye
	call		WriteString
	mov			edx,OFFSET nameBuffer
	call		WriteString
	exit	
main ENDP

END main
