/*
 Developer : Warren Seto
 Lab       : 5 - 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The number of worker threads
#define NUM_THREADS 1000

// The number of random points that should be generated (hundred million)
#define NUMBER_OF_GENERATED_POINTS 100000000

// The radius of the circle
#define CIRCLE_RADIUS 1

// Function prototype
void* computeRandomPoints (void* input);

// Global variable that stores the number of generated points in a given circle
int pointsInCircle = 0;

// Mutex used for locking/synchronizing threads
pthread_mutex_t lock;

/* Main function */
int main(int argc, const char * argv[])
{
    // STEP 1 : Create many threads to do the operation
    pthread_t thread[NUM_THREADS];
    
    pthread_mutex_init(&lock, NULL);
    
    int count;
    for (count = 0; count < NUM_THREADS; count++)
    {
        pthread_create (&thread[count], 0, computeRandomPoints, NULL);
    }
    
    for (count = 0; count < NUM_THREADS; count++)
    {
        pthread_join (thread[count], NULL);
    }
    
    // STEP 2 : Calculate and output the estimated value of Pi
    float estimatedPi = 4 * ((float)pointsInCircle / NUMBER_OF_GENERATED_POINTS);
    
    printf("The estimated value of Pi after generating %i points with %i threads is %f\n", NUMBER_OF_GENERATED_POINTS, NUM_THREADS, estimatedPi);
    
    pthread_mutex_destroy(&lock);
    
    return 0;
}


/* Function that determines that generates a number of points and yields the number of points that is within a given circle */
void* computeRandomPoints (void* input)
{
    double x, y;
    
    int count, tempCount = 0;
    
    for (count = 0; count < NUMBER_OF_GENERATED_POINTS / NUM_THREADS; count++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        
        if (((x * x) + (y * y)) <= CIRCLE_RADIUS) {
            tempCount++;
        }
    }
    pthread_mutex_lock(&lock);
	pointsInCircle += tempCount;
    pthread_mutex_unlock(&lock);
    
    pthread_exit(0);
}


/*
 Output:
 
 The estimated value of Pi after generating 100000000 points with 1000 threads is 3.133391
 */
