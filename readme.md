# MyShell Project

## CRN: 74025  
### Group 9

#### Group Members:  
- Nathaniel Kebere (100868890)  
- Anuj Shukla (100895219)  
- Syed Mesam Jafri (100869437)  
- Farzad Shahdad (100861389)  
- Danial Shaikh (100698628)  

---

## Overview

This project implements a simple shell in C that mimics basic UNIX shell functionalities. It allows users to execute commands such as `cd`, `clr`, `dir`, `echo`, and more. The shell is interactive and supports batch processing. The program can process both built-in commands and external commands, launching them as separate processes when needed.

---

## Key Features

- **Built-in Commands**: 
  - `cd`: Change the current working directory.
  - `clr`: Clear the terminal screen.
  - `dir`: List contents of a directory.
  - `environ`: Display the environment variables.
  - `echo`: Display a message or comment to the screen.
  - `help`: Show the help manual.
  - `pause`: Pause the shell until the user presses Enter.
  - `quit`: Exit the shell.

- **External Command Execution**: 
  - Supports executing external commands using `execvp` after forking a new process.
  - The shell waits for child processes to finish using `waitpid`.

- **Batch File Execution**: 
  - If a batch file is provided as a command-line argument, the shell will read and execute commands from the batch file line by line.

---

## How to Use

1. **Interactive Mode**:  
   When running the shell without arguments, it will display a prompt (`MyShell>`), allowing the user to enter commands interactively. Each command will be processed when the user presses Enter.

2. **Batch Mode**:  
   You can also execute a batch file by providing the file name as an argument:
   ```bash
   ./myshell batchfile.txt

## Key Features
1. cd <directory>
Changes the current working directory to the specified <directory>. If no directory is specified, it uses the user's home directory by default.

Example:

MyShell> cd /home/user

2. clr
Clears the screen of the terminal, providing a clean space for further commands.

Example:

MyShell> clr

3. dir <directory>
Lists the contents of the specified <directory>. If no directory is specified, it will list the contents of the current working directory.

Example:

MyShell> dir /home/user

4. environ
Displays a list of all the environment variables currently set in the shell.

Example:

MyShell> environ

5. echo <comment>
Displays the specified comment or message to the screen. Multiple spaces or tabs are reduced to a single space.

Example:

MyShell> echo Hello, World!

6. help
Displays the help manual, providing instructions and explanations on how to use the shell.

Example:

MyShell> help

Within the help manual the "more" filter gives you additional features to use, you can use the following commands:
- "Down arrow" key: Reveal more
- "Up arrow" key: Go back up
- "q": Quit the help

7. pause
Pauses the shell and waits for the user to press Enter before continuing.

Example:

MyShell> pause

8. quit
Exits the shell program.

Example:

MyShell> quit

## Concepts for Beginners
1. I/O Redirection
I/O Redirection allows users to redirect input or output to and from files instead of standard input/output (keyboard and terminal). This is typically done using < for input redirection or > for output redirection.

Example of input redirection:

MyShell> command < input.txt
Example of output redirection:

MyShell> command > output.txt

2. Program Environment
The environment of a program refers to variables and settings that can affect the behavior of the program. Environment variables like PATH, HOME, and USER hold important information. The environ command in this shell will list all environment variables available to the program.

3. Background Execution
Background execution allows processes to run in the background while the terminal remains available for other commands. In this shell implementation, background execution is not explicitly supported by the code, but external commands can be executed in the background if implemented using the & operator (e.g., command &).

Additional Notes
The shell supports both built-in commands (like cd, clr, dir) and external commands that are executed via forking and using execvp.
The setenv function is used to set environment variables. This is useful when managing the shell's internal state.
execvp is used to run external commands by passing the arguments in a format that can be understood by the shell.
The waitpid function ensures that the parent shell waits for the child process to complete before allowing the user to enter another command.
