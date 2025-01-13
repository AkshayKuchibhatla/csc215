; TRICKY TECHNIQUES SUBROUTINES NOV 21 2O24

;ASCII CHARACTERS' SETUP
CR      EQU     0DH     ; CARRIAGE RETURN
LF      EQU     0AH     ; LINE FEED
CTRLZ   EQU     1AH     ; OPERATOR INTERRUPT

;CP/M BDOS FUNCTIONS
RCONF   EQU     1    ; READ CON: INTO (A)
WCONF   EQU     2    ; WRITE (A) INTO CON:
RBUFF   EQU     10   ; READ A CONSOLE LINE FUNCTION

;CP/M ADDRESSES
RBOOT   EQU     0       ; REBOOT CP/M SYSTEM
BDOS    EQU     5       ; THE SYSTEM CALL ENTRY
TPA     EQU     100H    ; TRANSIENT PROGRAM AREA
        ORG     TPA     ; ASSEMBLY PROGRAM FOR TPA

START:  LXI     SP,STAK ; SET UP THE USER STACK
START1: CALL    CCRLF   ; START A NEW LINE
        LXI     H,SINON ; WITH SIGN-ON MESSAGE
        CALL    COMSG
START2: CALL    TWOCR   ; DOUBLE SPACE LINES
        CALL    SPMSG   ; PROMPT FOR TEST
        DB      'TESTING YES/NO FROM CONSOLE',CR,LF,0
        CALL    GETYN
        JNZ     START3  ; GOT A "NO"
        CALL    SPMSG   ; GOT A "YES"
        DB      LF,'YOUR ANSWER WAS "YES!"',0
        JMP     START2
START3: CALL    SPMSG
        DB      LF,'YOU SAID "NO!"',0
        JMP     START2

SINON:  DB      'YES AND NO PROGRAM',0,CR,LF

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

TWOCR:  CALL    CCRLF ; PRINTS TWO CARRIAGE RETURNS

; CARRIAGE RETURN AND LINEFEED TO CON:
CCRLF:  MVI     A,CR
        CALL    CO
        MVI     A,LF
        CALL    CO
        RET

SPMSG:  XTHL               ; Get "RETURN ADDRESS" to HL
        XRA A              ; Clear flags and accumulator
        ADD M              ; Get one message character
        INX H              ; Point to the next character
        XTHL               ; Restore stack for return
        RZ                 ; Return if done (zero)
        CALL CO            ; Else display character
        JMP SPMSG          ; And do another

; Routine to get Yes or No from the console
GETYN:  CALL    SPMSG      ; Prompt for input
        DB      ' (Y/N)?: ', 0 ; Message
        CALL    CIMSG      ; Get input line
        CALL    CCRLF      ; Echo carriage return
        LDA     INBUF+2    ; First character only
        ANI     01011111B  ; Convert lower case to upper
        CPI     'Y'        ; Compare with 'Y'
        RZ                 ; Return with zero = YES
        CPI     'N'        ; Compare with 'N'
        JNZ     GETYN      ; Else try again
        CPI     0          ; Reset zero flag
        RET                ; And all done

; INPUT CONSOLE MESSAGE INTO THE BBUFFER USING THIS FUCNTION
CIMSG:  PUSH    B       ; START BY SAVING REGISTERS.
        PUSH    D
        PUSH    H
        LXI     H,INBUF+1 ; ZERO CHARACTER COUNTER
        MVI     M,0
        DCX     H       ; DECREMENTS THE INDEX REGISTER PAIR.
        MVI     M,80
        XCHG            ; SEND INBUFF POINTER TO DE REGISTERS
        MVI     C,RBUFF ; SET UP READ BUFFER FUNCTION
        CALL    BDOS    ; INPUT A LINE
        LXI     H,INBUF+1 ; GET THE CHARACTER COUNTER
        MOV     E,M
        MVI     D,0
        DAD     D
        INX     H
        MVI     M,0
        POP     H
        POP     D
        POP     B
        RET

; PRINT MESSAGE TO THE CONSOLE IN ROT13
COMSG:  MOV     A,M     ; RETRIEVE ONE CHARACTER
        ORA     A       ; ZERO IS THE TERMINATOR CHARACTER
        RZ              ; RETURN OUT OF THE FUNCTION ON ZERO
        CALL    CO      ; OTHERWISE, OUTPUT THE CHARACTER.
        INX     H       ; INCREMENT INDEX REGISTER
        JMP     COMSG   ; KEEP GOING

INBUF:  DS      83      ; LINE INPUT BUFFER
        CALL    CCRLF   ; ADD CR, LF
        JMP     START2  ; KEEP GOING

; SET UP STACK SPACE AT THE END OF PROGRAM
        DS      64      ; 40H LOCATIONS (64 IN DEC)
STAK:   DB      0       ; TOP OF STACK

        END
