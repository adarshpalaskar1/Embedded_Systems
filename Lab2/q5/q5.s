	AREA input, DATA,READONLY
st DCD 0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9
	
	AREA Block, DATA
dat DCD 0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
	
	AREA transpose, CODE
		ENTRY
		EXPORT __main

__main
	LDR r0,=st
	LDR r1,=dat
	MOV r2,#0
	MOV r10,#3
	MOV r7,#4
	
	
t1	CMP r2,#9
	BGE stop

	UDIV r3,r2,r10
	MUL r4,r3,r10
	SUB r4,r2,r4
	
	MUL r4,r4,r10
	ADD r5,r4,r3
	
	MUL r5,r5,r7
	ADD r5,r5,r0
	
	MUL r6,r2,r7
	ADD r6,r6,r1
	
	LDR r8, [r5]
	STR r8, [r6]
	ADD r2,r2,#1
	B t1
	
stop B stop
	END
		
		
		