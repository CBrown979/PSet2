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

//Specs
// Design and implement a program that encrypts messages using Vigenère’s cipher.

// Implement your program in a file called vigenere.c in a directory called vigenere.

// Your program must accept a single command-line argument: a keyword, k, composed entirely of alphabetical characters.

// If your program is executed without any command-line arguments, with more than one command-line argument, or with one command-line argument that contains any non-alphabetical character, your program should print an error (of your choice) and exit immediately, with main returning 1 (thereby signifying an error).

// Otherwise, your program must proceed to prompt the user for a string of plaintext, p, (as by a prompt for plaintext:) which it must then encrypt according to Vigenère’s cipher with k, ultimately printing the result (prepended with ciphertext: and ending with a newline) and exiting, with main returning 0.

// With respect to the characters in k, you must treat A and a as 0, B and b as 1, … , and Z and z as 25.

// Your program must only apply Vigenère’s cipher to a character in p if that character is a letter. All other characters (numbers, symbols, spaces, punctuation marks, etc.) must be outputted unchanged. Moreover, if your code is about to apply the jth character of k to the ith character of p, but the latter proves to be a non-alphabetical character, you must wait to apply that jth character of k to the next alphabetical character in p; you must not yet advance to the next character in k.

// Your program must preserve the case of each letter in p.