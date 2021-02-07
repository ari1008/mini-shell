// base pour faire SON shell ;p
// gcc -g -Wall -Wextra -fanalyzer -pedantic shell-tos.c -o shell-tos
#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h>  // printf
#include <string.h>

int main(int argc, char *argv[]){
    char command[40]="./shellexecvp ";
    char argument[25]={};
    char  *result;
    do
    {
        printf("Shell-TOS=>\n");
        strcpy(argument,"");
        strcpy(command,"./shellexecvp ");
        fgets(argument,25,stdin);
        strcat(command,argument);
        result = strstr(command, "./shellexecvp exit");
        if (result == NULL) {
            system(command);
        } else {
          break;
        }
    }
        while(1);
    return EXIT_SUCCESS;
}
