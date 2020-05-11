# Simple Shell

**NAME**

hsh - Holberton Simple Shell command interpreter (shell)


**SYNOPSIS**

**./hsh**

[command] [arguments ...]



**DESCRIPTION**

The **hsh** (Simple Shell) is an end of the trimester project for students at Holberton School of Software Engineering. The objective is to  write
a simple UNIX command interpreter that acts closely to **sh**



**Overview**

A  shell  is a command-line interpreter that provides a command line user

interf  ace. The shell we built is a simplified iteration  of  a  command

line  similar to **bash** or **dash.**  **Simple**  **Shell** can be used in both interac‐

tive and non-interactive mode. In interactive mode the prompt will have

()  around  the $ sign ($).  The first argument at argument [0] is under‐

stood by the shell to be a command. The shell will then run  that  com‐

mand  if  it  can be found and arguments after t  he first are treated as

modifiers or options.


## To Compile

    gcc -Wall -Werror -Wextra -pedantic *.c -o hsh



## Example
![from our article on "What happens when you type ls -l in shell?"](https://cdn-images-1.medium.com/max/1600/1*cbzMRGdaZJ--kRk1x64q3g.png)

Article from medium blog post [What happens when you type ls -l in shell](https://medium.com/p/7106fd783587/edit)
## Built-ins

 1. cd - changes current directory of the process.

 Syntax : `cd [DIRECTORY]`

 2. exit - to exit from the shell you type exit and press ENTER.

 3. env - prints the environment




## Contents of repository
|  Files| Description|
|--|--|
| path.c |Contains functions for finding and executing the path. Also appends the command to the path.  |
|hsh.c|Simple Shell|
|builtin.c|Contains built-ins for the shell. Function for the env built-in can be found in hsh.c|
|  error.c| Handles errors for the shell |
|helper_functions.c  | Contains helper functions that we built ourselves (strncmp, strcpy, strlen, etc) |
|shell.h|header file containing global varialbes|
| vect.c | Tokenizing function |






## Authors
Contributors to the Holberton Shell project
 - [Mark Hedgeland](https://github.com/zmbslyr/)  
   [Twitter](https://twitter.com/markhedgeland) [LinkedIn](https://linkedin.com/in/markhedgeland) [Personal Site](http://markhedgeland.tech)
 - [Mohameth Seck](https://github.com/SeckMohameth/)
