#include <cs50.h>
#include <stdio.h>
#include <string.h> //You can get the length of a string using the strlen function. This function is declared in the header file string.h.
#include <ctype.h> //The ctype.h header file of the C Standard Library declares several functions that are useful for testing and mapping characters

// int main(int argc, char ** argv); //int main(int argc, string argv) does not work either

int main(void)
{
    string userName = get_string("What's Your Name: "); //declares data type string for variable named userName -- user name is the string entered by the user

    for (int initial = 0, sLength = strlen(userName); initial < sLength; initial++) //to loop over each element of the string - using variable called initial as the counter
    //initialize counter to 0, and obtain the length of userName to store value in sLength; 0 less than length of userName; increase counter by 1
    {
        if(initial == 0 && isalpha(userName[initial])) //checking the first position to make sure it's a letter
            {
                printf("%c", toupper(userName[initial])); //only prints the first (0th) letter as uppercase
            }

        //if there is a blank in the string[index], and the next string[index] is a letter
        else if(userName[initial] == ' ' && isalpha(userName[initial + 1]))
            {
                printf("%c", toupper(userName[initial + 1])); //print remaining first letters, after a blank, as an uppercase character
            }

    }

    printf("\n"); //print new line



}

//ToDos:
//Prompt user for name
    //get string
    //only accept letters and spaces; single space between letters entered
//Print
    //uppercase only - toupper


// Specification

// Design and implement a program, initials, that, given a person’s name, prints a person’s initials.

// Implement your program in a file called initials.c in a directory called initials.

// Your program should prompt a user for their name using get_string to obtain their name as a string.

// You may assume that the user’s input will contain only letters (uppercase and/or lowercase) plus single spaces between words. You don’t need to worry about names like Joseph Gordon-Levitt, Conan O’Brien, or David J. Malan!

// Your program should print the user’s initials (i.e., the first letter of each word in their name) with no spaces or periods, followed by a newline (\n).

// letters to be printed using toUpper no matter what case is entered by the user