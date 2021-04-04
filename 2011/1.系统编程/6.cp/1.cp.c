/*************************************************************************
	> File Name: 1.cp.c
	> Author: 
	> Mail: 
	> Created Time: Sun 04 Apr 2021 11:35:14 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFSIZE 512

int main(int argc, char *argv[]) {
    int fd_in, fd_out;
    ssize_t nread;
    char buf[BUFSIZE + 5] = {0};

    if(argc != 3) {
        printf("Usage: %s sourcefile destfile\n", argv[0]);
        exit(1);
    }

    if((fd_in = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(1);
    }

    if((fd_out = creat(argv[2], 0644)) == -1) {
        perror(argv[2]);
        exit(1);
    }

    while((nread = read(fd_in, buf, BUFSIZE)) > 0) {
        printf("nread = %d\n", nread);
        int nwrite;
        if((nwrite = write(fd_out, buf, strlen(buf))) != nread) {
            perror("write");
            exit(1);
        }
        memset(buf, 0, BUFSIZE + 5);
        printf("nwrite = %d\n", nwrite);
    }
    return 0;
}
