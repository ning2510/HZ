/*************************************************************************
	> File Name: 1.pthread.c
	> Author: 
	> Mail: 
	> Created Time: Mon 29 Mar 2021 10:51:24 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct MyArg {
    char name[20];
    int age;
};

void *print(void *arg) {
    sleep(2);
    struct MyArg inarg = *(struct MyArg *)arg;
    printf("%s is %d years old!\n", inarg.name, inarg.age);
    sleep(2);
    printf("Thread Killed by others!\n");
}

int main() {
    pthread_t tid;
    while(1) {
        struct MyArg myarg;
        printf("Please input:\n");
        scanf("%d", &myarg.age);
        strcpy(myarg.name, "ccc");
        pthread_create(&tid, NULL, print, (void *)&myarg);
        pthread_detach(tid);
    }
    pthread_join(tid, NULL);  // 主线程阻塞，等待 tid 线程终止后再进行
    sleep(30);
    return 0;
}
