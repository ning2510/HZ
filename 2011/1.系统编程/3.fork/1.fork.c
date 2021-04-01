/*************************************************************************
	> File Name: 1.fork.c
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Mar 2021 02:17:41 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    printf("I'm Father! ");
    if((pid = fork()) < 0) {
        perror("fork");
        exit(1);    // return 1;
    }
    if(pid == 0) {
        printf("I'm child!\n");
    } else {
        sleep(1);
        printf("I'm parent!\n");
    }
    return 0;
}
