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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to execute commands entered by the user
void execute_command(char *input)
{
    char *token;
    char *delim = " \n";          // Delimiters to split the input by space and newline
    token = strtok(input, delim); // Tokenize the input string

    if (token != NULL)
    {
        // If user enters "cd" command, they should be able to change the current working directory
        if (strcmp(token, "cd") == 0)
        {
            token = strtok(NULL, delim); // Get the next part of the input (directory path)
            change_directory(token);     // Call function to change directory
        }
        // If user enters "clr" command, it clears the terminal screen
        else if (strcmp(token, "clr") == 0)
        {
            token = strtok(NULL, delim); // Get next part (not needed for "clr")
            clear_screen();              // Call function to clear the terminal screen
        }
        // If user enters "dir <directory>" command, list the contents of the directory
        else if (strcmp(token, "dir") == 0)
        {
            // Get directory name
            token = strtok(NULL, delim);
            list_directory(token); // Call function to list the directory contents
        }
        // If user enters "environ" command, list all environment variables
        else if (strcmp(token, "environ") == 0)
        {
            list_environ(); // Call function to list all environment variables
        }
        // If user enters "echo <comment>" command, display the comment
        else if (strcmp(token, "echo") == 0)
        {
            // Get the comment after the "echo" command
            char *comment = strtok(NULL, "");
            echo_comment(comment); // Call function to display the comment
        }
        // If user enters "help" command, display the help manual
        else if (strcmp(token, "help") == 0)
        {
            display_help(); // Call function to display help
        }
        // If user enters "pause" command, pause the shell until the user presses Enter
        else if (strcmp(token, "pause") == 0)
        {
            pause_shell(); // Call function to pause the shell
        }
        // If user enters "quit" command, exit the shell program
        else if (strcmp(token, "quit") == 0)
        {
            exit(0); // Exit the program
        }
        else if (strcmp(token, "exit") == 0)
        {
            exit(0); // Exit the program
        }
        else
        {
            // If the command is not built-in, execute it as an external command
            pid_t pid = fork(); // Create a new process using fork

            if (pid < 0)
            {
                perror("Fork failed"); // Error if fork fails
            }
            else if (pid == 0)
            {
                // In the child process, set an environment variable to track the parent shell
                setenv("parent", getenv("shell"), 1);

                // Prepare arguments for execvp to execute the external command
                char *args[64];
                int i = 0;
                args[i++] = token;

                // Tokenize the remaining input into arguments for the command
                while ((token = strtok(NULL, delim)) != NULL)
                {
                    args[i++] = token;
                }
                args[i] = NULL; // Null-terminate the arguments list

                // Execute the external command
                execvp(args[0], args);

                perror("Command execution failed"); // If execvp fails, show an error
                exit(1);                            // Exit the child process with an error status
            }
            else
            {
                waitpid(pid, NULL, 0); // Parent process waits for the child process to finish
            }
        }
    }
}

void execute_command(char *input); // Ensure this function exists (forward declaration)

int main(int argc, char *argv[])
{
    char input[1024]; // Buffer for user input
    FILE *batchFile = NULL;

    char shell_path[1024];
    if (realpath(argv[0], shell_path))
    {
        setenv("shell", shell_path, 1);
    }

    // Check if a batch file is provided as a command-line argument
    if (argc > 1)
    {
        batchFile = fopen(argv[1], "r"); // Open the batch file for reading
        if (!batchFile)
        {
            perror("Error opening batch file"); // Error if the batch file can't be opened
            return 1;
        }
    }

    // Main loop to continuously accept and process user input
    while (1)
    {
        if (batchFile)
        {
            if (!fgets(input, sizeof(input), batchFile)) // Read from the batch file
            {
                break; // Exit loop if no more lines in batch file
            }
        }
        else
        {
            printf("MyShell> ");                     // Prompt for input if not in batch mode
            if (!fgets(input, sizeof(input), stdin)) // Read input from stdin (user)
            {
                break; // Exit loop if no input is provided
            }
        }

        input[strcspn(input, "\n")] = '\0'; // Remove newline character from input

        if (strlen(input) == 0)
        {
            continue; // Skip empty inputs
        }

        execute_command(input); // Call function to process the input
    }

    if (batchFile)
    {
        fclose(batchFile); // Close the batch file when done
    }

    return 0; // Return 0 indicating successful execution
}