/*************************************************************************
	> File Name: 2.winsize.c
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Mar 2021 10:48:58 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct winsize size;
    memset(&size, 0, sizeof(size));
    while(1) {
        sleep(1);
        if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
            perror("ioctl()");
            exit(1);
        }
        printf("col = %d\n", size.ws_col);
        printf("row = %d\n", size.ws_row);
    }
    return 0;
}
