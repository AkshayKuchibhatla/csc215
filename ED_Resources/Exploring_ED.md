# Exploring basic functions of ED: follow-along

This tutorial will go over many of the basic commands you can use in ED to help with editing files. It will build off of the [previous tutorial](Write_a_File_in_ED.md) which discussed how to create a file, input text and save using ED.

## Starting off

First, start CP/M again. Then, at the `>` prompt symbol, type `DIR` to check the contents of the disk. You should see `THIS     TXT` among the entries from last time. You can view the contents of this file without opening ED by using the `TYPE` command. Write `TYPE THIS.TXT` and press enter. You should see this:

```txt
A>TYPE THIS.TXT
ABCD
EFGH
IJKL
MNOP
QRST
UVWX
YZ


A>|

```

## Opening the file

Now that we have confirmed that the file exists and the contents are intact, let's open it in ED. Type `ED THIS.TXT` and press enter. You should see ED open, which looks like this:

```txt
A>ED THIS.TXT
*|
```

>*Notice that the `NEW FILE` heading from the previous tutorial is not visible this time around.*

## Loading in text from the disk

Upon the previous command, ED has created a new buffer in RAM to view the file and except the changes that we make; however, the actual file data is still on the disk. We can see this when we type the `#T` command, which prints all text in the buffer starting from the character pointer. It should look like this:

```txt
*#T
*|
```

>*There is no text in the buffer, so this command prints nothing.*

We can load text into the buffer using the `nA` command. **The `nA` command (n is an integer) appends the next *n* unprocessed source lines from the source file to the end of the memory buffer.** For now, we'll just enter `A` to append one line from the source file. Then, type `B#T` to go to the beginning of the buffer and type it (yes, you can chain commands together. That's what makes ED so cool!).

```txt
*A
*B#T
ABCD
*|
```

We have appended one line. Now, let's try to get the entire file in here. To do this, enter the command `0A`. This command appends enough lines of the source file to fill up *half* of the buffer. Then, enter `B#T` again to view all the lines in the buffer:

```txt
*0A
*B#T
ABCD
EFGH
IJKL
MNOP
QRST
UVWX
YZ

*
```

## Moving around

Now that we have put the entire file inside the buffer, let's get a feel for moving around the character pointer.

In ED, enter the `T` command. This command types all the characters after the character pointer of the line on which the character pointer is. You should see the following output when you type this command:

```txt
ABCD
*|
```

This shows that the character pointer is at the beginning of the first line, as indicated below:

```txt
▵ABCD
 EFGH
 IJKL
 MNOP
 QRST
 UVWX
 YZ
```

### Switching lines

Now, type the command `1LT`, which means "Move down **1** **L**ine and **T**ype it." You should see this:

```txt
*1LT
EFGH
*|
```

>*The commands in this chapter all end with `T`, which types the current line which the character pointer is on. This is so you can see the line after you've switched lines or after you've moved around on the line.*
>
>*You do not have to include the T for the command to execute, but it just helps you see what is going on.*

The character pointer has now been moved down to the start of the second line, as indicated below:

```txt
 ABCD
▵EFGH
 IJKL
 MNOP
 QRST
 UVWX
 YZ
```

If we move back one line and then print the line using the command `-1LT`, we should get the same output as before:

```txt
*-1LT
ABCD
*|
```

This indicates that the character pointer is back where it started. This is how you move lines using ED.

### Moving around on one line

Now, move down three lines and type the line. You should see this:

```txt
*3LT
MNOP
*|
```

The character pointer is sitting at the beginning of the fourth line. Now, enter `CT`, which means "Move forward 1 **C**haracter and **T**ype it." This should output:

```txt
*CT
NOP
*|
```

The character pointer has now been moved forward by one character, and is in the position indicated below:

```txt
 ABCD
 EFGH
 IJKL
 M▵NOP
 QRST
 UVWX
 YZ
```

If we enter the same command again, we go one character further on the same line:

```txt
*CT  
OP
*|
```

> **CHARACTER POINTER POSITION:**
>
>```txt
> ABCD
> EFGH
> IJKL
> MN▵OP
> QRST
> UVWX
> YZ
>```

When moving multiple characters forward (or backward), we can use numbers and negative signs as part of the command (OR we could just write multiple C's):

```txt
*-2CT
MNOP
*CCCT
P
*|
```

While the `T` command usually types lines **starting from the character pointer**, the command `0T` types the line **from the start of the line UP TO the character pointer**. We can see this below:

```txt
*0T
MNO*|
```

## Deleting characters

The command `D` deletes characters in front of the character pointer. For example, go to the beginning with `B`, then go ahead one character and type the line. It should look like so:

```txt
*BCT
BCD
*
```

> **CHARACTER POINTER POSITION:**
>
>```txt
> A▵BCD
> EFGH
> IJKL
> MNOP
> QRST
> UVWX
> YZ
>```

Now, enter the command `D` to delete one character, then go to the beginning again and print the buffer.

```txt
*DB#T
ACD
EFGH
IJKL
MNOP
QRST
UVWX
YZ

*|
```

You can see that the character that was right in front of the pointer was deleted.

You can insert this back in with the following chained command:

```txt
*BCIB^ZB#T
ABCD
EFGH
IJKL
MNOP
QRST
UVWX
YZ

*|
```

This concludes the tutorial on the basic operations of ED.
