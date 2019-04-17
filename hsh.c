#include "shell.h"

/**
 * main - Simple Shell
 * @argc: number of arguments
 * @argv: Arguments stored as string
 * @envp: Enviroment parameters
 *
 * Return: 0
 */
int main(int argc __attribute__((unused)),
	 char *argv[],
	 char *envp[])
{
	char *buffer = NULL, *path, *pathExec, *delim1 = "\t ";
	size_t bufSize = 0;
	ssize_t charCount;
	char **array = NULL;

	startup(argv);
	for (globals.count = 1; 1; globals.count++)
	{
		if (flags.interactive)
			write(STDERR_FILENO, "$ ", 2);
		charCount = getline(&buffer, &bufSize, stdin);
		if (charCount < 0)
			break;
		if (buffer[charCount - 1] == '\n')
			buffer[charCount - 1] = '\0';
		exitShell(buffer);
		array = vect(buffer, delim1,  charCount);
		globals.cmd = array[0];
		path = pathFind(envp);
		pathExec = execPath(path, array[0]);
		parse(array, envp);
		if (builtins(array[0]))
		{
			if (pathExec != NULL)
				newProcess(pathExec, array, envp);
			freeArray(array);
		}
		else
		{
			free(pathExec);
			freeArray(array);
		}
		free(pathExec);
	}
	if (charCount < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(buffer);
	return (globals.exit);
}

/**
 * newProcess - Creates a new process
 * @pathExec: Executable path
 * @args: Array of arguments given
 * @env: Array of env variables
 *
 * Return: void
 */
void newProcess(char *pathExec, char **args, char **env)
{
	pid_t newProcess;

	newProcess = fork();
	if (newProcess < 0)
		perror(args[0]);
	if (newProcess == 0)
	{
		execve(pathExec, args, env);
		nfError(errno);
		exit(globals.exit);
	}
	else
	{
		wait(&globals.exit);
		globals.exit = WEXITSTATUS(globals.exit);
	}
}
/**
 * builtins - checks if cmd is a built-in
 * @cmd: Command to check
 *
 * Return: 0 if built-in, 1 if not
 */
int builtins(char *cmd)
{
	char *built[4] = {
		"cd",
		".",
		"env",
		NULL
	};
	int index;

	for (index = 0; built[index] != NULL; index++)
	{
		if (cmd == NULL || _strcmp(cmd, built[index]) == 0)
			return (0);
	}
	return (1);
}
/**
 * envBuilt - Built-in: env
 * @cmd: Command to check against env
 * @env: Takes in env from main
 *
 * Return: void
 */
void envBuilt(char *cmd, char **env)
{
	char *envp = "env";
	int index = 0;

	if (_strcmp(cmd, envp) == 0)
	{
		while (env[index] != NULL)
		{
			write(1, env[index], _strlen(env[index]));
			write(1, "\n", 1);
			index++;
		}
	}
}

/**
 * parse - parses a string
 * @array: Token array
 * @env: Enviroment
 *
 * Return: void
 */
void parse(char **array, char **env)
{
	globals.arg = array[1];
	envBuilt(array[0], env);
	cd(array[0], array[1], env);
}
