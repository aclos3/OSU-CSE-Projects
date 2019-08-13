
TITLE RandomNumberSorter   (RandomNumberSorter.asm)

; Author:  Andrew Clos
; Last Modified: 8/1/2019
; OSU email address: closa@oregonstate.edu
; Course number/section: 271-400
; Assignment Number: 4          Due Date:  8/4/2019
; Description: 
INCLUDE			Irvine32.inc


.data
;intro text strings
	intro_1			BYTE	"Welcome to the Random Number Sorter!", 0
	intro_2			BYTE	"Programmed by Andrew Clos", 0
	intro_3			BYTE	"This program generates numbers in the range [", 0
	intro_4			BYTE	" .. ", 0
	intro_5			BYTE	"], ", 0
	intro_6			BYTE	"displays the original list, sorts the list and calculates the median value. Finally, it displays the list sorted in descending order. ", 0
	goodBye			BYTE	"Goodbye friend!", 0

;declared constants for min/max range of generation and 'number of numbers' to display
	MINRANGE		EQU	100    
	MAXRANGE		EQU	999  
	MINNUMS			EQU 15
	MAXNUMS			EQU 200

;warnings, instructions and other userful strings

	prompt_1		BYTE	"How many numbers should be generated? [", 0
	prompt_2		BYTE	" .. ", 0
	prompt_3		BYTE	"]: ", 0
	warnGreater		BYTE	"Number entered is too large, please enter an integer equal to ", 0
	warnGreater_2	BYTE	" or less.", 0
	warnLesser		BYTE	"Number entered is too small, please enter an integer equal to ", 0
	warnLesser_2	BYTE	" or greater.", 0
	space_1			BYTE	" ", 0
	spaces			BYTE	"     ", 0
	unsorted		BYTE	"The unsorted random numbers:", 0
	sorted			BYTE	"The sorted list:", 0
	median			BYTE	"The median is: ", 0
	point5			BYTE	".5", 0

 ;variables 
	numElements		DWORD	?
	usrArray		DWORD	200 DUP(?)

.code	

;************************************************************************
; Procedure main pushes prompts, variables and constants to the stack and
; calls the procedures in the proper order.
; receives: eax containing validated user entry for number of integers.
; returns: none
; preconditions: eax must contain valid userNum before fill array call
; all constants, variables and strings must be populated in the .data
; section.
; registers changed: none (esp from all the pushes).
;************************************************************************
main				PROC
	call			Randomize  ;seed randomly at beginning of program

	;INTRO strings and ranges pushed to stack, then procedure called 
	push			MAXRANGE
	push			MINRANGE
	push			OFFSET intro_6  
	push			OFFSET intro_5
	push			OFFSET intro_4
	push			OFFSET intro_3
	push			OFFSET intro_2
	push			OFFSET intro_1
	call			intro

	;GETUSERDATA: strings, ranges and variable for number of array elements pushed
	push			OFFSET warnGreater
	push			OFFSET warnGreater_2
	push			OFFSET warnLesser
	push			OFFSET warnLesser_2
	push			numElements
	push			MAXNUMS
	push			MINNUMS
	push			OFFSET prompt_3
	push			OFFSET prompt_2
	push			OFFSET prompt_1
	call			getUserData

	;FILLARRAY: validated user entry stored in variable. Array, ranges and user number pushed
	mov				numElements, eax 
	push			MAXRANGE
	push			MINRANGE
	push			numElements
	push			OFFSET usrArray  ;array passed by reference 
	call			fillArray
	
	;DISPLAYLIST: title and prompts, user number and array address pushed
	push			OFFSET unsorted  
	push			OFFSET spaces
	push			OFFSET space_1
	push			numElements
	push			OFFSET usrArray
	call			displayList
	
	;SORTLIST: array size and array address pushed
	push			numElements
	push			OFFSET usrArray
	call			sortList

	;DISPLAYMEDIAN: title and text, user number, and array address pushed
	push			OFFSET point5
	push			OFFSET median
	push			numElements
	push			OFFSET usrArray
	call			displayMedian

	;DISPLAYLIST: second call. sorted title, instead of unsorted title text pushed
	push			OFFSET sorted  
	push			OFFSET spaces
	push			OFFSET space_1
	push			numElements
	push			OFFSET usrArray
	call			displayList

	;GOODBYE: offset to string for goodbye message.
	push			OFFSET goodBye
	call			outro		
	exit

