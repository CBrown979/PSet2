#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> //contains atoi function: Its prototype is as follows: int atoi(const char *str); The str argument is a string, represented by an array of characters, containing the characters of a signed integer number.
#include <ctype.h> //The ctype.h header file of the C Standard Library declares several functions that are useful for testing and mapping characters -- isalpha; islower, isupper
#include <string.h> //You can get the length of a string using the strlen function. This function is declared in the header file string.h.

int main(int argc, string argv[]) //argc stands for "argument count"; argc contains the number of arguments passed to the program; argv stands for "argument vector". A vector is a one-dimensional array, and argv is a one-dimensional array of strings.
// int main ( int argc, char *argv[] ) //alternative for main found on stackOverflow for c9

{
    //Declare variables for shift and text
    int shiftKey; //number used to shift letters to the right in ciphertext
    string plainText; //string entered by the user

    //argc must equal 2 -- to run program, there can only be 2 arguments entered on command line - ./casear and shiftKey
    //argv is the 2nd argument, but is a number -- the number will be entered as a string, but needs to be converted to an integer (atoi)
    if(argc == 2)
    {
        shiftKey = atoi(argv[1]); //argv[1] is targeting the value of the 2nd argument on the command line, after ./caesar
        // printf("%i + %i = %i\n",shiftKey,shiftKey,shiftKey+shiftKey); //confirmed the number entered is acting like an integer
    }
    else
    {
        printf("Error! Please enter a number after ./caesar\n"); //print statement if nothing is entered after ./caesar
        return 1; //means error or anomaly
    }

    //Input from user - 1st line: plaintext: User input
    plainText = get_string("plaintext: ");
    // printf("%s\n", plainText);

    // //Ciphered text - 2nd line: ciphertext: cipheredText
    printf("ciphertext: "); //previously had \n which was pushing cipheredText to next line in error - just deleted lol

    //For each letter of plaintext - the entire length of plaintext, add the shiftKey
    //ciphertext = (ith character in plaintext + shiftKey) mod 26
    for(int i = 0, textLength = strlen(plainText); i < textLength; i++)
    {
        //is the indexed space an alphabet character?; if so, is it upper or lowercase? Must preserve cases

        if(isalpha(plainText[i]) && isupper(plainText[i])) { //confirming if each character is an alphabet character && is uppercase
            // printf("%c\n", plainText[i]); //then printing each alphabet character letter of plainText
            //from ASCII to AlphaIndex conversion values: plainText + shiftKey - 65 (A = 65, to bring to 0 based index, subtract 65)
            int upperConvertToIndex = plainText[i] + shiftKey - 65;

            //convert AlphaIndex to CipheredText -- (Ith index letter % 26 + 65(then add the ASCII back at the end)
            int newCipheredUpperText = upperConvertToIndex % 26 + 65; //modulo + 65 to generate the newly shifted ascii values
            printf("%c", newCipheredUpperText); //print the new ASCII letter (+65)
        }
        // if(isupper(plainText[i])){ //checking if Ith character in plainText is uppercase
        //     printf("%c\n", plainText[i]);
        // }
        else if(isalpha(plainText[i]) && islower(plainText[i])){
            //from ASCII to AlphaIndex conversion values: plainText + shiftKey - 97 (a = 97, to bring to 0 based index, subtract 97)
            int lowerConvertToIndex = plainText[i] + shiftKey - 97;

            //convert AlphaIndex to CipheredText -- Ith index letter % 26 + 97(then add the ASCII back at the end)
            int newCipheredLowerText = lowerConvertToIndex % 26 + 97; //modulo + 97 to generate the newly shifted ascii values
            printf("%c", newCipheredLowerText); //prints newly shifted ascii values
        }
        else {
            printf("%c", plainText[i]); //if not an alphabet, upper or lower case, just print the character in the Ith position
        }

        // {
        //     printf("lowercase\n"); //currently prints this if ith character is not uppercase
        // }

    }
            printf("\n"); //creates new line after cipherText prints
            return 0; //means program ran successfully

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