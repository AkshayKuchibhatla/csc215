# Register Usage In the 8080

A **register** is a type of computer memory built into the CPU which is used for handling and manipulating data during the execution of instructions.

Although a processor can point to any one of the 64K bytes in the RAM, there are three reasons why we still want hardware registers:

1. **Speed**: Data in memory must be retrieved using a fetch opcode. Data in registers, on the other hand, can be operated on much faster as it is already in the CPU.
2. **Portability**: The standard 8080 registers remain a constant feature on any CP/M based computer.
3. **Multiple indexes**: Some data will have to be stored in memory in most programs; so, having many registers which can point to locations in memory simplifies programming tasks.

Having more programmer accessible hardware registers is always better. The 8080 chip provides enough registers for most tasks.

## Register organization and data paths

Along with knowing about the available registers, a programmer must also understand the *paths* that data follows between registers, the ALU, and everything outside the CPU chip.

### Registers within the CPU

|Register name|Register purpose|
|-----------|-----------|

- The **A register**, also known as the **accumulator**, provides one input to the **arithmetic/logic unit (ALU)**. The other input comes from the data bus.
