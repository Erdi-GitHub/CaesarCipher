# CaesarCipher
## A simple C++ application to [de]cipher any text using the [Caesar Cipher](https://en.wikipedia.org/wiki/Caesar_cipher)


# What's a Ceasar Cipher?
Better explained by [WikiPedia](https://en.wikipedia.org/wiki/Caesar_cipher), a Caesar Cipher (or shift cipher) is a simple [substitution cipher](https://en.wikipedia.org/wiki/Substitution_cipher) in which every letter in the supplied text is fixed a number of positions down the alphabet (the latin one in this case).

Plaintext may be shifted right or left, below are a few examples of ciphers you may use:

```
Right shift of 5
Plaintext:	ABCDEFGHIJKLMNOPQRSTUVWXYZ
Ciphertext:	FGHIJKLMNOPQRSTUVWXYZABCDE
```
```
Left shift of 1
Plaintext:	ABCDEFGHIJKLMNOPQRSTUVWXYZ
Ciphertext:	ZABCDEFGHIJKLMNOPQRSTUVWXY
```
```
Left shift of 15
Plaintext:	Hello, World!
Ciphertext:	Spwwz, Hzcwo!
```
# Installation
### ! A C++ compiler is required to build this application !
### Recommended compiler: g++
## Linux/UNIX-like
### Using GNU Makefile
You may install this application through the following commands:
```
chmod +x install.sh
./install.sh # or bash install.sh
```
### Without Makefile
You may build this application using the following command:
```
g++ src/main.cpp -o caesar
```
Afterward, you may move the output onto a directory in your `$PATH`, e.g. `/usr/bin`, `$HOME/.local/bin`, `/usr/local/bin`, etc:
```
mv caesar ~/.local/bin
```
## Windows
Refer to [this video](https://youtu.be/tg9BGzygClI) by [OttoBotCode](https://www.youtube.com/@OttoBotCode)
## Anything else
Research on how to build C++ applications using your operating system online (you may use a site like [StackOverflow](https://stackoverflow.com/)) and build `src/main.cpp`
# Usage
> This portion assumes you have this application in your run path as `caesar`!

## Command Arguments
The general syntax of `caesar` is the following:
```
          the shift value
		        |
               /        text to cipher - "must be surrounded in quotes"
              |                |
caesar [l|r] [shift (1-25)] ["text here"]
       |
    l is left shift,
	r is right shift
```
You may choose to leave out certain arguments, in which case `caesar` will ask you to specify them through terminal input:
```
Enter action: (r - [right cipher], l - [left cipher]) 
Enter shift: (1-25) 
Text to [de]cipher ({left|right} cipher): 
```
You may also pipe arguments into `caesar`, and pipe output out of it:
```
cat someFile.txt | caesar r 19 # Read input from someFile.txt and cipher it with a right shift of 19
```
```
caesar l 5 "The industrial revolution and its consequences..." | cat > otherFile.txt # write output into otherFile.txt
```
```
cat someFile.txt | caesar r 23 | cat > someFileCiphered.txt # Cipher a file
```
