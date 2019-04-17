#include "shell.h"
/**
 * _strlen - get the length of a string
 * @s:  pointer to beginning of string
 * Return: returns string length
 **/
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}


/**
 * _strcpy - copy string
 * @dest: destination pointer
 * @src: source
 * Return: returns char ptr
 **/

char *_strcpy(char *dest, char *src)
{
	int index = 0;

	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';

	return (dest);
}


/**
 * _strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 * Return: returns 1 on success
 **/
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

/**
* _strncpy - compares one string to another string in memory
* @dest: destination of string to copy from
* @src: string to copy
* @n: length of the copied string
* Return: memory of copied string
**/
char *_strncpy(char *dest, char *src, int n)
{
	int index = 0;

	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}

	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

/**
* _strncmp - compare strings to certaint number of bytes
* @s1: first string
* @s2: second string
* @n: number of bytes
* Return: return 0
**/
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}
