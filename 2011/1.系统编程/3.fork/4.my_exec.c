/*************************************************************************
	> File Name: 4.my_exec.c
	> Author: 
	> Mail: 
	> Created Time: Sat 27 Mar 2021 03:18:35 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int opt, m_flag = 0;
    char msg[512] = {0};
    while((opt = getopt(argc, argv, "m:")) != -1) {
        switch(opt) {
            case 'm':
                printf("have m!\n");
                m_flag = 1;
                strcpy(msg, optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -m msg\n", argv[0]);
                exit(1);
        }
    }
    if(m_flag == 1) {
        printf("msg = %s\n", msg);
        return 0;
    }
    pid_t pid;
    if((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if(pid == 0) {
        printf("We will open a Vim\n");
        sleep(1);
        execl("/usr/bin/vim", "vim", "tmp.txt", NULL);
    } else {
        pid_t pid1;
        wait(NULL);
        printf("Vim is Out!\n");
        if((pid1 = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if(pid1 == 0) {
            sleep(1);
            printf("Cat will be do!\n");
            sleep(1);
            execlp("cat", "cat", "tmp.txt", NULL);
        } else {
            wait(NULL);
            printf("Cat is Over!\nDelete tmp.txt in 2s!\n");
            sleep(1);
            execlp("rm", "rm", "./tmp.txt", NULL);
        }
    }
    return 0;
}
