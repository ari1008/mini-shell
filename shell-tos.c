// base pour faire SON shell ;p
// gcc -g -Wall -Wextra -pedantic shell-tos.c -o shell-tos
#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h>  // printf
#include <string.h>

int main(int argc, char *argv[]){
    char command[40]="./mini-shell ";
    char argument[25]={};
    char  *result;
    do
    {
        printf("Donnez votre commande\n");
        strcpy(argument,"");
        strcpy(command,"./mini-shell ");
        fgets(argument,25,stdin);
        strcat(command,argument);
        result = strstr(command, "./mini-shell exit");
        if (result == NULL) {
            system(command);
        } else {
          break;
        }
    }
        while(1);
    return EXIT_SUCCESS;
}
