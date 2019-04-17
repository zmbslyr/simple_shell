#include "shell.h"

/**
 * vect - Takes a string and puts it into a vector array
 * @str: String to break apart
 * @delim: Delimeter string
 * @n: Size to malloc
 *
 * Return: Pointer to an array of pointers
 */
char **vect(char *str, char *delim,  ssize_t n)
{
	char *buffer, *bufPointer, *token;
	char **args;
	size_t tokenSize = 1;
	int argc = 0, index;

	buffer = malloc(n + 1);
	if (buffer == NULL)
		return (NULL);
	bufPointer = buffer;
	_strcpy(buffer, str);
	for (argc = 0; *bufPointer != '\0'; bufPointer++)
	{
		for (index = 0; delim[index] != '\0'; index++)
		{
			if (*bufPointer == delim[index])
				tokenSize++;
		}
	}
	args = malloc(sizeof(char *) * (tokenSize + 1));
	if (args == NULL)
		return (NULL);
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		args[argc] = malloc(_strlen(token) + 1);
		_strcpy(args[argc], token);
		token = strtok(NULL, delim);
		argc++;
	}
	args[argc] = NULL;
	free(buffer);
	return (args);
}
