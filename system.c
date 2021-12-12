#include<stdio.h>
#include<unistd.h>
#include<fcntl.h> 
#include<errno.h> 
#include<stdlib.h>
#include<string.h>
int main() 
{     
    int fd;
    int size;
    char* c=(char *)calloc(100,sizeof(char));
    char buff[40];
    //Creating a File
    fd = open("text.txt", O_RDONLY | O_CREAT); 
    printf("%d\n",fd);
    int clstat=close(3);
    printf("Status of close function %d of fd %d\n",clstat,fd);
    //Read system call
    fd = open("sample.txt", O_RDONLY);
    size = read(fd, c, 10);
    printf("Number of bytes written in file is %d\n",size);
    close(fd);
    //Write System Call
    fd=open("text1.txt",O_WRONLY | O_EXCL | O_TRUNC);
    size=write(fd,"Hello World to System Calls\n",strlen("Hello World to System Calls\n"));
    printf("fd is :%d\n",fd);
    printf("the number of bits written is %d\n",size);
    //Deleting using unlink
    fd = open("text.txt", O_RDONLY | O_CREAT);
    unlink("text.txt");
    //lseek system call
    

}