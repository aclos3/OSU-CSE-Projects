TITLE Adding Two Ints    (AddTwo.asm)

; Author:  Andrew Clos
; Last Modified:  6/25/2019
; OSU email address: closa@oregonstate.edu
; Course number/section: 271-400
; Assignment Number: XX            Due Date:  XX
; Description: Demo addition from book reading

INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.code						; area where you write code
main PROC

	mov eax,5
	add eax,6

	INVOKE ExitProcess,0
main ENDP
END main

