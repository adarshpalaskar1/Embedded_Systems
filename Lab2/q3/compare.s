	AREA main, CODE
	   ENTRY
	   EXPORT __main
__main 
		MOV r1, #101
		MOV r2, #1
		cmp r1, #10
		blt less_than_10
		cmp r1, #100
		blt less_than_100
		cmp r1, #1000
		blt less_than_1000
		bgt greater_than_1000

less_than_10
        MOV r3, #9
		MUL r2, r1, r3
        B stop		
less_than_100
        MOV r3, #8
        MUL r2, r1, r3
		B stop
less_than_1000
        MOV r3, #7
        MUL r2, r1, r3
		B stop
greater_than_1000
        MOV r3, #6
        MUL r2, r1, r3
		B stop
stop   
       END