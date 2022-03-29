#include <stdio.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
   int fd, res;
   int pid_1;

   pid_1=fork();

   if(pid_1==0){

    printf("child process pid: %d\n",getpid());
    printf("parent process id: %d\n",getppid());

    char buff[60];

    fd = open("file.txt", O_CREAT | O_RDWR, 777);
    printf("The file descriptor returned is %d ", fd);
    read(fd, buff, 60);
    printf("data in file is: %s\n",buff);

    close(fd);
}

else{
    wait(NULL); // parent wait until child executed
    printf("parent waits until child exected\nparent process id: %d\n",getpid());
}

return 0;



}