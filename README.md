# Installation

Set up using either WSL or a linux machine (like Ubuntu). Make sure to install the required compiler tools using following commands:
<br>
```
sudo apt-get update
sudo apt-get install make gcc-mips-linux-gnu
```

# Compilation

To compile, simply type "make" in the directory that contains the makefile.

# Inserting

To insert the compiled file into the rom, figure out the correct file within the ovlbanks. As a general guideline:

* ovlbank 3 -> Green Garden
* ovlbank 4 -> Blue Resort
* ovlbank 5 -> Red Mountain
* ovlbank 6 -> White Glacier
* ovlbank 7 -> Black Fortress
* ovlbank 8 -> Rainbow Palace

As for figuring out the submap itself, it boils down to: compare the first 0x20 bytes (or more) in RAM at 0x80043000 to the first 20 bytes of each file. If they match, you have the right file!

# Debugging

Whilst there is no easy way to just "debug" the C code itself, you can debug the raw asm within Project64. When making, the command line should spit out a ton of debug info (such as to which address everything compiled). You can easily use this information to place a breakpoint and see what the issue is.