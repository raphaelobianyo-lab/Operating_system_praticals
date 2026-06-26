#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_THREADS 10
int counter=0; sem_t semaphore;
void* increment_counter(void* a){sem_wait(&semaphore);counter++;sem_post(&semaphore);return NULL;}
int main(){pthread_t threads[NUM_THREADS];sem_init(&semaphore,0,1);
for(int i=0;i<NUM_THREADS;i++) pthread_create(&threads[i],NULL,increment_counter,NULL);
for(int i=0;i<NUM_THREADS;i++) pthread_join(threads[i],NULL);
printf("Final Counter Value = %d\n",counter);sem_destroy(&semaphore);return 0;}