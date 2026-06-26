#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) { perror("shmget"); return 1; }

    char *shared = (char *)shmat(shmid, NULL, 0);
    if (shared == (char *)-1) { perror("shmat"); return 1; }

    pid_t pid = fork();

    if (pid == 0) {
        sleep(1);
        printf("Child read: %s\n", shared);
        shmdt(shared);
        exit(0);
    } else {
        strcpy(shared, "Hello from Parent using Shared Memory!");
        printf("Parent wrote message.\n");
        wait(NULL);
        shmdt(shared);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}
