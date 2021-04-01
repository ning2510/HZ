/*************************************************************************
	> File Name: cat.c
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Mar 2021 07:51:52 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// ./a.out -b -n file...
void cat_file(const char *);

int num = 0, b_flag = 0, n_flag = 0;

int main(int argc, char *argv[]) {
    char ch;
    while((ch = getopt(argc, argv, "bn")) != -1) {
        switch(ch) {
            case 'b':
                b_flag = 1;
                break;
            case 'n':
                n_flag = 1;
                break;
            default:
                fprintf(stderr, "Usage : %s [-b|-n] file\n", argv[0]);
                exit(1);
        }
    }
    for(int i = optind; i < argc; i++) {
        cat_file(argv[i]);
    }
    return 0;
}

void cat_file(const char *file) {
    FILE *fp;
    if((fp = fopen(file, "r")) == NULL) {
        perror(file);   // 出错时打印具体的错误信息
        exit(1);
    }
    char buff[1024] = {0};
    while(fgets(buff, sizeof(buff), fp) != NULL) {   // 光标放到 fgets 按 shift + k 可以查看 man 手册中 fgets 的用法
        if(!b_flag && !n_flag) {
            printf("%s", buff);
            continue;
        }
        if(buff[0] != '\n') {
            num++;
            printf("%d\t%s", num, buff);
        }
        else {
            if(n_flag == 1 && b_flag == 0) {
                num++;
                printf("%d\t\n", num);
            }
            else printf("\n");
        }

    }
    fclose(fp);
    return ;
}
