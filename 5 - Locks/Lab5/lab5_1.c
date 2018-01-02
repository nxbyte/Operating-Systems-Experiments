/*
 Developer : Warren Seto
 Lab       : 5 - 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUF_SIZE 10

int buf[BUF_SIZE];

pthread_mutex_t lock;

void* producer(void* param)
{
    int i;
    
    pthread_mutex_lock(&lock); /* 1 */
    
    for (i = 0; i < BUF_SIZE; ++i) {
        buf[i] = i;
    }
    
    pthread_mutex_unlock(&lock); /* 1 */
    
    pthread_exit(0);
}

void* consumer(void* param)
{
    int i;
    
    pthread_mutex_lock(&lock); /* 1 */
    
    for (i = 0; i < BUF_SIZE; ++i) {
        printf("Buffer Index %d = %d\n", i, buf[i]);
    }
    
    pthread_mutex_unlock(&lock); /* 1 */
    
    pthread_exit(0);
}

int main(int argc, const char * argv[]) {

    pthread_t t_prod, t_cons;
    
    pthread_mutex_init(&lock, NULL); /* 1 */
    
    
    pthread_create(&t_prod, 0, producer, NULL);
    
    sleep(1);
    
    pthread_create(&t_cons, 0, consumer, NULL);
    
    pthread_join(t_prod, NULL);
    pthread_join(t_cons, NULL);

    
    pthread_mutex_destroy(&lock); /* 1 */

    return 0;
}


/*
 Results from output:
 
 Buffer Index 0 = 0
 Buffer Index 1 = 1
 Buffer Index 2 = 2
 Buffer Index 3 = 3
 Buffer Index 4 = 4
 Buffer Index 5 = 5
 Buffer Index 6 = 6
 Buffer Index 7 = 7
 Buffer Index 8 = 8
 Buffer Index 9 = 9
 */



