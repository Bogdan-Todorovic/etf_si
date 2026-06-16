#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Data {
    int x, y;
    sem_t semXY, semZ;
} Data;

void* A(void *arg) {
    Data* data = arg;
    int i = 0;
    while (i < 5) {
        sem_wait(&data->semZ);
        data->x = rand() % 100;
        data->y = rand() % 100;
        sem_post(&data->semXY);
        i++;
    }

    return 0;
}

void* B(void *arg) {
    Data *data = arg;
    int i = 0;
    while (i < 5) {
        sem_wait(&data->semXY);
        int z = data->x + data->y;
        sleep(1);
        printf("z = %d\n", z);
        sem_post(&data->semZ);
        i++;
    }
    return 0;
}

int main() {
    Data data;
    pthread_t threadA, threadB;

    if (sem_init(&data.semZ, 0, 0) || sem_init(&data.semXY, 0, 1))
        return -1;
    if (pthread_create(&threadA, 0, A, &data) || pthread_create(&threadB, 0, B, &data))
        return -2;

    pthread_join(threadA, 0);
    pthread_join(threadB, 0);

    sem_close(&data.semZ);
    sem_close(&data.semXY);

    printf("Kraj programa");
    return 0;
}