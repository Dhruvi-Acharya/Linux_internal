#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{    
      int fd;
      char buffer[1024]="Hello";
      fd = creat("file3.txt",777); // creating file

      write(fd,buffer,1024); // writing content

      lseek(fd,4096,SEEK_CUR); //allocating extra 4K bytes

      write(fd,buffer,1024);

      return 0;
}
/*
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    char random_garbage[1024]; 
    int fd = -1;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd < 0) {
        perror("Can't open file: ");
        return 2;
    }
    write(fd, random_garbage, 1024);
    lseek(fd, 2048, SEEK_CUR);
    write(fd, random_garbage, 1024);
    close(fd);
    return 0;
    
    }*/