main				ENDP

;************************************************************************
; Procedure to post the introduction and instructions to the user. 
; receives: 6 offsets to memory addresses for welcome strings and 2 
;		    addresses to constants to represent upper and lower limits.
; returns: none
; preconditions: valid parameters on stack in [ebp+8] to [ebp+36]
; registers changed: eax, edx
;************************************************************************
intro				PROC

	push			ebp
	mov				ebp,esp

	mov				edx, [ebp + 8]
	call			WriteString
	call			CrLf
	mov				edx, [ebp + 12]
	call			WriteString
	call			CrLf
	mov				edx, [ebp + 16]
	call			WriteString
	mov				eax, [ebp + 32]
	call			WriteDec
	mov				edx, [ebp + 20]
	call			WriteString
	mov				eax, [ebp + 36]
	call			WriteDec
	mov				edx, [ebp + 24]
	call			WriteString
	call			CrLf
	mov				edx, [ebp + 28]
	call			WriteString
	call			CrLf
	
	pop				ebp
	ret				

intro				ENDP

;************************************************************************
; Procedure to get data from the user and perform call input validation
; receives: MINNUMS and MAXNUMS are global constants.
; returns: pushes two global constants and user numbers from eax to the 
;		   stack.
; preconditions: none
; registers changed: 
;************************************************************************
getUserData			PROC
	
	push			ebp
	mov				ebp,esp
	
	UserEntryLoop:
	;display the prompt and limits and collect data from user
	mov				eax,0
	mov				edx, [ebp + 8]
	call			WriteString
	mov				eax, [ebp + 20]
	call			WriteDec
	mov				edx, [ebp + 12]
	call			WriteString
	mov				eax, [ebp + 24]
	call			WriteDec
	mov				edx, [ebp + 16]
	call			WriteString
	call			ReadInt
	
	;push the limit, prompts, and user entered integer to the stack for validation
	push			[ebp + 32]
	push			[ebp + 36]
	push			[ebp + 40]
	push			[ebp + 44]
	push			eax
	push			[ebp + 20]
	push			[ebp + 24]
	call			validate

	;if eax is zero, it means data entry was invalid, loop to top to display prompts again.
	cmp				eax,0
	je				UserEntryLoop
	
	pop				ebp
	ret				0

 getUserData		ENDP

;************************************************************************
; Procedure to perform range of integer validation. Keeps program in loop
; until valid input is received.
; receives: [ebp + 8]: upper limit of user nums (200 by default).
;			[ebp + 12]: lower limit of user nums (15 by default).
;			[ebb + 16]: user entered number.
; returns: eax as zero if not valid, eax as user value if valid.
; preconditions: that upper limit is greater than lower limit, that 0 is 
;                not a valid integer.
; registers changed: eax, edx 
;************************************************************************
validate			PROC
	push			ebp
	mov				ebp,esp    

	mov				eax,[ebp + 16]   ;retrieve user entered integer from stack
	BeginUserInput:
	cmp				eax, [ebp + 8]  ;compare to upper limit
	jle				IsLesser
	mov				edx, [ebp + 20]
	call			WriteString
	push			eax
	mov				eax, [ebp + 8]
	call			WriteDec
	pop				eax
	mov				edx, [ebp + 24]
	call			WriteString
	call			CrLf 
	jmp				NotValid
	IsLesser:
	cmp				eax, [ebp + 12]  ;compare to lower limit
	jge				EndUserInput
	mov				edx, [ebp + 28]
	call			WriteString
	push			eax
	mov				eax, [ebp + 12]
	call			WriteDec
	pop				eax
	mov				edx, [ebp + 32 ]
	call			WriteString
	call			CrLf
	jmp				NotValid
	
	jmp				BeginUserInput
	NotValid:
	mov				eax,0    ;reset eax to zero if entry was invalid
	EndUserInput:
	
	pop				ebp
	ret				28

 validate			ENDP

 ;************************************************************************
