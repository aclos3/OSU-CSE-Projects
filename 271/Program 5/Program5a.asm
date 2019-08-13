
TITLE Program5a   (Program5a.asm)

; Author:  Andrew Clos
; Last Modified: 8/3/2019
; OSU email address: closa@oregonstate.edu
; Course number/section: 271-400
; Assignment Number: 5A          Due Date:  8/11/2019
; Description: 
INCLUDE			Irvine32.inc

;-----------------------------------------------------------------------------
; This macro takes an offset of a string from the caller and writes it to the 
; screen, it then adds a return line. This macro push/pops edx to protect the
; calling procedure.
;-----------------------------------------------------------------------------
mWriter				MACRO	theWritten
	
	push			edx
	mov				edx, theWritten
	call			WriteString
	call			CrLf
	pop				edx

ENDM

;-----------------------------------------------------------------------------
; This macro takes three parameters from the caller. One is an offset to a 
; prompt containing the string to request user input, another is the max size 
; if the users entry (number of digits), and the other is the offset to the 
; memory location where the user entered string will be stored. This macro 
; push/pops ecx and edx to protect the calling procedure. 
;-----------------------------------------------------------------------------
mGetString			MACRO	numToGet, maxSize, prompt
	
	push			ecx
	push			edx

	EntryLoop:
	;prompt for 10 integers
	mov				edx, prompt
	call			WriteString

	mov				edx, numToGet
	mov				ecx, maxSize   
	call			ReadString

	pop				edx
	pop				ecx
ENDM

;-----------------------------------------------------------------------------
; This macro displays a string by calling the WriteString function on an offset 
; that is passed from the caller. This macro push/pops edx to protect the
; calling procedure.
;-----------------------------------------------------------------------------
mDisplayString		MACRO	displayMe
	
	push			edx

	mov				edx, displayMe
	call			WriteString

	pop				edx

ENDM


;-----------------------------------------------------------------------------
; Data segment containing intro, goodbye and instruction prompts as well as
; constants and variables for arrays and user data entry.
;-----------------------------------------------------------------------------
.data

;intro/outro text strings
	intro_1			BYTE	"Welcome to my Demonstration offset low-level I/O procedures!", 0
	intro_2			BYTE	"Programmed by Andrew Clos", 0
	goodBye			BYTE	"Goodbye friend!", 0

;declared constant for the number of integers to be entered by the user.
	NUMELEMENTS		EQU		10

;warnings, instructions and other userful strings

	prompt_1		BYTE	"Please provide 10 decimal integers.", 0
	prompt_2		BYTE	"Please enter an integer number: ", 0
	warnTooMany		BYTE	"Too many digits have been entered, please enter 5 or fewer digits.", 0
	warnOutofAscii	BYTE	"Entry contains chracter outside of the valid range (0 - 9), please try again.", 0
	comma			BYTE	", ", 0
	userList		BYTE	"You entered the following numbers:", 0
	sum				BYTE	"The sum offset these numbers is: ", 0
	average			BYTE	"The average is: ", 0

 ;variables 
	usrArray		DWORD	10 DUP(?)
	usrEntry		BYTE	16 DUP(0)
	tempString		BYTE	16 DUP(0)
	usrSum			DWORD	0
	usrAvg			DWORD	0

.code	


;************************************************************************
; The main procedures makes use of the mWriter macro to post introduction
; prompts, instructions and the goodbe messages. It also pushes addresses
; of variables, arrays and constants to the stack before calling the 
; applicable functions.
; receives: none
; returns: none
; preconditions: String variables, arrays and global constants contain the
; proper information since they are critical to the functions being called.
; registers changed: edx: macro calls modify edx for WriteString.
;************************************************************************
main				PROC
	
	mWriter			OFFSET intro_1
	mWriter			OFFSET intro_2
	call			CrLf
	mWriter			OFFSET prompt_1
	
	;READVAL
	push			OFFSET warnOutofAscii
	push			OFFSET warnTooMany
	push			NUMELEMENTS
	push			OFFSET prompt_2
	push			OFFSET usrEntry    
	push			OFFSET usrArray   
	call			ReadVal

	;ARRAYPRINTER
	mWriter			OFFSET userList

	push			OFFSET tempString
	push			NUMELEMENTS
	push			OFFSET comma
	push			OFFSET usrArray
	call			ArrayPrinter
	call			Crlf

	;DISPLAYSUM
	mWriter			OFFSET sum

	push			NUMELEMENTS
	push			OFFSET tempString
	push			OFFSET usrArray
	call			displaySum

	;DISPLAYAVERAGE:
	mWriter			OFFSET average

	push			NUMELEMENTS
	push			OFFSET tempString
	push			OFFSET usrArray
	call			displayAverage

	mWriter			OFFSET goodBye	
	exit

main				ENDP


