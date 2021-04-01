/*************************************************************************
	> File Name: 3.multi_thread_add.c
	> Author: 
	> Mail: 
	> Created Time: Mon 29 Mar 2021 11:41:43 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int now = 1, ans;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *sum() {
    while(1) {
        pthread_mutex_lock(&mutex);
        if(now > 1000) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        //printf("%d\n", now);
        ans += now++;
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t tid[5];
    for(int i = 0; i < 5; i++) {
        pthread_create(&tid[i], NULL, sum, NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(tid[i], NULL);
    }
    printf("%d\n", ans);
    return 0;
}
