/*
CRN: 74025
Group 9
	
Group Member 1: Nathaniel Kebere (100868890)
Group Member 2: Anuj Shukla (100895219)
Group Member 3: Syed Mesam Jafri (100869437)
Group Member 4: Farzad Shahdad (100861389)
Group Member 5: Danial Shaikh (100698628)

*/

#ifndef MYSHELL_H
#define MYSHELL_H
#include <stdio.h> // Standard I/O functions
#include <stdlib.h> // Standard library for functions like malloc
#include <string.h> // String handling functions
#include <unistd.h> // Provides access to the POSIX operating system API

//Function declarations
void change_directory(char *path); // declaration of 'cd' function
void list_directory(char *path);  // declaration of 'dir' function
void list_environ();  // declaration of 'environ' function
void echo_comment(char *comment); // declaration of 'echo' function
void display_help(); // declaration of 'help' function

#endif