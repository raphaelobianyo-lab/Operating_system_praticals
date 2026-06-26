#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 10
int counter=0; pthread_mutex_t mutex;
void* increment_with_mutex(void* arg){pthread_mutex_lock(&mutex);counter++;pthread_mutex_unlock(&mutex);return NULL;}
void* increment_without_mutex(void* arg){counter++;return NULL;}
int main(){pthread_t threads[NUM_THREADS];
printf("=== WITH MUTEX ===\n"); counter=0; pthread_mutex_init(&mutex,NULL);
for(int i=0;i<NUM_THREADS;i++) pthread_create(&threads[i],NULL,increment_with_mutex,NULL);
for(int i=0;i<NUM_THREADS;i++) pthread_join(threads[i],NULL);
printf("Final Counter = %d\n",counter); pthread_mutex_destroy(&mutex);
printf("\n=== WITHOUT MUTEX ===\n"); counter=0;
for(int i=0;i<NUM_THREADS;i++) pthread_create(&threads[i],NULL,increment_without_mutex,NULL);
for(int i=0;i<NUM_THREADS;i++) pthread_join(threads[i],NULL);
printf("Final Counter = %d\n",counter); return 0;}