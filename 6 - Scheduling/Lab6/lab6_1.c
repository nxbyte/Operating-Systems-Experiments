/*
 Developer : Warren Seto
 Lab       : 6 - 1
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    
    int n = atoi(argv[1]);
    int i, j;
    int count = 0;
    time_t begin = time(NULL);
    pid_t id = getpid();
    
    for(i = 1; i<= n; i++){
        for(j =2; j<i; j++){
            if(i%j == 0)
                break;
        }
        if(j == i){
            printf("%d ", j);
            count++;
        }
    }
    
    printf("\n");
    printf("* Process %d found %d primes within [1, %d] in %ld seconds\n", id, count, n, time(NULL)-begin);
    
    return 0;
}
