#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *threadCode(void *arg)
{
    int tid;
    tid = *((int *)arg);
    printf("Hello I am thread %d", tid);
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS], i;

    for (i=0; i<NUM_THREADS; i++)
    {
        thread_args[i] = i+1;
        printf("In main creating thread %d", i);
        pthread_create(&threads[i], NULL, threadCode, (void *) &thread_args[i]);
    }

   for (i=0; i<NUM_THREADS; i++)
   {
       pthread_join(threads[i], NULL);
   } 
   exit(0);

}


