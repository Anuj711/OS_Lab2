/*
CRN: 74025
Group 9

Group Member 1: Nathaniel Kebere (100868890)
Group Member 2: Anuj Shukla (100895219)
Group Member 3: Syed Mesam Jafri (100869437)
Group Member 4: Farzad Shahdad (100861389)
Group Member 5: Danial Shaikh (100698628)




*/

#include <sys/types.h>
#include <sys/wait.h>
#include "myshell.h"

void execute_command(char *input)
{
    char *token;
    char *delim = " \n";
    token = strtok(input, delim);
    if (token != NULL)
    {
        // If user enters "cd" command they should be able to change the current working directory
        if (strcmp(token, "cd") == 0)
        {
            token = strtok(NULL, delim); // Get next part (directory path)
            change_directory(token);
        }
        // If user enters "clr" command, it clears the screen
        else if (strcmp(token, "clr") == 0)
        {
            token = strtok(NULL, delim);
            clear_screen();
        }
        // If user enters "dir <directory>" command, the contents of <directory> are displayed. If invalid directory passed, error message given
        else if (strcmp(token, "dir") == 0)
        {
            // Get directory name
            token = strtok(NULL, delim);
            list_directory(token);
        }
        // If user enters "environ" command, list all the envrionment strings
        else if (strcmp(token, "environ") == 0)
        {
            list_environ();
        }
        // If user enters "echo <comment>" command, display the <comment> on the display followed by a new line
        // Mulitple spaces/tabs are reduced into a single space
        else if (strcmp(token, "echo") == 0)
        {
            // Get rest of the input
            char *comment = strtok(NULL, "");
            echo_comment(comment);
        }
        // If user enters "help" command, display the help manual for the user and uses "more help.txt" to display the file one page at a time
        else if (strcmp(token, "help") == 0)
        {
            display_help();
        }
        else if (strcmp(token, "pause") == 0)
        {
            pause_shell();
        }
        else if (strcmp(token, "quit") == 0)
        {
            exit(0);
        }
        else
        {
            pid_t pid = fork();

            if (pid < 0)
            {
                perror("Fork failed");
            }
            else if (pid == 0)
            {
                setenv("parent", getenv("shell"), 1);

                char *args[64];
                int i = 0;
                args[i++] = token;

                while ((token = strtok(NULL, delim)) != NULL)
                {
                    args[i++] = token;
                }
                args[i] = NULL;

                // Execute the command
                execvp(args[0], args);

                perror("Command execution failed");
                exit(1);
            }
            else
            {
                waitpid(pid, NULL, 0);
            }
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_command(char *input); // Ensure this function exists

int main(int argc, char *argv[])
{
    char input[1024]; // Buffer for user input
    FILE *batchFile = NULL;

    // Check if a batch file is provided as an argument
    if (argc > 1)
    {
        batchFile = fopen(argv[1], "r");
        if (!batchFile)
        {
            perror("Error opening batch file");
            return 1;
        }
    }

    while (1)
    {
        if (batchFile)
        {
            if (!fgets(input, sizeof(input), batchFile))
            {
                break;
            }
            printf("Executing: %s", input);
        }
        else
        {
            printf("MyShell> ");
            if (!fgets(input, sizeof(input), stdin))
            {
                break;
            }
        }

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0)
        {
            continue;
        }

        execute_command(input);
    }

    if (batchFile)
    {
        fclose(batchFile);
    }

    return 0;
}
