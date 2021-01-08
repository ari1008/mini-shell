// base pour faire SON shell ;p
// gcc -g -Wall -Wextra -fanalyzer -pedantic mini-shell.c -o mini-shell


#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h>  // printf
#include <string.h>

#include <sys/wait.h> // wait
#include <sys/types.h> // pid_t
#include <unistd.h>    // fork

int main(int argc, char *argv[])
{
    pid_t pid;
    int status;
    //const char * separators = " ,.!"

    printf("My pid : %d\n",getpid()); 


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
        if (execvp(arg[1],argv + 1)== -1)
            perror("execvp");

        return EXIT_FAILURE; //on termine le fils meme si execve fail 
        }
        //dans le pere 
        else
            wait(&status);        
    }

    //getchar();
    return EXIT_SUCCESS;
}