;************************************************************************
; Procedure to read a value from the user and store the value in an array
; performs basic input validation to allow only ASCII code entries between
; 48 and 57 (0-9 decimal) as well as restrict the number of digits per
; integer to a maximum of 5.
; receives: prompts for instructions, warnings for data entry validation,
; the memory locations for the array to be filled and user entered number.
; returns: 
; preconditions: none
; registers changed: 
;************************************************************************
ReadVal				PROC
	
	push			ebp
	mov				ebp,esp
	
	;loop counter (10 by default)
	mov				ecx, [ebp + 20]

	mov				edi, [ebp + 8]   ;start of the integer array

	;loop 10(default) times through to collect user numbers
	Collect10Loop:
		
	;call to the mGetString to read in user entry.
	mGetString		[ebp + 12], [ebp + 20], [ebp + 16]

	;save outer loop counter
	push			ecx

	;check number of digits in user string, reject if greater than 5.
	cmp				eax, 5
	jg				TooManyDigits
	
	;put the user entered string in to esi and string length in to ecx
	mov				ecx, eax
	mov				esi, [ebp + 12]
	
	ValidateLoop:
	cld
	lodsb			

	;48-57 are the valid ASCII codes for chacters 0-9
	cmp				al, 57
	jg				InvalidDigit
	cmp				al, 48
	jl				InvalidDigit

	;the next four lines reset eax, then restore the value back to al.
	mov				edx, 0
	mov				dl, al
	mov				eax, 0
	mov				al, dl
	
	;convert to int: multiply digit by correct power of 10 based on its location in the string
	push			eax
	push			ecx
	mov				eax, 1
	Factor10Loop:
	mov				ebx, 10
	mul				ebx
	loop			Factor10Loop

	;remove extra factor of 10
	mov				edx, 0
	mov				ebx, 10
	div				ebx
	mov				ebx, eax
	
	pop				ecx
	pop				eax

	;convert eax from Ascii code to decimal, then multiply digit being evaluated by its factor of 10 and add to array.
	sub				eax, 48
	mul				ebx
	mov				edx, eax
	mov				eax, [edi]
	add				eax, edx
	mov				[edi], eax

	loop			ValidateLoop

	pop				ecx
	jmp				EndofCollect
	
	;if the entry contains too many digits, the warning is called, loop counter and array pointer are decremented.
	InvalidDigit:
	mWriter			[ebp + 28]
	pop				ecx
	inc				ecx
	sub				edi, 4
	jmp				EndofCollect

	;if the entry contains too many digits, the warning is called, loop counter and array pointer are decremented.
	TooManyDigits:
	mWriter			[ebp + 24]
	pop				ecx
	inc				ecx
	sub				edi, 4
		
	;when entry has succeeded, decrement loop counter, increment array pointer 
	EndofCollect:
	add				edi, 4
	dec				ecx
	cmp				ecx, 1
	jge				Collect10Loop

	pop				ebp
	ret				0

 ReadVal			ENDP

 ;*******************************************************************************
; Procedure prints the user's array of 10 integers. 
; receives: [ebp + 8] address of the start of the array of ints
;			[ebp + 12] string containing ", " for printing.
;			[ebp + 16] number of elements in the array
;			[ebp + 20] temporary string used while converting integer to string
; returns: none
; preconditions: [ebp + 16] must contain the correct number of elements in the array
; or the procedure will either not print all of the elements or it will move beyond
; the array's memory and the behavoir will be undefined.
;********************************************************************************
ArrayPrinter		PROC
	push			ebp
	mov				ebp,esp

	mov				esi, [ebp + 8] ;points to start of array
	mov				ecx, [ebp + 16] ;number of array elements

loopDisplay:
	pushad        ;push temp string and address of array pointer to stack before calling WriteVal
	push			[ebp + 20]
	push			[esi]
	call			WriteVal
	popad	

	cmp				ecx, 1 ;if this is the last number, don't print a comma
	je				NoComma

	mov				edx, [ebp + 12]	;add the comma/space
	call			WriteString

	NoComma:
	add				esi, 4  ;increment the array index pointer.
	loop			loopDisplay
	call			CrLf

	pop				ebp
	ret				

ArrayPrinter		ENDP
 ;************************************************************************
