# Console Input and output

This program from chapter 12 of *CP/M Assembly Language Programming* by Ken Barbier shows how to recieve input and output to a console in 8080 assembly language. 

The program will recieve console input from the user in the form of a single character. Then, it will echo that character, or print it again.

To accomplish this, the program will implement **two subroutines**:

1. **CI:** Short for **C**onsole **I**nput, CI reads a character from the terminal and puts it in the (A) register.
2. **CO:** Short for **C**onsole **O**utput, CO writes the character in the (A) register to the terminal.

These two functions work together to create the program.

