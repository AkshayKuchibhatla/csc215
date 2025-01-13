; CP/M I/O SUBROUTINES 13 NOVEMBER 24

;ASCII CHARACTERS' SETUP
CR      EQU     0DH     ; CARRIAGE RETURN
LF      EQU     0AH     ; LINE FEED
CTRLZ   EQU     1AH     ;OPERATOR INTERRUPT

;CP/M BDOS FUNCTIONS
RCONF   EQU     1    ; READ CON: INTO (A)
WCONF   EQU     2      ;WRITE (A) INTO CON:

;CP/M ADDRESSES
RBOOT   EQU     0       ;REBOOT CP/M SYSTEM
BDOS    EQU     5       ; THE SYSTEM CALL ENTRY
TPA     EQU     100H    ; TRANSIENT PROGRAM AREA
        ORG     TPA     ;ASSEMBLY PROGRAM FOR TPA

START:  LXI     SP,STAK ;SET UP THE USER STACK
START1: CALL    CI      ; INPUT A CONSOLE CHARACTER
        CPI     CTRLZ   ; OPERATOR INTERRUPT?
        JZ      RBOOT   ;IF YES, THEN RETURN TO CP/M
        CALL    CO      ; IF NOT, THEN ECHO IT AND
        JMP     START1  ;   LOOP.

; CONSOLE CHARACTER INTO REGISTER A MASKED TO 7 BITS
CI:     PUSH    B       ;SAVE REGISTERS
        PUSH    D
        PUSH    H
        MVI     C,RCONF ;READ FUNCTION IN (C)
        CALL    BDOS
        ANI     7FH     ;MASK TO 7 BITS
        POP     H       ;RESTORE REGISTERS
        POP     D       
        POP     B
        RET

; CHARACTER IN REGISTER A OUTPUT TO CONSOLE 
CO:     PUSH    B       ;SAVE REGISTERS
        PUSH    D
        PUSH    H
        MVI     C,WCONF ; SELECT FUNCTION AND MOVE INT (C)
        MOV     E,A     ;CHARACTER MOVED FROM (A) TO (E)
        CALL    BDOS    ; OUTPUT BY CP/M
        POP     H       
        POP     D
        POP     B
        RET

; SET UP STACK SPACE AT THE END OF PROGRAM
        DS      64      ;40H LOCATIONS (64 IN DEC)
STAK:   DB      0       ; TOP OF STACK

        END

