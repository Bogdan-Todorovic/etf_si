#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x, y, z;
sem_t semXY, semZ;

void* A(void *arg) {
    int i = 0;
    while (i < 5) {
        // A ceka da se rezultat ispise pre nego sto promeni sadrzaj x i y
        sem_wait(&semZ);
        x = rand() % 100;
        y = rand() % 100;
        // Signalizira niti B da su vrednosti spremne za sabiranje
        sem_post(&semXY);
        i++;
    }
    return 0;
}

void* B(void *arg) {
    int i = 0;
    while (i < 5) {
        // Nit B ceka da A upise vrednosti u x i y
        sem_wait(&semXY);
        z = x + y;
        sleep(1);
        printf("z = %d\n", z);
        // Nit B obavestava A da je ispisao z i da je spreman za promenu x i y
        sem_post(&semZ);
        i++;
    }
    return 0;
}

int main() {
    pthread_t a, b;
    sem_init(&semXY, 0, 0);
    sem_init(&semZ, 0, 1);

    pthread_create(&a, 0, A, 0);
    pthread_create(&b, 0, B, 0);

    pthread_join(a, 0);
    pthread_join(b, 0);

    sem_close(&semXY);
    sem_close(&semZ);

    printf("Kraj programa");
    return 0;
}