	AREA sum, CODE	
	ENTRY
	EXPORT __main

__main PROC
	MOV R0, #10
	ADD R1, R0, #1
	MOV R3, #2
	MUL R2, R0, R1
	SDIV R4, R2, R3

stop B stop
	ENDP
	END


