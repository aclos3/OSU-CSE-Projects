TITLE Composite Number Spreadsheet   (Program3.asm)

; Author:  Andrew Clos
; Last Modified:  7/22/2019
; OSU email address: closa@oregonstate.edu
; Course number/section: 271-400
; Assignment Number: 3         Due Date:  7/28/2019
; Description: 

INCLUDE Irvine32.inc

.data
;intro text
	intro_1			BYTE	"Welcome to the Composite Number Spreadsheet", 0
	intro_2			BYTE	"Programmed by Andrew Clos", 0
	intro_3			BYTE	"This program is capable offset generating a list of composite numbers", 0
	intro_4			BYTE	"Simply let me know how many you would like to see.", 0
	intro_5			BYTE	"I'll accept orders for up to 300 composites.", 0
	goodBye			BYTE	"Goodbye: ", 0

	;declared constants
	MINCOMP			DWORD	1    
	MAXCOMP			DWORD	300  



;inst_1			BYTE	"Please enter an integer between 1 and 46: ", 0
;warnGreater		BYTE	"Number entered is too large, please enter and intger equal to 300 or less:", 0
;warnLesser		BYTE	"Number entered is too small, please enter and intger equal to 1 or greater:", 0
;extraCredit		BYTE	"**EC: I attempted the extra credit by adding a printed tab character after each integer is printed.", 0
;blanks			BYTE	"     ", 0

;userFib			DWORD	47
;eaxHolder		DWORD	0
;edxHolder		DWORD	0
;ecxHolder		DWORD	0
;tabMake			BYTE 	9, 0

;nameBuffer		BYTE	100 DUP(0)   ;input buffer
;byteCount		DWORD	?           ;counter for user entered buffer length

.code						

;************************************************************************
; Section:		Introduction
; Description:  Greets the user and prompts them to enter their desired
;				number of .
;************************************************************************

introduction	PROC

	mov			edx, OFFSET intro_1
	call		WriteString
	call		CrLf
	mov			edx, OFFSET intro_2
	call		WriteString
	call		CrLf
	mov			edx, OFFSET intro_3
	call		WriteString
	call		CrLf
	mov			edx, OFFSET intro_4
	call		WriteString
	call		CrLf
	mov			edx, OFFSET intro_5
	call		WriteString
	call		CrLf
;	mov			edx, OFFSET extraCredit
;	call		WriteString
;	call		CrLf

	ret
introduction ENDP

;************************************************************************
; Section:		goodbye  
; Description:  Prints a goodbye message to the console.
;************************************************************************
goodbye PROC

	mov			edx, OFFSET goodbye
	call		WriteString
	call		CrLf

	ret
goodbye ENDP

main PROC

	call	introduction
	;call	getUserData	
	;call	showComposites
	call	goodbye






	exit
main ENDP

END main
