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
#include <dirent.h>

// Access environment variables
extern char **environ;

// Logic when the "cd command is inputed by user in shell
// Allows user to enter the desired path as input for the function
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

// Logic when the "clr" command is inputed by user in shell
void clear_screen()
{
    // ANSI escape sequence to clear screen
    printf("\033[H\033[J");
}

// Logic when the "dir <directory>" command is inputted by the user in shell
void list_directory(char *path)
{
    if (path == NULL)
    {
        // Default to current directory
        path = ".";
    }

    DIR *dir = opendir(path);
    if (dir == NULL)
    {
        perror("Error:");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

// Logic when the "environ" command is inputted by the user in shell
void list_environ()
{
    for (char **env = environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
}

// Logic when the "echo <comment>" command is inputted by the user in shell
void echo_comment(char *comment)
{
    if (comment == NULL)
    {
        // Just print a new line
        printf("\n");
        return;
    }

    int in_space = 0;
    while (*comment)
    {
        if (*comment == ' ' || *comment == '\t')
        {
            if (!in_space)
            {
                // Print only one space
                printf(" ");
                in_space = 1;
            }
        }
        else
        {
            printf("%c", *comment);
            in_space = 0;
        }
        comment++;
    }
    printf("\n");
}

// Logic when the "help" command is inputted by the user in shell
// Displays the help.txt file from the system
void display_help()
{
    system("more help.txt");
}

void pause_shell()
{
    printf("Press Enter to continue...\n");
    while (getchar() != '\n')
        ;
}