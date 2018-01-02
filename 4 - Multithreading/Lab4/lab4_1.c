/*
 Developer : Warren Seto
 Lab       : 4 - 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>


/* Struct that holds an array of integers and the size of the array */
typedef struct Array {
    int length;
    int* values;
} IntArray;


/* Global variables that hold computed statistical data */
float r_min, r_avg, r_max, r_med, r_sd;


/* Function Prototypes */
void* findMin (void* inputStruct);
void* findAverage(void* inputStruct);
void* findMax(void* inputStruct);
void* findMed(void* inputStruct);
void* findSD(void* inputStruct);


/* Main function */
int main(int argc, const char * argv[])
{
    // STEP 1 : Offset the input arguments to only get the input numbers
    argv++;
    argc--;

    
    // STEP 2 : Early exit if the user did not input numbers
    if (!argc) {
        printf("No numbers entered. Please enter numbers to calculate statistical values.\n");
        return 0;
    }
    
    
    // STEP 3 : Convert each inputted numbers into an array of Integers and then into a Struct
    int count, tempArray[argc];
    
    for (count = 0; count < argc; count++)
    {
        tempArray[count] = atoi(argv[count]);
    }
    
    IntArray input = { .length = argc, .values = tempArray };
    
    
    // STEP 4 : Create 5 threads to compute statistical data
    pthread_t threads[5];
    
    pthread_create (&threads[0], 0, findMin, &input);
    pthread_create (&threads[1], 0, findAverage, &input);
    pthread_create (&threads[2], 0, findMax, &input);
    pthread_create (&threads[3], 0, findMed, &input);
    
    // STEP 5 : Wait for all threads to finish before executing
    pthread_join (threads[0], NULL);
    pthread_join (threads[1], NULL);
    pthread_join (threads[2], NULL);
    pthread_join (threads[3], NULL);
    pthread_join (threads[4], NULL);
    
    // STEP 6 : Output the global variables that hold the resulting statistical data
    printf ("Average = %f\n", r_avg);
    printf ("Minimum = %f\n", r_min);
    printf ("Maximum = %f\n", r_max);
    printf ("Median = %f\n", r_med);
    printf ("Standard Deviation = %f\n\n", r_sd);
    
    return 0;
}

/* Function that finds the minimum value given an int array that is in a struct */
void* findMin (void* inputStruct)
{
    r_min = ((IntArray*)inputStruct)->values[0];
    
    int count;
    for (count = 0; count < ((IntArray*)inputStruct)->length; count++)
    {
        if (r_min > ((IntArray*)inputStruct)->values[count])
            r_min = ((IntArray*)inputStruct)->values[count];
    }
    
    pthread_exit(0);
}


/* Function that finds the average value given an int array that is in a struct */
void* findAverage(void* inputStruct)
{
    int count, size = ((IntArray*)inputStruct)->length;
    
    for (count = 0; count < size; count++)
    {
        r_avg += ((IntArray*)inputStruct)->values[count];
    }
    
    r_avg /= size;
    
    pthread_exit(0);
}


/* Function that finds the maximum value given an int array that is in a struct */
void* findMax(void* inputStruct)
{
    r_max = ((IntArray*)inputStruct)->values[0];
    
    int count;
    for (count = 0; count < ((IntArray*)inputStruct)->length; count++)
    {
        if (r_max < ((IntArray*)inputStruct)->values[count])
            r_max = ((IntArray*)inputStruct)->values[count];
    }
    
    pthread_exit(0);
}


/* Function that finds the median given an int array that is in a struct */
void* findMed(void* inputStruct)
{
    int count, count2, size = ((IntArray*)inputStruct)->length, tempArray[size];
    
    for (count = 0; count < size; count++)
    {
        tempArray[count] = ((IntArray*)inputStruct)->values[count];
    }
    
    float temp;
    for (count = 0; count < size - 1; count++)
    {
        for (count2 = count + 1; count2 < size; count2++)
        {
            if (tempArray[count2] < tempArray[count])
            {
                temp = tempArray[count];
                tempArray[count] = tempArray[count2];
                tempArray[count2] = temp;
            }
        }
    }
    
    r_med = size % 2 ? tempArray[size / 2] : ((tempArray[size / 2] + tempArray[size / 2 - 1]) / 2.0);
    
    pthread_exit(0);
}


/* Function that finds the standard deviation given an int array that is in a struct. (With float precision) */
void* findSD(void* inputStruct)
{
    float sum = 0.0, mean, standardDeviation = 0.0;
    
    int count, size = ((IntArray*)inputStruct)->length;
    
    for (count = 0; count < size; count++)
    {
        sum += ((IntArray*)inputStruct)->values[count];
    }
    
    mean = sum/size;
    
    for (count = 0; count < size; count++)
    {
        standardDeviation += pow(((IntArray*)inputStruct)->values[count] - mean, 2);
    }
    
    r_sd = sqrt(standardDeviation / size);
    
    pthread_exit(0);
}

