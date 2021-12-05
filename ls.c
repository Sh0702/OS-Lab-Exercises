#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc,char *argv)
{
    struct *dirent d;
    DIR *dir = opendir('.');
    if(!dir)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    while(d = readdir(dir) != NULL)
        printf("%s\t",d->d_name);
    printf("Done");
    return 0;
}