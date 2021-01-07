// base pour faire SON shell ;p
// gcc -g -Wall -Wextra -pedantic mini-shell.c -o mini-shell


#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h>  // printf
#include <string.h>
#include <sys/types.h> // pid_t
#include <unistd.h>    // fork

int main(int argc, char *argv[],char *env[])
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

    if (argc>[1])
    {
        if (execve(argv[1], argv + 1,env )== -1)
        {
            perror("execve");
        }     
    }
    printf("My pid : %d\n",getpid()); 

    //system(command);
    getchar();
    return EXIT_SUCCESS;
}

