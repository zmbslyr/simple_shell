#include "shell.h"

/**
 * error - Handle errors for functions
 * @status: Errno status
 *
 * Return: void
 */
void error(int status)
{
	if (status == ENOTDIR)
	{
		write(STDERR_FILENO, globals.name, _strlen(globals.name));
		write(STDERR_FILENO, ": ", 2);
		if (globals.count > 9 && globals.count < 100)
			_putchar((globals.count / 10) + '0');
		_putchar((globals.count % 10) + '0');
		write(STDERR_FILENO, ": ", 2);
		perror(globals.cmd);
		globals.exit = 127;
	}
}

/**
 * nfError - Not found error handler
 * @status: status of errno
 *
 * Return: void
 */
void nfError(int status)
{
	if (status == ENOENT || status == ENOTDIR)
	{
		if (status == ENOENT)
		{
			globals.exit = 127;
			write(STDERR_FILENO, globals.name, _strlen(globals.name));
			write(STDERR_FILENO, ": ", 2);
			if (globals.count > 9 && globals.count < 100)
				_putchar((globals.count / 10) + '0');
			_putchar((globals.count % 10) + '0');
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, globals.cmd, _strlen(globals.cmd));
			write(STDERR_FILENO, ": not found\n", 12);
		}
		else
		{
			globals.exit = 2;
			write(STDERR_FILENO, globals.name, _strlen(globals.name));
			write(STDERR_FILENO, ": ", 2);
			if (globals.count > 9 && globals.count < 100)
				_putchar((globals.count / 10) + '0');
			_putchar((globals.count % 10) + '0');
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, globals.cmd, _strlen(globals.cmd));
			write(STDERR_FILENO, ": not found\n", 12);
		}
	}
	else if (status == EACCES)
	{
		globals.exit = 126;
		write(STDERR_FILENO, globals.name, _strlen(globals.name));
		write(STDERR_FILENO, ": ", 2);
		if (globals.count > 9 && globals.count < 100)
			_putchar((globals.count / 10) + '0');
		_putchar((globals.count % 10) + '0');
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, globals.cmd, _strlen(globals.cmd));
		write(STDERR_FILENO, ": Permission denied\n", 20);
	}
}

/**
 * cdError - Error handling for cd built-in
 * @status: Errno status
 *
 * Return: void
 */
void cdError(int status)
{
	if (status < 0)
	{
		globals.exit = 2;
		write(STDERR_FILENO, globals.name, _strlen(globals.name));
		write(STDERR_FILENO, ": ", 2);
		if (globals.count > 9 && globals.count < 100)
			_putchar((globals.count / 10) + '0');
		_putchar((globals.count % 10) + '0');
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, globals.cmd, _strlen(globals.cmd));
		write(STDERR_FILENO, ": can't cd to ", 14);
		write(STDERR_FILENO, globals.arg, _strlen(globals.arg));
		write(STDERR_FILENO, "\n", 1);
	}
}
