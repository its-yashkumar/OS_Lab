    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <errno.h>
    #include<unistd.h>
    #include <string.h>
    #include <sys/types.h>
    int main()
    {
        int c = 99, fd, sz;
        char *c1 = (char *)calloc(100, sizeof(char));
        while (c != 0)
        {
            printf("Enter Code: \n1. Create \n2. Open \n3. Close \n4. Write \n5. Read \n6.Unlink \n7. Lseek \n8. Exit\n");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
            fd = creat("file1.txt", 0777);
            printf("fd= %d\n", fd);
            close(fd);
            break;
            case 2:
            fd = open("file1.txt", O_RDONLY | O_CREAT, 0777);
            printf("fd = %d\n", fd);
            close(fd);
            break;
            case 3:
            close(fd);
            printf("fd = %d\n", fd);
            break;
            case 4:
            fd = open("file1.txt", O_WRONLY | O_CREAT, 0777);
            sz = write(fd, "Hi, Krishna\n", strlen("Hi, Krishna\n"));
            printf("sz = %d\n", sz);
            break;
            case 5:
            fd = open("file1.txt", O_RDONLY);
            sz = read(fd, c1, 10);
            printf("sz = %d\n", sz);
            printf("fd = %d\n", fd);
            c1[sz] = '\0';
            printf("%s\n", c1);
            close(fd);
            break;
            case 6:
            close(fd);
            sz = unlink("file1.txt");
            printf("sz = %d\n", sz);
            break;
            case 7:
            fd = open("file1.txt", O_RDONLY);
            sz = lseek(fd, -1, SEEK_END);
            int i;
            char s;
            printf("sz = %d\n", sz);
            for (i = sz; i > 0; i--)
            {
            lseek(fd, -1, 1);
            read(fd, &s, 1);
            printf("%c", s);
            lseek(fd, -1, 1);
            }
            read(fd, c1, 19);
            break;
            case 8:
            exit(0);
            default:
            break;
            }
        }
    return 0;
    }