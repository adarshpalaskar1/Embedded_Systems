    AREA MYCODE, CODE
    ENTRY
    EXPORT __main
__main
    MOV R0, #2
    MOV R1, #1
    MOV R2, #10
    ADD R3, R1, R2         ; R3 = n+1
    MUL R3, R2             ; R3 = n*(n+1)
    SDIV R3, R0            ; R3 = n*(n+1)/2

stop B stop
    END
