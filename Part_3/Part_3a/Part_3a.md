# A: The Front Panel Switches and LEDs

## 1. Front Panel Switches

### ON-OFF Switch

**ON** position: applies power to the computer.
**OFF** position: cuts power and erases the memory.

### STOP-RUN Switch

**STOP** position: stops program execution.
**RUN** position: implements program execution.

### SINGLE STEP Switch

Each time it's flipped, this switch executes one machine language instruction. Similar to stepping through lines of code using a debugger.

### EXAMINE-EXAMINE NEXT Switch

**EXAMINE** position: displays the contents of any specified memory address previously loaded into the **DATA/ADDRESS** Switches on the 8 data LEDs.
**EXAMINE NEXT** position: displays the contents of the *next sequential* memory address.

### DEPOSIT-DEPOSIT NEXT Switch

**DEPOSIT** position: causes the data byte loaded into the 8 **DATA** Switches to be loaded into the memory address which has been previously designated.
**DEPOSIT NEXT** position: loads the data byte loaded into the 8 **DATA** Switches into the next sequential memory address.
The data byte loaded into the 8 switches can be changed before flipping this switch.

### RESET-CLR Switch

**RESET** position: sets the Program Counter to the 1st memory address (0 000 000 000 000 000).
You can use this to return to the first step of a program which begins at the first memory address.

**ClR** position: The **CLEAR** command for external input and output devices.

### PROTECT-UNPROTECT Switch

**PROTECT** position: prevents memory contents from being changed.

**UNPROTECT** position: permits the contents of the memory to be altered.

### AUX Switches

The basic *Altair 8800* includes two **auxiliary switches** which are not yet connected to the computer. These switches will be used in unison with peripherals added to the basic machine.

A **peripheral device** is an external device that connects to a computer to expand its capabilities.

## 2. Indicator LEDs

| LED      | Definition |
| ----------- | ----------- |
| **ADDRESS**| LEDs designated **A15-A0**. The bit pattern shown on the **ADDRESS** LEDs denotes the memory address being examined or loaded with data.|
| **DATA**| LEDs designated **D7-D0**. The bit pattern on the **DATA** LEDs denotes the data in the specified memory address.|
|**INTE**|An **INTERRUPT** has been enabled when this LED is glowing.|
|**PROT**|The memory is **PROTECTED** when this LED is glowing.|
|**WAIT**|The CPU is in a **WAIT** stat when this LED is glowing.|
|**HLDA**|A **HOLD** has been **ACKNOWLEDGED** when this LED is glowing.|

## 3. Status LEDs

> **Note:** A glowing LED means that the status is acitve for the designated condition.

| LED      | Definition |
| ----------- | ----------- |
|**MEMR**|The memory bus is being used for reading memory data.|
|**INP**|The data bus is in input mode. Input data should be placed on the data bus when it is in input mode.|
|**M1**|The CPU is processing the first machine cycle of an instruction.|
|**OUT**|The address bus contains the address of an output device and the data bus will contain the output data when the CPU is ready.|
|**HLTA**|A **HALT** instruction has been executed and acknowledged.|
|**STACK**|The address bus holds the Stack Pointer's push-down stack address.|
|**WO**|Operation in the current machined cycle will be a **WRITE** memory or **OUTPUT** function. Otherwise, a **READ** memory or **INPUT** operation will occur.|
|**INT**|An **INTERRUPT** request has been acknowledged.|
