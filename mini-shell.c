// base pour faire SON shell ;p
// gcc -g -Wall -Wextra -pedantic mini-shell.c -o mini-shell


#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h>  // printf
#include <string.h>
#include <sys/types.h> // pid_t
#include <unistd.h>    // fork

int main(int argc, char *argv[])
{
    int i;
    char command[25]={};
    for (i=1; i < argc; i++)
    {
        printf("Argument %d : %s \n", i+1, argv[i]);
        strcat(command,argv[i]);
        strcat(command, " ");
    }
    printf("%s",command);
    system(command);
    getchar();
    return EXIT_SUCCESS;
}

