#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    int fd;
    fd = execl("/home/dhruvi/Linux_internal/day4/exectest_cmd_line","./exectest_cmd_line","aa","bb","cc",NULL);
    printf("fd: %d\n",fd); // not inherit fd 
}