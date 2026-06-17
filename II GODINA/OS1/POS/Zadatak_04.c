#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t semA, semB, semC;

void * critical (void *arg) {
    int id = *(int*) arg;
    sem_wait(&semA);
    printf("Nit %d usla u sekciju A.\n", id);
    sleep(rand() % 5 + 1);

    sem_wait(&semB);
    printf("Nit %d usla u sekciju B.\n", id);
    sleep(rand() % 5 + 1);
    sem_post(&semB);

    sem_wait(&semC);
    printf("Nit %d usla u sekciju C.\n", id);
    sleep(rand() % 5 + 1);
    sem_post(&semC);

    sem_post(&semA);
    return 0;
}

int main() {
    sem_init(&semA, 0, 10);
    sem_init(&semB, 0, 1);
    sem_init(&semC, 0, 1);
    pthread_t threads[10];
    int ids[10];

    for (int i = 0; i < 10; i++) {
        ids[i] = i+1;
        pthread_create(&threads[i], 0, critical, &ids[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], 0);
    }

    printf("Kraj Programa.");
    return 0;
}