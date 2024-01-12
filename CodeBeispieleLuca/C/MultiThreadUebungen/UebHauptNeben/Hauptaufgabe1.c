#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int loops = 100;
static volatile int shared1, shared2;
static pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void neben()
{
    pthread_mutex_lock(&mutex2);
    shared2++;
    pthread_mutex_unlock(&mutex2);
}

void haupt()
{
    while (pthread_mutex_trylock(&mutex1))
        neben();

    shared1++;
    usleep(1000);
    pthread_mutex_unlock(&mutex1);
}

static void *start(void *arg)
{
    int n = *(int *)arg;
    for (int i = 0; i < n; i++)
    {
        haupt();
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, start, &loops);
    pthread_create(&t2, NULL, start, &loops);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Shared1: %d\n", shared1);
    printf("Shared2: %d\n", shared2);
    return EXIT_SUCCESS;
}
