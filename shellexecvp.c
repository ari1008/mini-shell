// base pour faire SON shell ;p
// gcc -g -Wall -Wextra -fanalyzer -pedantic shellexecvp.c -o shellexecvp


#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h>  // printf
#include <string.h>

#include <sys/wait.h> // wait
#include <sys/types.h> // pid_t
#include <unistd.h>    // fork

#include<time.h> //time

void historique(char * command,FILE * fichier){

    time_t t = time(NULL); /* t contient maintenant la date et l'heure courante */
    
    fprintf(fichier,"%s => %s\n",ctime(&t),command);
        

}

int main(int argc, char *argv[])
{

    pid_t pid;
    int status;
    FILE * fichier = NULL;
    
    fichier = fopen("historique.txt","a");

    //pour function historique
    char command[25]="";
    for (int i=1; i < argc; i++)
    {
        //printf("Argument %d : %s \n", i+1, argv[i]);
        strcat(command,argv[i]);
    }
    //printf("%s\n",command);

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
        if (execvp(argv[1],argv + 1)== -1)
            perror("execvp");

        return EXIT_FAILURE; //on termine le fils meme si execve fail 
        }
        //dans le pere 
        else{

            wait(&status);            
            historique(command,fichier);
            }      
    }
    fclose(fichier);
    //getchar();
    return EXIT_SUCCESS;
}