/*
 Developer : Warren Seto
 Lab       : 2 - 3
 */

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int processID = fork();
    
    if (processID) // Parent Process
    {
        printf("Parent Process Started (%i) \n", processID);
        
        sleep(1000);

        printf("Parent Process Ended \n");
    }
    
    else // Child Process
    {
        printf("Child Process Started (%i) \n", processID);
        
        printf("Child Process Ended \n");
    }
    
    return 0;
}
