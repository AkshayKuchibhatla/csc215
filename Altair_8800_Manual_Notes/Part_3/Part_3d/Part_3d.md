# D: Memory Addressing

There are many methods of addressing the memory of the *Altair 8800*. They are described below.

## Direct Addressing

Supplies the specified memory address in the form of two bytes immediately following the byte storing the instruction.

## Register Pair Addressing

- The contents of a register pair in the CPU can contain a memory address.
- Most instructions use the `H` and `L` registers for this purpose.
- The `H` stands for **high** and contains the more significant 8 bits, while the `L` stands for low and contains the least significant 8 bits.
- The two instructions `STAX` and `LDAX` permit the `B` and `C` or `D` and `E` register pairs to contain memory addresses.

## Stack Pointer Addressing

- The programmer *must* reserve the stack location in memory by loading a memory address into the Stack Pointer.
- This can be done via the `LXI` instruction.
- The programmer should always make note of the stack's address on his memory map.
- In Part 4, the `PUSH` and `POP` stack operations will be covered in depth.

## Immediate Addressing

- Immediate instructions contain data which is loaded into memory during program loading.
- The data is loaded with the program sequentially; therefore, it is stored in the exact memory block reserved for programming.
- As a result, the programmer does not need to alter the memory map when loading immediate data.

## Stack Addressing of Subroutines

- When a subroutine is CALLed by a program, the address of the next sequential instruction in the program is automatically saved by being PUSHed onto the stack.
- When the subroutine has finished executing, a RETURN instruction POPs the address from the stack and the main program continues execution.
