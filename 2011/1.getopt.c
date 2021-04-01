/*************************************************************************
	> File Name: 1.getopt.c
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Mar 2021 08:51:16 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//两种写法：int main(int argc, char *argv[])

int main(int argc, char **argv) {
    char c;
    char name[20] = {0};
    int age = 0;
    char sex[5] = {0};
    char title[512] = {0};
    while((c = getopt(argc, argv, "n:a:s:t::")) != -1) {
        switch(c) {
            case 'n':
                strcpy(name, optarg);
                break;
            case 'a':
                age = atoi(optarg);
                break;
            case 's':
                strcpy(sex, optarg);
                break;
            case 't':
                strcpy(title, optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s -n name -s sex -a age -t title!\n", argv[0]);
                exit(1);
        }
    }
    printf("%s is %d years old, %s, with title %s!\n", name, age, sex, title);
    return 0;
}
