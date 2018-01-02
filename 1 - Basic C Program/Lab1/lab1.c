/*
 Developer : Warren Seto
 Lab       : 1
 */

#include <stdio.h>

/** Declare Function Prototype */
void outputPrimeFactor(int* input);

int main(int argc, const char * argv[])
{
    // Declare an integer to find its prime factors
    int num = 300;
    
    printf("The prime factorization of %i = ", num);
    
    // Call the outputPrimeFactor procedure with the address of the desired integer
    outputPrimeFactor(&num);
    
    printf("\n\n");
    
    return 0;
}

/** Displays the prime factors for a given integer input */
void outputPrimeFactor(int* input)
{
    // Counter variable to control the loops
    int count;
    
    //"For" loop for finding the prime factors
    for (count = 2; count <= (*input); count++) //This will count from 2 to the inputted number
    {
        while ((*input) % count == 0) //It will check if the inputted number and count is divisible, then loop the statement if is true
        {
            (*input) = (*input) / count; //This will divide the number by count
            
            if ((*input) / count >= 1) //This will add the time symbol, when the expression is greater to or equal to one
            {
                printf("%i x ", count);
            }
            
            else //If (num / count < 0) is true, then show the last number in the statement
            {
                printf("%i", count);
            }
        }
    }
}
