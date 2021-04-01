/*************************************************************************
	> File Name: 2.100_child.c
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Mar 2021 02:38:38 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int x;
    for(int i = 1; i <= 100; i++) {
        x = i;
        if((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if(pid == 0) break;
    }
    if(pid == 0) {
        printf("I'm %dth Child!\n", x);
        sleep(1);
    }
    else {
        for(int i = 1; i <= 100; i++) {
            int wstauts;
            pid_t rpid = wait(&wstauts);
            printf("Child %d returns with code %d\n", rpid, wstauts);
        }
    }
    return 0;
}
