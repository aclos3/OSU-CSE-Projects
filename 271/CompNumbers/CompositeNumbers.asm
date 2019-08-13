
TITLE CompositeNumbers   (CompositeNumbers.asm)

; Author:  Andrew Clos
; Last Modified:  7/23/2019
; OSU email address: closa@oregonstate.edu
; Course number/section: 271-400
; Assignment Number: 3          Due Date:  7/28/2019
; Description: Calculates and displays a user specified amount of composite numbers. I chose
;			   to also incorporate the extra credit option to display only odd composite numbers
;			   finally, I also attempted to not use any global variables to work on push and pop
;			   techniques.
INCLUDE			Irvine32.inc


.data
;intro text strings
	intro_1			BYTE	"Welcome to the Composite Number Spreadsheet", 0
	intro_2			BYTE	"Programmed by Andrew Clos", 0
	intro_3			BYTE	"This program is capable of generating a list of composite numbers", 0
	intro_4			BYTE	"Simply let me know how many you would like to see.", 0
	intro_5			BYTE	"I'll accept orders for up to ", 0
	intro_6			BYTE	" composites.", 0
	intro_7			BYTE	"**EC: Attempted extra credit to display only odd composite numbers. ", 0
	goodBye			BYTE	"Goodbye friend!", 0

;declared constants for min/max number of comps or 0/1 for odd comp choice
	MINCOMP			EQU	1    
	MAXCOMP			EQU	300  
	ONLYODD			EQU 2
	ALLCOMPS		EQU 1

;warnings and instructions for data input.
	prompt_0		BYTE	"Please enter 1 to view all composites or 2 to view only odd composites.", 0
	prompt_1		BYTE	"How many composites do you want to view? [", 0
	prompt_2		BYTE	" .. ", 0
	prompt_3		BYTE	"]: ", 0
	warnGreater		BYTE	"Number entered is too large, please enter and intger equal to 300 or less.", 0
	warnLesser		BYTE	"Number entered is too small, please enter and intger equal to 1 or greater.", 0
	spaces			BYTE	"     ", 0
	space1			BYTE	" ", 0	

.code	

;************************************************************************
; Procedure for main simply calls the procedures in order, but does push
; important register values to the stack between getUserData and 
; showComposites calls.
; receives: none
; returns: pushes eax and ebx to the stack
; preconditions: none
; registers changed: none
;************************************************************************
main				PROC

	call			intro
	call			getUserData
	push			eax   ;user's desired number of composites
	push			ebx   ;user's choice of odd/even
	call			showComposites
	call			outro		
	exit

main				ENDP

;************************************************************************
; Procedure to post the introduction and instructions to the user. 
; receives: MAXCOMP is a global constant 
; returns: none
; preconditions: none
; registers changed: eax, edx
;************************************************************************
intro				PROC

	mov				edx, OFFSET intro_1
	call			WriteString
	call			CrLf
	mov				edx, OFFSET intro_2
	call			WriteString
	call			CrLf
	mov				edx, OFFSET intro_3
	call			WriteString
	call			CrLf
	mov				edx, OFFSET intro_4
	call			WriteString
	call			CrLf
	mov				edx, OFFSET intro_5
	call			WriteString
	mov				eax, MAXCOMP
	call			WriteDec
	mov				edx, OFFSET intro_6
	call			WriteString
	call			CrLf
	mov				edx, OFFSET intro_7
	call			WriteString
	call			CrLf
	
	ret

intro				ENDP

;************************************************************************
; Procedure to get data from the user and perform call input validation
; receives: ALLCOMPS, ONLYOOD, MINCOMP, and MAXCOMP are global constants.
; returns: pushes four global constants and user menu choice, and composite
;		   number choice from eax to the stack.
; preconditions: none
; registers changed: eax, ebx, edx
;************************************************************************
getUserData			PROC
	
	UserOddLoop:
	mov				edx, OFFSET prompt_0
	call			WriteString
	call			CrLf
	call			ReadInt
	mov				ebx,eax      
	push			eax		  ;send initial user entered data to stack
	push			ALLCOMPS  ;send the min and max range for menu choice to the stack
	push			ONLYODD
	call			validate
	cmp				eax,0
	je				UserOddLoop
	
	UserEntryLoop:
	mov				eax,0
	mov				edx, OFFSET prompt_1
	call			WriteString
	mov				eax, MINCOMP
	call			WriteDec
	mov				edx, OFFSET prompt_2
	call			WriteString
	mov				eax, MAXCOMP
	call			WriteDec
	mov				edx, OFFSET prompt_3
	call			WriteString
	call			ReadInt
	push			eax      ;send initial user entered data to stack
	push			MINCOMP  ;send min and max number of composites to stack
	push			MAXCOMP
	call			validate
	cmp				eax,0
	je				UserEntryLoop

	ret				

 getUserData		ENDP

