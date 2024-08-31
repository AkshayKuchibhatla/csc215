# E: The Octal System

Traditionally, the octal number system, which is base 8, contains digits 0 to 7. It serves a special purpose in the world of computing: condensation.

Because binary has only 2 symbols, it doesn't take a huge number to accumulate many 1s and 0s. For example, it takes at least 20 binary digits to represent a 7-digit decimal number. Octal, on the other hand, can be used to split a binary number into groups of 3 bits and represent each of those groups with one octal number.

3 bits of binary can represent the decimal numbers 0 to 7:

| Decimal | Binary |
| ----------- | ----------- |
| 0 | 000 |
| 1 | 001 |
| 2 | 010 |
| 3 | 011 |
| 4 | 100 |
| 5 | 101 |
| 6 | 110 |
| 7 | 111 |

Octal, as mentioned before, also has the digits 0 to 7.

So, let's say we want to represent the binary instruction `11101010` in octal. We can break this into groups of 3 starting from the right: `11 101 010`. Lastly, we can assign each of these binary numbers an octal equivalent:

| Octal | Binary |
| ----------- | ----------- |
| 3 | 11 |
| 5 | 101 |
| 2 | 010 |

Hence, `11101010` is `352` in octal. This is how condensation works.

The *Altair 8800* manual will present most binary instructions in octal for conciseness.
