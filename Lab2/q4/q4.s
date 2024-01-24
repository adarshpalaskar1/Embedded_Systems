	AREA main, CODE
		ENTRY
		EXPORT __main
		   
__main 
		MOV r0, #0
		MOV r3, #2
		
		CMP r0, #0
		BEQ equal
		UDIV r2,r0,r3
		MUL r2,r2,r3
		SUB r2,r0,r2
		
		CMP r2,#0
		BEQ even
		
		CMP r2,#1
		BEQ odd
		
equal 	MOV r1,#128
		B st

odd		MOV r1,#512
		B st
		
even	MOV r1,#256
		B st

st		ADD r0,r0, #1
		END