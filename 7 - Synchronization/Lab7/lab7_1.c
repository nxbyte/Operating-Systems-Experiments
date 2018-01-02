/*
 Developer : Warren Seto
 Lab       : 7 - 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// The amount of time the farmer takes to cross the bridge (sleep time)
#define MAX_CROSSING_TIME 5


// Struct that stores each FARMER's identification
typedef struct node
{
    int num; // Farmer Number
    int direction; // Where 0 is NORTH and 1 is SOUTH
} FARMER;


// Semaphore used for locking/synchronizing threads (starvation)
sem_t bridgeStatus;


// Friendly output to show the direction of the FARMER
const char* DirectionOutput[2] = {"North", "South"};


// Function prototypes
void* crossTheBridge (void* inputDriver);
void enterBridge(FARMER* inputFarmer);
void exitBridge(FARMER* inputFarmer);


/* Main function */
int main(int argc, const char * argv[])
{
    // Check if the input is correct
    if (argc < 2) {
        printf("Missing two numeric inputs. Please try again.\n");
        return 0;
    }
    
    // Shift the input arguments to have the input number be parsed
    argv++;
    
    int driverNum[2];
    int count, count2;
    
    // Parse the input numbers for North and South bound cars
    for (count = 0; count < argc - 1; count++)
    {
        driverNum[count] = atoi(argv[count]);
    }

    // Farmer structs that hold the drivers that will be crossing the road
    FARMER drivers[driverNum[0] + driverNum[1]];
    
    // Populate the Farmer structs
    int totalDrivers = 0;
    for (count = 0; count < 2; count++) {
        for (count2 = 0; count2 < driverNum[count]; count2++) {
            drivers[totalDrivers++] = (FARMER){ .num = count2, .direction = count };
        }
    }

    // Output to show the input from
    printf("* We have %i farmers from the north and %i from south *\n", driverNum[0], driverNum[1]);
    
    sem_init(&bridgeStatus, 0, 1);
    
    // One thread per FARMER
    pthread_t threads[totalDrivers];
    
    int tempTotal = totalDrivers;
    
    // Induce one thread per Farmer struct (driver) to cross the bridge
    while(tempTotal--) {
        pthread_create (&threads[tempTotal], 0, crossTheBridge, (void*) (drivers + tempTotal));
    }
    
    tempTotal = totalDrivers;
    
    while(tempTotal--) {
        pthread_join (threads[tempTotal], NULL);
    }

    sem_destroy(&bridgeStatus);
    
    printf("* All farmers passed *\n");
    
    return 0;
}

// Thread task function that calls: enter_bridge(), sleeps a random amount of time, and then calls exit_bridge()
void* crossTheBridge (void* inputDriver)
{
    /* About to enter the Bridge */
    FARMER* tempDriver = (FARMER*)inputDriver;
    printf("M1: %s farmer #%i is about to enter the bridge (%s)\n", DirectionOutput[tempDriver->direction], tempDriver->num, DirectionOutput[tempDriver->direction]);
    
    /* Entered and Passing the bridge */
    enterBridge(tempDriver);
    
    /* Finished passing the Bridge */
    exitBridge(tempDriver);
    
    /* Left the bridge */
    printf("M5: %s farmer #%i has left the bridge (%s)\n", DirectionOutput[tempDriver->direction], tempDriver->num, DirectionOutput[tempDriver->direction]);
    
    pthread_exit(0);
}

void enterBridge(FARMER* inputFarmer)
{
    sem_wait(&bridgeStatus);
    
    printf("M2: %s farmer #%i has entered the bridge (%s)\n", DirectionOutput[inputFarmer->direction], inputFarmer->num, DirectionOutput[inputFarmer->direction]);
    
    int randPassingTime = rand() % MAX_CROSSING_TIME; // Random amount of time to simulate passing

    printf(" M3: %s farmer #%i will pass the bridge in %i seconds \n", DirectionOutput[inputFarmer->direction], inputFarmer->num, randPassingTime);
    
    sleep(randPassingTime);
}

void exitBridge(FARMER* inputFarmer)
{
    printf(" M4: %s farmer #%i has finished passing the bridge\n", DirectionOutput[inputFarmer->direction], inputFarmer->num);
    
    sem_post(&bridgeStatus);
}

