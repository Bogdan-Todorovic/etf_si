#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t sem;

void * X (void *arg) {
    sleep(rand()%5);
    sem_post(&sem);
    printf("Uslov X ispunjen.\n");
    return 0;
}

void * Y (void *arg) {
    sleep(rand()%5+2);
    sem_post(&sem);
    printf("Uslov Y ispunjen.\n");
    return 0;
}

void * Z (void *arg) {
    sleep(rand()%5+1);
    sem_post(&sem);
    printf("Uslov Z ispunjen.\n");
    return 0;
}

void * P (void *arg) {
    sem_wait(&sem);
    sem_wait(&sem);
    sem_wait(&sem);

    sleep(1);
    printf("Uslov P sacekao i ispunjen je.\n");
    return 0;
}

int main() {

    // Nit P ceka X, Y, Z u bilo kom redosledu

    sem_init(&sem, 0, 0);
    pthread_t x, y, z, p;
    pthread_create(&x, 0, X, 0);
    pthread_create(&y, 0, Y, 0);
    pthread_create(&z, 0, Z, 0);
    pthread_create(&p, 0, P, 0);

    pthread_join(x, 0);
    pthread_join(y, 0);
    pthread_join(z, 0);
    pthread_join(p, 0);

    sem_close(&sem);
    printf("Kraj programa.");
    return 0;
}