; Procedure fills an array with Random integers, but determining the range
; of integers, calling the RandomRange procedure, and then placing the 
; generated value in to the array. This occurs within a loop that steps
; through each element of the array (based on user specified number of 
; elements.
; receives: [ebp + 8]: memory offset of the array.
;			[ebp + 12]: user specifed number of integers.
;			[ebb + 16]: min range (100 by default).
;			[ebb + 20]:  max range (999 by default).
; returns: an array populated with integers.
; preconditions: min range [ebp + 16] must be below max range [ebp + 20].
; registers changed: eax, ecx, edi 
;************************************************************************
fillArray			PROC
	
	push			ebp
	mov				ebp,esp

	mov				edi, [ebp + 8]    ;start of array address to edi
	mov				ecx, [ebp + 12]   ;loop counter gets user number

filler:     ;start of loop to first get a random number in the right range to eax.
	mov				eax, [ebp + 20]  ;max range value
	sub				eax, [ebp + 16]  ;subtract the minimum value
	inc				eax				 ;add one to get correct 'span'
	call			RandomRange
	add				eax, [ebp + 16]  ;add minimum to back in to correct range.

	  ;add the randomly generated number in to the array
	mov				[edi], eax
	add				edi, 4  ;increment the array to the next index before looping again
	
	loop			filler
	pop				ebp
	ret				8
 fillArray			ENDP

;************************************************************************
; Procedure sorts an array of integers in ascending order. It does this by
; looping through the array twice and comparing values that are next to
; each other and swapping them if required. (bubble sort)
; receives: [ebp + 8]: memory offset of the array.
;			[ebp + 12]: user specifed number of integers.
; returns: none, but modifies the array of integers)
; preconditions: user specified number of array elements must match the 
;				 number of elements in the array.
; registers changed: eax, ecx, esi 
;************************************************************************
sortList			PROC
	push			ebp
	mov				ebp,esp

	mov				ecx, [ebp + 12]   ;loop counter gets user number
	dec				ecx

;the following section contains two loops to perform a bubble sort
;source cited: from Irvine Assembly Language book, 9.5.1
OuterLoop:
	push			ecx			;preserving the outer loop counter
	mov				esi, [ebp + 8]  ;point to address of first array element

InnerLoop:
	mov				eax, [esi]       ;get integer in from array
	cmp				[esi + 4], eax   
	jge				EndInner        ;don't exchange if 'left' is already less than 'right'
	
	pushad			;store all registers so as not to modify them with the procedure call	
	call			exchangeElements
	popad

EndInner:
	add				esi, 4			;increment array pointer
	loop			InnerLoop
	pop				ecx				;restore outer loop counter
	loop			OuterLoop
EndOuter:
	pop				ebp
	ret				8

sortList			ENDP

