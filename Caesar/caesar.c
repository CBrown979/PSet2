#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> //contains atoi function: Its prototype is as follows: int atoi(const char *str); The str argument is a string, represented by an array of characters, containing the characters of a signed integer number.
#include <ctype.h> //The ctype.h header file of the C Standard Library declares several functions that are useful for testing and mapping characters
#include <string.h> //You can get the length of a string using the strlen function. This function is declared in the header file string.h.

int main(int argc, string argv[]) //argc stands for "argument count"; argc contains the number of arguments passed to the program; argv stands for "argument vector". A vector is a one-dimensional array, and argv is a one-dimensional array of strings.
// int main ( int argc, char *argv[] ) //alternative for main found on stackOverflow for c9

{
    //Declare variables for shift and text
    int shiftKey; //number used to shift letters to the right in ciphertext
    // string plainText;

    //argc must equal 2 -- to run program, there can only be 2 arguments entered on command line - ./casear and shiftKey
    //argv is the 2nd argument, but is a number -- the number will be entered as a string, but needs to be converted to an integer (atoi)

    if(argc == 2)
    {
        shiftKey = atoi(argv[1]); //argv[1] is targeting the value of the 2nd argument on the command line, after ./caesar
        printf("%i + %i = %i\n",shiftKey,shiftKey,shiftKey+shiftKey);
    }
    else
    {
        printf("Error! Please enter a number after ./caesar\n");
    }



}

//CAESAR SPECS
// Design and implement a program, caesar, that encrypts messages using Caesar’s cipher.

// Implement your program in a file called caesar.c in a directory called caesar.

// Your program must accept a single command-line argument, a non-negative integer. Let’s call it k for the sake of discussion.

// If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.

// You can assume that, if a user does provide a command-line argument, it will be a non-negative integer (e.g., 1). No need to check that it’s indeed numeric.

// Do not assume that k will be less than or equal to 26. Your program should work for all non-negative integral values of k less than 231 - 26. In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for k that’s too big or almost too big to fit in an int. (Recall that an int can overflow.) But, even if k is greater than 26, alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if k is 27, A should not become [ even though [ is 27 positions away from A in ASCII, per asciichart.com; A should become B, since B is 27 positions away from A, provided you wrap around from Z to A.

// Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).

// Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext "rotated" by k positions; non-alphabetical characters should be outputted unchanged.

// Your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.

// After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.