;************************************************************************
; Procedure to perform range of integer validation. Keeps program in loop
;			until proper input is received.
; receives: stack pointers for ebp +4, +8 and +12 to indicate min and max
;			ranges of user choices and the user's choice 
; returns:  cleans up stack by decrementing pointer (12)
; preconditions: that min/max range and user choice are pushed to stack
;				 (+4, +8, +12), respectively. 
; registers changed: eax, ebp, edx, esp
;************************************************************************
validate			PROC
	mov				ebp,esp    ;ebp to the stack pointer
	mov				eax,[ebp + 12]   ;retrieve user entered integer from stack
	BeginUserInput:
	cmp				eax, [ebp + 4]
	jle				IsLesser
	mov				edx, OFFSET warnGreater
	call			WriteString
	call			CrLf 
	jmp				NotValid
	IsLesser:
	cmp				eax, [ebp + 8]
	jge				EndUserInput
	mov				edx, OFFSET warnLesser
	call			WriteString
	call			CrLf
	jmp				NotValid
	
	jmp				BeginUserInput
	NotValid:
	mov				eax,0    ;reset eax to zero if entry was invalid
	EndUserInput:
	ret				12       ;clean up the stack
 validate			ENDP



;************************************************************************
; Procedure to use loop function to cycle through calls to isComposite
;			until the user specified number of composites have been shown.
; receives: user entered number of composites, which it takes from stack
;			(ebp + 8).
; returns: none
; preconditions: The stack location (ebp+8) contains number of composites
;				 to be printed.
; registers changed: ebp, eax, ebx, ecx
;************************************************************************
showComposites		PROC
	mov				eax, 1  ;line break counter
	push			eax     
	mov				ebp,esp
	mov				eax, 2  ;starting value to test for being a composite number
	mov				ebx, 1
	mov				ecx, [ebp + 12]
	
	
	OutputLoop:    ;loop through equal to number of composites user wants to see

	pushad            ;put registers on stack to retrieve after procedure call
	call			isComposite	
	
	cmp				ebx, 0  ;if ebx == 0, current number being evaluated is prime
	jne				Found
	popad
	inc				eax    ;increment the number to be tested
	inc				ecx   ;if current number was prime, add 1 to loop counter 
	jmp				EndLoop
	
	Found:
	;the follwoing 10 lines deal with adding a line break every 10 numbers.
	mov				eax, [ebp]
	cmp				eax, 10
	jne				SkipPrint
	mov				eax, 10
	sub				[ebp], eax
	call			CrLf
	SkipPrint:
	inc				DWORD PTR[ebp]  ;increment value of the line counter
	

	popad       ;after composite check and printing is finished, restore this loops registers
	inc				eax	   ;increment the number to be tested.
	EndLoop:
	loop			OutputLoop
	pop				eax
	ret				

 showComposites		ENDP

;************************************************************************
; Procedure to test a number (from caller) to see if it is composite and
;			output the number to the console if it is. It performs this 
;			test by using a loop, which starts at (test value - 1) and 
;			ends at 2. It then performs a divide on the test number by 
;			each of the loop counter values and if remainder is zero, the
;			test number is noted as a composite. Also handles skipping 
;		    even composites if that has been specified by the user. 
;			The addition of spacing and return lines is handled at the
;		    end of this function.
; receives: the number to be tested (eax).
; returns:  whether or not the number was composite (ebx incremented)
; preconditions: must contain the user menu option choice for 'only odd'
;			     display [ebp + 4].
; registers changed: ebx, exc, edx
;************************************************************************
isComposite			PROC

	mov				ebx,0	;ebx to be used for "found composite" indicator
	mov				ecx, eax
	dec				ecx
	CompLoop:

	cmp				ecx,1
	jbe				EndLoop
	mov				edx,0
	push			eax    ;eax holds the number being evaluated, so push/pop
	div				ecx    ;around the division function.
	pop				eax	
	cmp				edx,0
	je				CompTrue	
	loop			CompLoop
	CompTrue:
	push			ebx
	mov				ebx, [ebp + 8]  ;did the user want to only see odd?
	cmp				ebx, 2
	jne				NotFiltering   ;if all composites to be show, don't filter out evens.
	push			eax
	div				DWORD PTR[ebp + 8]  ;the value 1 or 2 in ebp+4 corresponds to odd only or all composites
	pop				eax
	cmp				edx, 0
	je				IsAnEvenComp
	NotFiltering:
	pop				ebx
	inc				ebx      ;tells the calling function a composite was found.
	call			WriteDec  ;output the positive result.
	mov				edx, OFFSET space1 ;adding an extra space if the number < 2 digits
	cmp				eax,10
	jge				SkipSpace
	call			WriteString  ;adding an extra space if the number is < 3 digits
	SkipSpace:
	cmp				eax,100
	jge				SkipSpace2
	call			WriteString
	SkipSpace2:
	mov				edx, OFFSET spaces
	call			WriteString
	jmp				EndLoop
	IsAnEvenComp:
	pop				ebx
	EndLoop:
	ret

isComposite		ENDP

 ;************************************************************************
; Procedure to print a friendly goodbye message to the console.
; receives: none
; returns: none
; preconditions:
; registers changed: EDX (puts memory offset of goodbye string in EDX) 
;************************************************************************
outro				PROC

	mov				edx, OFFSET goodBye
	call			CrLf
	call			CrLf
	call			WriteString
	call			CrLf
	ret

 outro				ENDP

END			main