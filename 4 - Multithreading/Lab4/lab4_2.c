/*
 Developer : Warren Seto
 Lab       : 4 - 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The number of random points that should be generated (hundred million)
#define NUMBER_OF_GENERATED_POINTS 100000000

// The radius of the circle
#define CIRCLE_RADIUS 1

// Function prototype
void* computeRandomPoints (void* input);


// Global variable that stores the number of generated points in a given circle
int pointsInCircle = 0;


/* Main function */
int main(int argc, const char * argv[])
{
    // STEP 1 : Create a thread to
    pthread_t thread;
    
    pthread_create (&thread, 0, computeRandomPoints, NULL);
    
    pthread_join (thread, NULL);
    
    
    // STEP 2 : Calculate and output the estimated value of Pi
    float estimatedPi = 4 * ((float)pointsInCircle / NUMBER_OF_GENERATED_POINTS);
    
    printf("The estimated value of Pi after generating %i points is %f\n", NUMBER_OF_GENERATED_POINTS, estimatedPi);
}


/* Function that determines that generates a number of points and yields the number of points that is within a given circle */
void* computeRandomPoints (void* input)
{
    double x, y;
    
    int count;
    
    for (count = 0; count < NUMBER_OF_GENERATED_POINTS; count++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        
        if (((x * x) + (y * y)) <= CIRCLE_RADIUS) {
            pointsInCircle++;
        }
    }
    
    pthread_exit(0);
}
