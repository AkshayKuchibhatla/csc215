# How to Multiply two numbers on the *ALTAIR 8800*

## Paper and Pencil Method

Before we can multiply two numbers using the *ALTAIR*, let's do it on pencil and paper with binary:

Let's perform the multiplication **45 × 21**:

``` txt
        0010 1101 (45) (multiplicand)
      × 0001 0101 (21) (multiplier)
     —————————————
        00101101 (45 × 1)
       00000000  (45 × 0)
      00101101   (45 × 1)
     00000000    (45 × 0)
  + 00101101     (45 × 1)
  ———————————————
    001110110001 = 945
```

Notice how a group of partial products is calculated by multiplying the multiplicand by each bit of the multiplier. Each partial product is shifted over so the least significant bit is under its corresponding bit in the multiplier, then all the partial products are added. The question is: how would we take this and turn it into a computer algorithm?
