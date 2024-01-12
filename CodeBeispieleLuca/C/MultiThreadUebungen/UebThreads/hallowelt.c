#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

void *start(void *number)
{
    int *t = (int *)number;                          
    printf("Hello World its me, thread #%d!\n", *t); 
    return EXIT_SUCCESS;
}

int main()
{
    pthread_t thread[NUM_THREADS];
    int tid[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
    {
        tid[i] = i;

        if (pthread_create(&thread[i], NULL, &start, (void *)(tid + i)))
        {
            perror("pthread_create()");
            exit(EXIT_FAILURE);
        }
    }
    usleep(1000);
    return EXIT_SUCCESS;
}
