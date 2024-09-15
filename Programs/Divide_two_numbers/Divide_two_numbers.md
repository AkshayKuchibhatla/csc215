# How to Divide Two Numbers on the *ALTAIR 8800*

This program will take two numbers from memory, divide one by the other, then store the result in memory.

## Part 1: How Division Works

Just as multiplication is repeated addition at its core, division is repeated subtraction. The quotient of a dividend and divisor is the number of times that the divisor can consecutively be subtracted from the dividend without the result being a negative number.

For example, let's solve **72 ÷ 8** using repeated subtraction:

| # Subtraction | Subtraction | Difference |
| ----------- | ----------- | ----------- |
| 1   | 72 - 8 | 64 |
| 2   | 64 - 8 | 56 |
| 3   | 56 - 8 | 48 |
| 4   | 48 - 8 | 40 |
| 5   | 40 - 8 | 32 |
| 6   | 32 - 8 | 24 |
| 7   | 24 - 8 | 16 |
| 8   | 16 - 8 | 8  |
| 9   | 8 - 8  | 0 |

The reason that 72 ÷ 8 = 9 is because 8 can be subtracted from 72 nine consecutive times without the difference being negative. This is the essence of division.

## Part 2: Programming Division onto the *ALTAIR*

There are 4 steps to this program:

1. Store the divisor in one register and store the dividend in another register. Additionally, reserve one register for the quotient of the division.
2. Check if the dividend is greated than the divisor.
3. If it is, subtract the divisor from the dividend, increment the quotient register by 1 and repeat step 2. If it is not, move on to step 4.
4. Store the quotient and the remainder, which is what would be left of the dividend after the divisor has been subtracted from the from it enough times, in memory.

Here is the full program in mneumonics:

|Pneumonic|Description|Binary|Hex|
|-----------|-----------|--------|-------|
|`RESET`|Sets the program counter to the 1st memory address (00 000 000)|||
|`LDA`|Load the divisor from an address into the accumulator. In this case, the address is byte 40.|00 111 010|3a|
|(Address byte 1)|The **less significant** byte of the address in memory.|01 000 000|40|
|(Address byte 2)|The **more significant** byte of the address in memory.|00 000 000|00|
|`MOV`|Move the divisor from the accumulator to register `B`.|01 000 111|47|
|`LDA`|Load the dividend from an address into the accumulator. In this case, the address is byte 30.|00 111 010|3a|
|(Address byte 1)|The **less significant** byte of the address in memory.|00 110 000|30|
|(Address byte 2)|The **more significant** byte of the address in memory.|00 000 000|00|
|`CMP`|Compares the dividend in the accumulator with the divisor in register `B`.|10 111 000|B8|
|`JNC`|If the dividend is less than the divisor and division is no longer possible, the previous instruction would have made the carry bit would have been set to `0`. Therefore, there would be no carry and the program would have to jump to the `STA` instruction to end the program.|11 011 010|DA|
|(Address byte 1)|The **less significant** byte of the address which the program counter will jump to.|00 010 000|10|
|(Address byte 2)|The **more significant** byte of the address which the program counter will jump to.|00 000 000|00|
|`SUB`|Subtract the divisor in register `B` from the dividend in the accumulator.|10 010 000|90|
|`INR`|Increment the C register, which is the quotient register, after a subtraction.|00 001 100|0C|
|`JMP`|Jump back to the `CMP` instruction to continue the loop of division.|11 000 011 |C3|
|(Address byte 1)|The **less significant** byte of the address of the `CMP` instruction in memory.|00 000 111|07|
|(Address byte 2)|The **more significant** byte of the address of the `CMP` instruction in memory.|00 000 000|00|
|`STA`|Store the remainder in the accumulator to another address. In this case, the address is byte 51.|00 110 010|32|
|(Address byte 1)|The **less significant** byte of the address in memory.|01 010 001|51|
|(Address byte 2)|The **more significant** byte of the address in memory.|00 000 000|00|
|`MOV`|Move the quotient from the register `C` to the accumulator.|01 111 001|79|
|`STA`|Store the quotient in the accumulator to another address. In this case, the address is byte 50.|00 110 010|32|
|(Address byte 1)|The **less significant** byte of the address in memory.|01 010 000|50|
|(Address byte 2)|The **more significant** byte of the address in memory.|00 000 000|00|
|`HLT`|Halt the instruction pointer.|01 001 100|76|
