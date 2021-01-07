// base pour faire SON shell ;p
// gcc -g -Wall -Wextra -pedantic mini-shell.c -o mini-shell


#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h>  // printf
#include <string.h>

#include <sys/wait.h> // wait
#include <sys/types.h> // pid_t
#include <unistd.h>    // fork


int main(int argc, char *argv[],char *env[])
{
    pid_t   pid;
    int status;
    int i;
    char shell[25]="/bin/";
    char command[25]={};
    for (i=1; i < argc; i++)
    {
        printf("Argument %d : %s \n", i+1, argv[i]);
        strcat(command,argv[i]);
        strcat(command, " ");
    }
    printf("My pid : %d\n",getpid()); 
    printf("%s",command);

    //si il y a un argument
    if (argc > 1 )
    {

        if ((pid = fork())== -1)
        {
            perror("fork");
            return EXIT_FAILURE; 

        }
        //si pid = 0 alors on est dans le process fils
        else if (pid == 0)
        {

        strcat(shell,argv[1]);
        if (execve(shell, argv + 1,env )== -1)
            perror("execve");

        return EXIT_FAILURE; //on termine le fils meme si execve fail 
        }
        //dans le pere 
        else
            wait(&status);        
    }

    //system(command);
    getchar();
    return EXIT_SUCCESS;
}

