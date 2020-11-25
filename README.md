# Simple_shell project - Holberton School - COHORTE 13 - NOVEMBER 2020

## Task description

Write a simple UNIX command interpreter.

## What is a shell

Simply put, the shell is a program that takes commands from the keyboard and gives them to the operating system to perform. In the old days, it was the only user interface available on a Unix-like system such as Linux. Nowadays, we have graphical user interfaces (GUIs) in addition to command line interfaces (CLIs) such as the shell.

On most Linux systems a program called bash (which stands for Bourne Again SHell, an enhanced version of the original Unix shell program, sh, written by Steve Bourne) acts as the shell program. Besides bash, there are other shell programs available for Linux systems.

## How to use

Then you can start inserting commands followed by an enter, as the examples below indicate

```
<3 ls -lah
<3 /bin/ls
<3 pwd
<3 mkdir hola
<3 cd hola
<3 cd ..
<3 rmdir hola
```
To finish using our shell, you must insert the command "exit"

```
<3 exit
```

## File contents
|   **File**   |   **Description**   |
| -------------- | --------------------- |
| main.c | The main function |
| holberton.h | Header file |
| functions.c | Functions generals |
| aux_funcs.c | String management |
| builts_int.c | Funcions built ints |
| ctrlc.c | Control c function |
| free_double.c | Free to double pointers |
| find_path.c | Looks for the PATH |
| AUTHORS | Creators |
| man_1_simple_shell | Manual |

## Libraries included in this project
- stdio.h
- string.h
- stdlib.h
- sys/types.h
- sys/wait.h
- sys/stat.h
- unistd.h

## Authors
Facundo Diaz and Cecilia Giudice

## Date
11/11/2020 start aaaa