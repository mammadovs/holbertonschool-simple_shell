# Simple UNIX Shell

## Description

This project is a simple UNIX command line interpreter written in C.

It:
- Displays a prompt
- Executes commands without arguments
- Uses execve system call
- Handles EOF (Ctrl+D)
- Prints errors like /bin/sh
- Does not support pipes, redirections or arguments

## Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Usage

./hsh

## Requirements

- Ubuntu 20.04 LTS
- Betty style
- No memory leaks
- Max 5 functions per file