; Procedure is called whenever another procedure needs to print to the 
; console.  It builds a string by taking characters one at a time, 
; converting them to their ascii codes and inserting them in an array.
; It makes use of multiple loops that multiply a value by 10 a number of
; times to determine the correct "place" (10's 100's, 1000's, etc. for the
; character.
; receives: [ebp + 8] the integer to be converted
;			[ebp + 12] address of a temporary string for the converted
;				       number to reside in.
; returns: none
; preconditions: the number to be evaluated must contain characters 0-9
; or the conversion to ASCII code and subsequent output of the string will
; be nonsensical.
; registers changed: eax, ebx, ecx, edx, esi 
;************************************************************************
WriteVal			PROC
	push			ebp
	mov				ebp,esp

	mov				edi, [ebp + 12]   ;address of our temp string storage
	mov				eax, [ebp + 8]  ;the number to be evaluated
	
	mov				ecx, 0
	mov				ebx, 10
	push			eax
	;to determine the number of digits the number has.
	ReductionLoop:
	inc				ecx   ;counter will indicate number of digits when loop finishes.
	mov				edx, 0
	div				ebx			;if eax is zero after this division, we've reached the last digit.
	cmp				eax, 0
	jne				ReductionLoop				
	
	pop				eax

	;begin to fill the string. 
	BuildString:
	dec				ecx
	push			ecx
	mov				ebx, 10
	mov				ecx, 0
	push			eax
	
	;divide by 10 (minus one) to determine how many digits there are in total
	Divide10:
	inc				ecx
	mov				edx, 0
	div				ebx
	cmp				eax, 0
	jne				Divide10
	add				eax, edx
	push			edx

	;a 'multiply by 10' loop to place the character properly in the array
	;without this extra step, my arry was being filled backwards, so the printed
	;string was in reverse!
	L1:
	dec				ecx
	mul				ebx
	cmp				ecx, 0
	jne				L1
	
	;sets up the carry over (remainder) to be the next number evaluated by 
	;the next loop cycle, restore outer loop counter.
	mov				edx, 0
	div				ebx
	mov				ebx, eax
	pop				edx
	pop				eax
	pop				ecx
	sub				eax, ebx
	push			eax
	
	InsertDigit:
	add				edx, 48	  ;convert remainder to its Ascii code.
	mov				eax, 0   ;clear up eax 
	mov				al, dl
	;store the ASCII code in the array, increment array pointer
	stosb	
	
	pop				eax
	cmp				ecx, 1   ;loop again if there are more digits
	jge			BuildString

     ; add null to end of string. Before adding this, my strings would not terminate properly!
	mov				al, 0
	stosb

	;call macro to display the string to the console.
	mDisplayString	[ebp + 12]
	
	pop				ebp
	ret				8

WriteVal			ENDP


 ;*******************************************************************************
; Procedure sums an array of integers and calls WriteVal to display the sum to 
; the console. 
; receives: [ebp + 8] address of the start of the array of ints
;			[ebp + 12] address of string to be filled with converted integer.
;			[ebp + 16] number of elements in the array
; returns: none
; preconditions: [ebp + 16] must contain the correct number of elements in the array
; or the procedure will not count all elements or will step beyond the memory of the
; array and the behavior will be undefined. [ebp + 8] must be the starting address
; of an array of integers or crashing, rather than summing may take place. 
;********************************************************************************
DisplaySum			PROC
	push			ebp
	mov				ebp,esp
	
	mov				ecx, [ebp + 16]  ;number of elements
	mov				esi, [ebp + 8]   ;start of the array of integers
	mov				eax, 0    ;zero out the accumulator for our sum

	;sum each element of the array, storing value in eax
	SumLoop:
	mov				ebx, [esi]
	add				eax, ebx
	add				esi, 4  ;increment array pointer by 4 bytes (DWORD)
	loop			SumLoop

	;set up the stack and then call WriteVal
	push			[ebp + 12]  ;user string
	push			eax        ;usrSum
	call			WriteVal
	call			CrLf

	pop				ebp
	ret				
DisplaySum			ENDP


 ;*******************************************************************************
; Procedure sums an array of integers and then performs integer division by the
; number of integers to determine the average. Next, it calls WriteVal to display
; the average to the console. 
; receives: [ebp + 8] address of the start of the array of ints
;			[ebp + 12] address of string to be filled with converted integer.
;			[ebp + 16] number of elements in the array
; returns: none
; preconditions: [ebp + 16] must contain the correct number of elements in the array
; or the procedure will not count all elements or will step beyond the memory of the
; array and the behavior will be undefined. [ebp + 8] must be the starting address
; of an array of integers or crashing, rather than averaging may take place. 
;********************************************************************************
DisplayAverage		PROC
	push			ebp
	mov				ebp,esp
	
	mov				ecx, [ebp + 16]  ;number of elements
	mov				esi, [ebp + 8]   ;start of the array of integers
	mov				eax, 0     ;zero out the accumulator for our sum

	;sum each element of the array, storing value in eax
	SumLoop:
	mov				ebx, [esi]
	add				eax, ebx
	add				esi, 4
	loop			SumLoop

	;perform division on sum
	mov				edx, 0
	mov				ecx, [ebp + 16]
	div				ecx

	;set up the stack and then call WriteVal
	push			[ebp + 12]  ;user string
	push			eax        ;usrSum
	call			WriteVal
	call			CrLf

	pop				ebp
	ret				
DisplayAverage		ENDP

END			main