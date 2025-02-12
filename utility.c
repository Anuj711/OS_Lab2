/*
CRN: 74025
Group 9
	
Group Member 1: Nathaniel Kebere (100868890)
Group Member 2: Anuj Shukla (100895219)
Group Member 3: Syed Mesam Jafri (100869437)
Group Member 4: Farzad Shahdad (100861389)
Group Member 5: Danial Shaikh (100698628)

*/

#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>

//Logic when the "cd command is inputed by user in shell
//Allows user to enter the desired path as input for the function
void change_directory(char *path) 
{
    if (path == NULL) 
    {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) 
        {
            printf("%s\n", cwd);
        } 
        else 
        {
            perror("getcwd() error");
        }    
    }
    else 
    {
        if (chdir(path) != 0) 
        {
            perror("myshell");
        }
    }
}

//Logic when the "clr" command is inputed by user in shell
void clear_screen()
{
    // ANSI escape sequence to clear screen
    printf("\033[H\033[J");  
}