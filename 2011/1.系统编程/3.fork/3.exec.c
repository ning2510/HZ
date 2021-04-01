/*************************************************************************
	> File Name: 3.exec.c
	> Author: 
	> Mail: 
	> Created Time: Sat 27 Mar 2021 03:08:15 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    if((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if(pid == 0) {
        printf("I'm Child!\nI'm do a great job now!\n");
        execlp("cat", "cat", "3.exec.c", NULL);
        printf("I'm die!\n");
    } else {
        printf("I'm Father!\n");
        wait(NULL);
    }
    return 0;
}
