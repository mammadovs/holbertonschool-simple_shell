# Simple UNIX Shell Project

## Description
This project is a simple implementation of a UNIX command line interpreter (shell) written in C. It was developed as part of the Holberton School curriculum to understand the inner workings of the shell, process management, and system calls.

The program follows a basic cycle: **Read** input from the user, **Parse** the command string, **Execute** the command using system calls, and **Repeat**.

## Features
* **Interactive Mode**: Displays a prompt (`$ `) and waits for the user to type commands.
* **Non-Interactive Mode**: Can process commands via pipes (e.g., `echo "ls" | ./hsh`).
* **PATH Search**: Automatically searches for the command in system directories defined in the `PATH` environment variable.
* **Built-in Commands**: Supports `exit` to terminate the shell and `env` to print current environment variables.
* **EOF Handling**: Correctly handles the `End-of-File` condition (`Ctrl+D`) to exit gracefully.
* **Error Handling**: Prints error messages in the same format as the standard `/bin/sh`.



## Compilation
The shell is compiled on Ubuntu 20.04 LTS using `gcc` with the following flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
