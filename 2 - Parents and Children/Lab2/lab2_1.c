/*
 Developer : Warren Seto
 Lab       : 2 - 1
 */

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int value = 5;

int main()
{
    pid_t pid;
    pid = fork();
    
    if (pid == 0)
    {
        /* child process */
        value += 15;
        
        return 0;
    }
    else if (pid > 0)
    {
        /* parent process */
        
        wait(NULL);
        
        printf("PARENT: value = %d\n", value); /* Value is still 5 */
        
        return 0;
    }
}

/*
 In the child process the value should be 15.
 In the parent process the value should be 5.
 
 This is because when a child is created, it has its own instance of the variable 'value'
*/
