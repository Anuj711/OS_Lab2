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
        //If user enters "clr" command, it clears the screen
        else if (strcmp(token, "clr") == 0) 
        {
            token = strtok(NULL, delim);
            clear_screen();
        }
        //If user enters "dir <directory>" command, the contents of <directory> are displayed. If invalid directory passed, error message given
        else if (strcmp(token, "dir") == 0) 
        {
            // Get directory name
            token = strtok(NULL, delim); 
            list_directory(token);
        }
        //If user enters "environ" command, list all the envrionment strings
        else if (strcmp(token, "environ") == 0) 
        {
            list_environ();
        }
        //If user enters "echo <comment>" command, display the <comment> on the display followed by a new line
        //Mulitple spaces/tabs are reduced into a single space
        else if (strcmp(token, "echo") == 0) 
        {
            // Get rest of the input
            char *comment = strtok(NULL, ""); 
            echo_comment(comment);
        }
        //If user enters "help" command, display the help manual for the user and uses "more help.txt" to display the file one page at a time
        else if (strcmp(token, "help") == 0) 
        {
            display_help();
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