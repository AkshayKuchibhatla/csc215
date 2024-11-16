# Console Input and output

This program from chapter 12 of *CP/M Assembly Language Programming* by Ken Barbier shows how to recieve input and output to a console in 8080 assembly language. 

The program will recieve console input from the user in the form of a single character. Then, it will echo that character, or print it again.

To accomplish this, the program will implement **two subroutines**:

1. **CI:** Short for **C**onsole **I**nput, CI reads a character from the terminal and puts it in the (A) register.
2. **CO:** Short for **C**onsole **O**utput, CO writes the character in the (A) register to the terminal.

Both functions run through the same steps:

1. They push the contents of the working registers to the stack, so as to save them.
2. They move the corresponding primitive BDOS function into the (C) register. For CI, this would be `RCONF`, or **R**ead **Con**sole **F**unction and for CO this would be `WCONF` or **W**rite to **Con**sole function.
3. Jump to BDOS using CALL and the location. This executes the function stored in the (C) register.
4. Pop the contents of the working registers back off the stack so that conditions are restored to the exact same as before subroutine was called.

These two functions work together to create the program.

The functions differ in one way, though: While CI processes the value receieved *after* calling BDOS by masking the high-order bit, CO processes the value *before* calling BDOS by moving it from the accumulator to the (E) register.

