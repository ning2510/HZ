/*************************************************************************
	> File Name: 5.my_run.c
	> Author: 
	> Mail: 
	> Created Time: Sat 27 Mar 2021 03:48:40 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    char filename[512] = {0};
    char f_type[512] = {0};
    char b_name[512] = {0};
    char g_cmd[512] = {0};
    if(argc < 2) {
        fprintf(stderr, "Usage : %s filename.c arg...\n", argv[0]);
        exit(1);
    }
    strcpy(filename, argv[1]);
    char *sub;
    if((sub = strrchr(filename, '.')) == NULL) {
        // strrchr(filename, '.')  从字符串 filename 后面开始搜索第一个出现 '.' 的位置，如果没有返回 NULL
        fprintf(stderr, "Filename is not supported!\n");
        exit(2);
    }
    strncpy(b_name, filename, sub - filename);
    strcpy(f_type, sub);
    if(!strcmp(f_type, ".c")) {     // 如果文件后缀是 .c
        strcpy(g_cmd, "gcc");
    } else if(!strcmp(f_type, ".cpp")) {    // 如果文件后缀是 .cpp
        strcpy(g_cmd, "g++");
    } else {
        fprintf(stderr, "File type is not supported!\n");
        exit(2);
    }
    pid_t pid;
    if((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if(pid == 0) {
        execlp("vim", "vim", filename, NULL);
    }
    wait(NULL);
    if((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if(pid == 0) {
        execlp(g_cmd, g_cmd, filename, "-o", b_name, NULL);
    }
    int wstatus;
    wait(&wstatus);
    if(wstatus == 0) {
        printf("OK!\n");
        char tmp_name[512] = {0};
        sprintf(tmp_name, "./%s", b_name);
        /*
        *sprintf 指的是字符串格式化命令，函数声明为 int sprintf(char *string, char *format [,argument,...]);，主要功能是把格式化的数据写入某个字符串中，即发送格式化输出到 string 所指向的字符串。
        * */
        //printf("argv[1] = %s\n", *(argv + 1));
        execv(tmp_name, argv + 1);
    } else {
        printf("Failed!\n");
        exit(3);
    }
    return 0;
}
