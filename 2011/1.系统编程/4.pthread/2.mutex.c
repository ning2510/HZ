/*************************************************************************
	> File Name: 2.mutex.c
	> Author: 
	> Mail: 
	> Created Time: Mon 29 Mar 2021 11:26:51 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int now;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *print() {
    while(1) {
        pthread_mutex_lock(&mutex);     // 加锁
        if(now >= 10000) {
            pthread_mutex_unlock(&mutex);  //解锁
            break;
        }
        now++;
        printf("%d\n", now);
        pthread_mutex_unlock(&mutex);  //解锁
    }
}

int main() {
    pthread_t tid[2];
    pthread_create(&tid[0], NULL, print, NULL);
    pthread_create(&tid[1], NULL, print, NULL);
    for(int i = 0; i < 2; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}
