	AREA sum, CODE
	ENTRY
	EXPORT __main

__main 
	MOV R0, #10
	MOV R1, #3
	ADD R0, R0, R1
stop B stop
	END