;************************************************************************
; Procedure is called during looping of the sortList procedures and
; exchanges the values of [esi] and [esi+4]
; receives: values to be swapped (in [esi] and [esi+4].
; returns: swapped values
; preconditions: [esi] and [esi+4] must contain the values to be swapped.
; registers changed: eax, ebx, ecx.
;************************************************************************
exchangeElements	PROC
	push			ebp
	mov				ebp,esp

	;the next four lines perform the swap, using eax and ebx as holders.
	mov				eax, [esi]   
	mov				ebx, [esi + 4]
	mov				[esi], ebx
	mov				[esi + 4], eax

	pop				ebp
	ret

exchangeElements	ENDP

;************************************************************************
; Procedure prints the median value of an array of integers. It does this
; by determining the 'middle' of the array and displaying that value to
; the console. If the array contains an even number of integers, it takes
; the middle two integers and averages them to determine median.
; receives: [ebp + 8]: memory offset of the array.
;			[ebp + 12]: user specifed number of integers.
;			[ebb + 16]: memory offset of a title string.
;			[ebb + 20]: memory offset of a string ".5" to append to
;			averaged median, if necessary.
; returns: none
; preconditions: user specified number of array elements must match the 
;				 number of elements in the array.
; registers changed: eax, ebx, ecx, edx, esi 
;************************************************************************
displayMedian		PROC
	push			ebp
	mov				ebp,esp
	
	mov				esi, [ebp + 8]    ;start of array address to esi
	mov				eax, [ebp + 12]
	
	;this section performs integer division on the number of array elements
	; to find the middle of the array. If the result is an even number it will
	;look at the middle two values of the array and average them.
	mov				edx, 0  
	mov				ebx, 2
	div				ebx
	push 			edx    ;need remainder of division on stack for use later.
	
	;this determines the center of the array and checks to see if the array
	;contained an even number of numbers.  If it was even, the center two
	;values of the array are added together and diveded by 2 to find their
	;average.  If that resulting value is odd, a ".5" is appended to the
	;integer that is displayed on the console.
	mov				ebx, 4
	mul				ebx
	mov				ebx, eax
	add				esi, ebx
	mov				eax, [esi]
	pop				edx
	cmp				edx, 0
	jne				Odd  
	mov				ebx, [esi - 4] ;get the value one to the left of the "center"
	add				eax, ebx      ;find their average
	mov				ecx, 2
	div				ecx
	mov				ebx, edx    ;store the result of the division (odd/even) for later
	Odd:
	;median text output
	mov				edx, [ebp + 16]
	call			WriteString
	call			WriteDec

	;check to see if average was odd, if so, append a ".5" to the end.
	cmp				ebx,1   ;will either be even (multiple of four, or 0 or 1 if usernum was even)
	jne				NotEven
	mov				edx, [ebp + 20]
	call			WriteString
	NotEven:
	call			CrLf

	pop				ebp	
	ret				

displayMedian		ENDP

;************************************************************************
; Procedure prints an array of integers in rows of 10. It also adds an 
; extra space to integers that are only two digits long to keep the 
; columns aligned.
; receives: [ebp + 8]: memory offset of the array.
;			[ebp + 12]: user specifed number of integers.
;			[ebb + 16]: memory offset of a string containing single space.
;			[ebb + 20]: memory offset of a string containing five spaces.
;			[ebb + 24]: memory offset of a string containing the title.
; returns: none
; preconditions: user specified number of array elements must be correct.
; registers changed: eax, ebx, ecx, edx, esi 
;************************************************************************
displayList			PROC
	push			ebp
	mov				ebp,esp

	mov				esi, [ebp + 8]
	mov				ecx, [ebp + 12]
	mov				ebx, 1			;incrementing counter for column printing

	;display the sorted/unsorted title
	mov				edx, [ebp + 24]
	call			WriteString
	call			CrLf

loopDisplay:
	mov				eax, [esi]
	call			WriteDec

;the following section deals with column alignment
;although the range specified by the assignment contains only 3 digit numbers
;this mini-section is capable of handling column alignment for 1 - 3 digit numbers as well.

	mov				edx, [ebp + 16]   ;single space character occupies this string
	cmp				eax, 10         ;add extra space if <2 digits 
	jge				SkipSpace
	call			WriteString  ;adding an extra space if the number is < 3 digits
	SkipSpace:
	cmp				eax,100
	jge				SkipSpace2
	call			WriteString
	SkipSpace2:
	mov				edx, [ebp + 20]   ;five spaces (standard space between numbers)
	call			WriteString
	
;the following section deals with adding a return line after every 10 numbers are printed.
	cmp				ebx, 10
	jne				NoReturnLine
	mov				ebx, 1
	call			CrLf
	jmp				EndLoop
	NoReturnLine:
	inc				ebx
	EndLoop:
	add				esi,4  ;increment the array index pointer.
	loop			loopDisplay
	call			CrLf

	pop				ebp
	ret				8

displayList			ENDP

;************************************************************************
; Procedure to print a friendly goodbye message to the console.
; receives: [ebp + 8] which contains the memory offset of the goodbye string.
; returns: none
; preconditions: none
; registers changed: EDX (puts memory offset of goodbye string in EDX) 
;************************************************************************
outro				PROC
	
	push			ebp
	mov				ebp,esp

	mov				edx, [ebp + 8]
	call			CrLf
	call			CrLf
	call			WriteString
	call			CrLf

	pop				ebp
	ret

 outro				ENDP

END			main