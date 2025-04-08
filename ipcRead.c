#include <stdio.h>
#include <sys/shm.h>
#include <stdlib.h>

int main() {
    void *ptr;
    int m, fact = 1;

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

    m = atoi((char *)ptr);
    printf("\nNumber read from Shared Memory\t: %d", m);

    for (int i = 1; i <= m; i++)
        fact *= i;

    printf("\nFactorial of %d\t\t\t: %d\n", m, fact);

    shmdt(ptr);
    return 0;
}