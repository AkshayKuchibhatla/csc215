# C: Using the Memory

- The *Altair 8800* is programmed in machine language.
- While programming in a higher-level language, the compiler automatically keeps track of memory addresses.
- When using machine language, on the other hand, the *programmer* must keep track of the memory.
- Failure to understand what's going on in the memory can result in program instruction and other valuable data being erased or overwritten.

- You can keep track of the *Altair 8800*'s memory contents using a technique called **memory mapping**.
- **memory mapping** involves breaking down the memory into blocks and assigning a type of data and a specific purpose to each of those blocks.

- For example, a normal memory map for the *Altair 8800* with **256 words of memory** might assign **programs to the first 100 words**, **subroutines to the second 100 words**, and **data to the remaining 56 words**.
- These blocks can be modified at will.
- the main purpose of memory mapping is to organize the available memory.

You can make a memory map each time you change the program in the *Altair 8800*. After the program is written, you can allocate memory space for the program itself, for subroutines (if there are any), and for data.
