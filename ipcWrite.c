#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdlib.h>

int main() {
    void *ptr;
    int n;

    int id = shmget(1111, sizeof(int), IPC_CREAT | 0666);
    if (id == -1) {
        printf("\nError in creating/accessing Shared Memory !!!\n");
        return 1;
    }

    ptr = shmat(id, NULL, 0);
    if (ptr == (void *)-1) {
        printf("\nError in attaching Shared Memory !!!\n");
        return 1;
    }

    printf("\nEnter the Number\t:\t");
    scanf("%d", &n);
    sprintf(ptr, "%d", n);

    printf("\nValue written to shared memory: %d\n", n);

    shmdt(ptr);

    return 0;
}