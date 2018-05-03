#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> //contains atoi function: Its prototype is as follows: int atoi(const char *str); The str argument is a string, represented by an array of characters, containing the characters of a signed integer number.
#include <string.h> //You can get the length of a string using the strlen function. This function is declared in the header file string.h.
#include <ctype.h> //The ctype.h header file of the C Standard Library declares several functions that are useful for testing and mapping characters -- isalpha; islower, isupper

int main(int argc, string argv[]) //argc stands for "argument count"; argc contains the number of arguments passed to the program; argv stands for "argument vector". A vector is a one-dimensional array, and argv is a one-dimensional array of strings.
{
    //Declare variables for shift and text
    string shiftKey; //string used to shift letters to the right in ciphertext
    string plainText; //string entered by the user

    //argc must equal 2 -- to run program, there can only be 2 arguments entered on command line - ./vigenere and shiftKey
    //argv is the 2nd argument and will be alphabet characters only -- entered as a string
    if(argc == 2) //checks for 2 arguments
    {
        shiftKey = argv[1]; //argv[1] is targeting the value of the 2nd argument on the command line, after ./vigenere
        //assigning the 2nd argument to the variable shiftKey
        int lenShiftKey = strlen(shiftKey); //declares variable for the length of shiftKey
        // printf("%s\n",shiftKey); //confirmed key is acting like an string

        //confirm that shiftKey string contains all alphabet characters only
        for(int i = 0; i < lenShiftKey; i++) //run check on all the characters in shiftKey string
        //initialze counter to 0 & assign the length of shiftKey to allAlphas variable
        {
            if(!isalpha(shiftKey[i]))//if a character in the shiftKey string is NOT an alphabet character
            {
                printf("Error! ONLY Alphabet Characters Accepted - Try Again\n");//print error message
                return 1; //means error or anomaly
            }
        }

    if(argc != 2)//if argc does not equal 2; if there are not ONLY 2 arguments on the command line
    {
            printf("Error! There must be ONE WORD after ./vigenere\n"); //print error message
            return 1; //means error or anomaly
    }

    //Input from user - 1st line: plaintext: User input
    plainText = get_string("plaintext: ");
    // printf("%s\n", plainText);

    // // //Ciphered text - 2nd line: ciphertext: cipheredText
    printf("ciphertext: ");


    //For each element of plaintext - the entire length of plaintext, confirm if each element is an alphabet character; if so, add the shiftKey
    //ciphertext = (ith character in plaintext + shiftKey) mod 26
    for (int i = 0, textLength = strlen(plainText), index = 0; i < textLength; i++)
    {
        if (isalpha(plainText[i])) //check if plaintext[i] is an alphabet character
        {
            if (isupper(plainText[i])) //check if each character is uppercase; print uppercase chars
            {
                ////preserve upper case
                //  if isupper(prompt[i])
                //  {
                //       printf("%c", (((plainText[i] + key[loop]) - 'A') % 26) + 'A');
                //  }
                printf("%c", ((plainText[i] - 'A') + (toupper(shiftKey[index]) - 'A')) % 26 + 'A');

                //CAESAR Logic
                //from ASCII to AlphaIndex conversion values: plainText + shiftKey - 65 (A = 65, to bring to 0 based index, subtract char 'A')
                //int upperConvertToIndex = plainText[i] + shiftKey - 65;
                //convert AlphaIndex to CipheredText -- (Ith index letter % 26 + 65(then add the ASCII back at the end)
                //int newCipheredUpperText = upperConvertToIndex % 26 + 65; //modulo + 65 to generate the newly shifted ascii values	        }
	        else if (islower(plainText[i])) //check if each character in plaintext is lowercase
	        {
	            printf("%c", ((plainText[i] - 'a') + (tolower(shiftKey[index]) - 'a')) % 26 + 'a');
	            ////preserve lower case
                //  else if islower(plainText[i])
                // {
                //      printf("%c", (((plainText[i] + key[loop]) - 'a') % 26 ) + 'a');
                // }

	            //CAESAR Logic
	            //converts lowerChars with key shift to ascii to alpha to ascii
	            //from ASCII to AlphaIndex conversion values: plainText + shiftKey - 97 (a = 97, to bring to 0 based index, subtract 97)
                //int lowerConvertToIndex = plainText[i] + shiftKey - 97;
                //convert AlphaIndex to CipheredText -- Ith index letter % 26 + 97(then add the ASCII back at the end)
                //int newCipheredLowerText = lowerConvertToIndex % 26 + 97; //modulo + 97 to generate the newly shifted ascii values
	        }

            index = (index + 1) % lenShiftKey; //runs through length of the shiftKey characters; and loops back to the beginning - 0 indexed

            }

        else
        {
            printf("%c", plainText[i]); //if not an alphabet, upper or lower case, just print the character in the Ith position
        }
    }
    printf("\n"); //creates new line after cipherText prints
  }
  else
  {
    printf("Usage: ./vigenere k\n");//per specs, this is the output that is displayed when no <1 or >2 arguments are present
    exit(1); //means EXIT_FAILURE -- check50 did not want return 1 used
  }
  exit(0); //means EXIT_SUCCESS -- check50 did not want return 0 used
}
