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


void execute_command(char *input) 
{
    char *token;
    char *delim = " \n";
    token = strtok(input, delim);
    if (token != NULL) 
    {
        //If user enters "cd" command they should be able to change the current working directory
        if (strcmp(token, "cd") == 0) 
        {
            token = strtok(NULL, delim); // Get next part (directory path)
            change_directory(token);
        }
        if (strcmp(token, "help") == 0) 
        {
            token = strtok(NULL, delim); // Get next part (directory path)
            change_directory(token);
        }
        else 
        {
            printf("Command not recognized.\n");
        }    
    }
}

int main() 
{
    char input[1024]; // Buffer for user input
    while (1) 
    {
        printf("MyShell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) 
        {
            break; // Exit on EOF    
        }
        execute_command(input); // Process the input
    }    
    return 0;
}