#include "shell.h"

/**
 * cd - change user directory
 * @cmd: Command to check against cd
 * @path: Path to change to
 *
 * Return: void
 */
void cd(char *cmd, char *path)
{
	char *cd = "cd";
	int fd;

	if (cmd == NULL || _strcmp(cmd, cd) == 0)
	{
		if (cmd == NULL)
			return;
		if (path == NULL && cmd != NULL)
		{
			fd = chdir(getenv("HOME"));
		}
		else if (cmd != NULL)
		{
			fd = chdir(path);
			if (fd < 0)
				cdError(fd);
		}
	}
}

/**
 * sigHandle - handles signal for control c
 * @n: Integer
 *
 * Return: void
 */
void sigHandle(int n __attribute__((unused)))
{
	write(STDERR_FILENO, "\n($) ", 5);
}

/**
 * startup
 * @argv: argv from main
 *
 * Return - void
 */
void startup(char **argv)
{
	globals.error = ENOENT;
	globals.name = argv[0];
	globals.exit = 0;
	signal(SIGINT, sigHandle);
	if (isatty(STDOUT_FILENO) == 1 && isatty(STDIN_FILENO) == 1)
		flags.interactive = 1;
}

/**
 * exitShell - exits the shell
 * @buffer: Buffer to clean up
 *
 * Return: void
 */
void exitShell(char *buffer)
{
	char *ex = "exit";

	if (_strcmp(buffer, ex) == 0)
	{
		free(buffer);
		exit(globals.exit);
	}
}

/**
 * freeArray - frees any double pointer array
 * @arr: Array to be free'd
 *
 * Return: void
 */
void freeArray(char **arr)
{
	int index;

	if (arr == NULL)
		return;
	for (index = 0; arr[index] != NULL; index++)
		free(arr[index]);
	if (arr[index] == NULL)
		free(arr[index]);
	free(arr);
}
