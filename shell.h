#ifndef _SHELL_
#define _SHELL_
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>

/* Base Functions */
char **vect(char *str, char *delim, ssize_t n);
char *argToString(char **args);
void freeArray(char **arr);
char *pathFind(char **env);
char *execPath(char *PATH, char *cmd);
void newProcess(char *pathExec, char **args, char **env);
void apndCmd(char *buffer, char *cmd);
char *createPath(char **path, char *buffer, char *cmd);
void sigHandle(int n);
void parse(char **array, char **env);
void error(int status);
int nfError(int status);
void cdError(int status);

/* Built-ins */
int builtins(char *cmd);
void cd(char *cmd, char *path);
void exitShell(char *buffer);
void envBuilt(char *cmd, char **env);
void envBuilt(char *cmd, char **env);

/* helper_functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);
int _putchar(char c);


/* GLOBALS */
/**
 * struct global - GLobal values
 * @count: global line count
 * @exit: Global exit status
 * @name: Program name
 * @cmd: Command
 * @arg: First argument
 *
 * Description: Keeps track of global values
 */
struct global
{
	int count;
	int exit;
	char *name;
	char *cmd;
	char *arg;
} globals;

/**
 * struct flag - flags for the system
 * @interactive: checks for interactive mode
 *
 * Description: Flags for the system
 */
struct flag
{
	bool interactive;
} flags;

#endif /* _SHELL_ */
