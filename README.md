# simple_shell
15 day end of first trimester project for Holberton School - Cohort 13 - November 2020. 

## Description

This is a UNIX command line interpreter. It takes commands from the keyboard and gives them to the operating system to perform. In the old days, it was the only user interface available on a Unix-like system such as Linux. Nowadays, we have graphical user interfaces (GUIs) in addition to command line interfaces (CLIs) such as the shell.

On most Linux systems a program called bash (which stands for Bourne Again SHell, an enhanced version of the original Unix shell program, sh, written by Steve Bourne) acts as the shell program. Besides bash, there are other shell programs available for Linux systems.

Usage: ```simple_shell```

It:
Displays a prompt and waits for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. Arguments can be passed to programs.
If an executable cannot be found, prints an error message and displays the prompt again.
It can handle errors.
It also handles the “end of file” condition (Ctrl+D)
Handles the PATH
Handles the exit built-in, that exits the shell
Uses the env as a built-in, that prints the current environment
Handles Ctrl+C: the shell does not quit when the user inputs ^C
Handles the builtin command cd (cd [directory], cd .. and cd)

## Getting started

### Compilation
This shell is compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

### Usage
It works both in interactive mode:
```
$ ./hsh
(<3) /bin/ls
hsh main.c shell.c
(<3)
(<3) exit
$
```
```
And in non-interactive mode:
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Executable commands
Input commands followed by an enter. Some examples shown below:

```
<3 ls -lah
<3 /bin/ls
<3 pwd
<3 mkdir hola
<3 cd hola
<3 cd ..
<3 rmdir hola
```
To exit program:

```
<3 exit
```

## File manifest
|   **File**   |   **Description**   |
| -------------- | --------------------- |
| main.c | The main function |
| holberton.h | Header file |
| functions.c | General functions |
| aux_funcs.c | String management auxiliary functions |
| builts_ints.c | Built in management functions |
| ctrlc.c | Function to manage CTRL + C |
| _strlen.c | Find string length functions |
| find_path.c | Looks for the PATH |
| dir_check.c | Checks if directory exists |
| main.c | Entry point to the program |
| AUTHORS | Creators |
| man_1_simple_shell | Manual |
| README.md |

## Libraries included in this project
- stdio.h
- string.h
- stdlib.h
- sys/types.h
- sys/wait.h
- sys/stat.h
- unistd.h
- dirent.h

## Known bugs
None :)

## Restrictions
List of allowed functions and system calls:
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

## Authors
Soledad Frechou and Tadeo Grach

## Date
11/11/2020 Start - 25/11/2020 end