# How to Subtract Two Numbers on the *ALTAIR 8800*

This program will retrieve two numbers from memory, subtract them, and store the result in another memory slot.

This program will be very similar to the [adding two numbers](../Add_two_numbers/Add_two_numbers.md) program, in that it will follow the same instructions:

0. `LDA`
1. `MOV` (A &rarr; B)
2. `LDA`
3. `ADD` (A + B)
4. `STA`
5. `JMP`

The exception here is that, before adding the two numbers, we will apply [two's complement](Twos_complement.md) to the second number.

For example, let's say we want to perform the subtraction **246 - 117**:

We can start be converting both numbers to binary:

246 = `1111 0110`

117 = `0111 0101`

Next, we have to convert 117 to -117 using two's complement:

1. Invert the bits: `0111 0101` &rarr; `1000 1010`
2. Add 1: `1000 1010` &rarr; `1000 1011`

Therefore, `1000 1011` = -117.

Next, we can just add these using code:
