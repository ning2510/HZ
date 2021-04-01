/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Sat 27 Mar 2021 04:08:37 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int age;
    char name[20] = {0};
    if(argc != 3) {
        fprintf(stderr, "Usage : %s name age!\n", argv[0]);
        exit(1);
    }
    strcpy(name, argv[1]);
    age = atoi(argv[2]);
    printf("argv[0] = %s\n", argv[0]);
    printf("%s is %d years old!\n", name, age);
    return 0;
}
