#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Data {
    int nums[2];
    int i;
    sem_t spaceAvailable, itemsAvailable, mutex;
} Data;

void * X (void *arg) {
    Data *data = arg;
    while (1) {
        sleep(rand()%5);
        sem_wait(&data->mutex);
        sem_wait(&data->spaceAvailable);

        data->nums[data->i] = rand() % 100;
        data->i = (data->i + 1) % 2;

        sem_post(&data->itemsAvailable);
        sem_post(&data->mutex);
        printf("X napravio broj\n");
    }
    return 0;
}

void * Y (void *arg) {
    Data *data = arg;
    while (1) {
        sleep((rand()%5) < 3? 5:10);
        sem_wait(&data->mutex);
        sem_wait(&data->spaceAvailable);

        data->nums[data->i] = rand() % 100;
        data->i = (data->i + 1) % 2;

        sem_post(&data->itemsAvailable);
        sem_post(&data->mutex);
        printf("Y napravio broj\n");
    }
    return 0;
}

void * Z (void *arg) {
    Data *data = arg;
    while (1) {
        sem_wait(&data->itemsAvailable);
        sem_wait(&data->itemsAvailable);
        sleep(1);
        int z = data->nums[0] + data->nums[1];
        printf("z = %d\n", z);

        sem_post(&data->spaceAvailable);
        sem_post(&data->spaceAvailable);
    }
    return 0;
}

int main() {
    Data data;
    data.i = 0;
    pthread_t x, y, z;

    sem_init(&data.spaceAvailable, 0, 2);
    sem_init(&data.itemsAvailable, 0, 0);
    sem_init(&data.mutex, 0, 1);

    pthread_create(&x, 0, X, &data);
    pthread_create(&y, 0, Y, &data);
    pthread_create(&z, 0, Z, &data);

    pthread_join(x, 0);
    pthread_join(y, 0);
    pthread_join(y, 0);

    return 0;
}
