# Two's Complement: How Computers Represent Integers

Representing positive numbers in binary is quite obvious, but what about negative numbers? What is different and how can that information be used for most calculations?

Computers represent negative integers using a concept called **Two's Complement**.

First, let's go over how to get the two's complement negative notation of an integer. Say we're trying to find the two's complement of 47:

1. Write the number in binary: 47 &rarr; `0010 1111`

2. Invert the digits (0s become 1s, 1s become 0s): `0010 1111` &rarr; `1101 0000`

3. Lastly, add 1: `1101 0000` &rarr; `1101 0001`

Therefore, `1101 0001` is -47 in binary.

But isn't that just 209 in binary? Well, there is one way to prove that it's -47:

If `1101 0001` = -47, that would mean that adding 57 to it would give us 10. Let's try that:

```txt
    111    1  Carry Row
    0011 1001 (57)
+   1101 0001 (-47)
——————————————
    0000 1010
```

Because we are working with only 8 bits, similar to the *Altair 8800*, The last carried bit falls off. Hence, the result is `0000 1010`, the binary equivalent of 10! Ain't that clever?

We can see another example of this in 200 + (-100):

100 = `0110 0100`

-100 = `1001 1100`

200 = `1100 1000`

```txt
      11      Carry Row
    1100 1000 (200)
+   1001 1100 (-100)
——————————————
    0110 0100
```

`0110 0100` = 100.

This is actually how subtraction works in binary; we just add negative numbers.

Two's complement also works the other way. Let's take -47 from earlier for example, which is `1101 0001` in binary. Taking the negative of this should give us 47. Let's try doing that:

1. Invert the bits: `1101 0001` &rarr; `0010 1110`
2. Add 1: `0010 1110` &rarr; `0010 1111`

As stated before, `0010 1111` = 47.

Two's complement is most helpful when computers [subtract numbers](Subtract_two_numbers.md).
