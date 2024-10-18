# Write a basic file in ED: follow-along

This is a follow-along tutorial on how to open a basic file in ED and write some text in it.

## Initialization

1. First, start CP/M. You should be on the `A:` disk to begin with.

2. Type the command `DIR` and press enter to view all of the items in the `A:` disk.

3. Among the entries, you should see `ED.COM`, which is shown in the format `ED       COM` on CP/M. This entry tells us that the transient program of ED is stored in the `A:` disk.
**NOTE:** *If you do not see ED on the `A:` disk, try navigating to the using the commands `B:`, `C:`, and typing `DIR` in them to see if ED is stored in those places.*

4. Now, in the `A:` disk, type the command `ED THIS.TXT`. You should see the following appear under your command:

```txt

NEW FILE
*|

```

>*The "`|`" character represents where your cursor should be.*

You have successfully initialized ED and created a file called THIS.TXT.

## Editing

Now, it's time to put some text in the file.

The `*` character is ED's prompt for commands.

When you first open ED, you are in command mode. To enter insert mode, type `I` and press enter. You should see the following:

```txt

NEW FILE
*I
|
```

Enter the following characters here: `ABCD`. Then, press enter and write `EFGH`. Then press enter and write `IJKL`. Continue this process until the last two letters `YZ`. Finally, press enter one more time.

Press `CTRL+Z` to exit insert mode (for mac users, that's the actual CONTROL key, not command + Z).

After doing all of this, you should see the following:

```txt

NEW FILE
*I
ABCD
EFGH
IJKL
LMNO
PQRST
UVWX
YZ
*|
```

## Viewing text

Now that you're back in command mode, write the command `B` and press enter.

The `B` command stands for "beginning", and moves the character pointer to the beginning of the file. The **character pointer** is the place where text is inputed into the file when you go into input mode. It's like the location of your cursor in normal typing. The thing is, when you finish typing up your file, the character pointer is all the way at the end, as shown below:

```txt

NEW FILE
*I
ABCD
EFGH
IJKL
LMNO
PQRST
UVWX
YZ▵
```

> *The character pointer is denoted by the "`▵`" symbol.*

The `B` command moves the character pointer all the way to before the first letter of the first line, as shown below:

```txt

NEW FILE
*I
▵ABCD
 EFGH
 IJKL
 LMNO
 PQRST
 UVWX
 YZ
```

> *Keep in mind that the character pointer is invisible, and thus it's up to the programmer to keep track of where it is. There are, however, some commands you can use to find where the cursor is, as we will cover later.*

Now type the command `#T`. This will display all of the characters of the file stored in the buffer from the character pointer. You should see the following when you type this command:

```txt
*#T     
ABCD
EFGH
IJKL
LMNOP
PQRST
UVWX
YZ
*|
```

## Saving and exiting

So, you've openned a new file and you've put text in it. Now it's time to save and exit! Enter the `E` command and press enter. The `E` command completes all of the saving actions described [in the introdution](Ed_Intro.md) (in the section titled "finalizing changes") and exits ED. When you execute this command, you should see the following:

```txt
*E

A>|
```

> *Now that the user has exited ED, CP/M has resumed the `>` prompt from before.*
