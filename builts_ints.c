#include "holberton.h"
/**
* find_built_in_3 - find builts in
* @args: arguments
* @env: environment variables
* @buffer: user buffer
* Return: result 0 or -1
*/
int find_built_in_3(char **args, char **env, char *buffer)
{
	int i = 0;

	built_in functions[] = {
		{"exit", fexit},
		/*{"help", fhelp},*/
		{"cd", fcd},
		{"env", fenv},
		{NULL, NULL}
	};
	while (functions[i].name != NULL)
	{
		if (_strcmp(args[0], functions[i].name) == 0)
		{
			if (functions[i].f(args, env, buffer) == -1)
			{
				return (-1);
			}
			return (0);
		}
		else
		{
			i++;
		}
	}
	return (1);
}
/**
* fhelp - command help function
* @args: arguments
* @env: environment variables
* @buffer: user buffer
* Return: result 0 or -1
*/
/*int fhelp(char **args, char **env, char *buffer)
{
	(void)env;
	if (args[1] != NULL)
	{
		if (execve("/bin/cat", args, NULL) == -1)
		{
			perror("");
		}
		printf("a!\n");
	}
	free(buffer);
	printf("HELP!\n");
	return (0);
}*/
/**
* fexit - command exit function
* @args: arguments
* @env: environment variables
* @buffer: user buffer
* Return: result...
*/
int fexit(char **args, char **env, char *buffer)
{
	(void)env;

	free(buffer);
	free(args);
	exit(0);
}
/**
* fcd - command cd function
* @args: arguments
* @env: environment variables
* @buffer: user buffer
* Return: result 0
*/
int fcd(char **args, char **env, char *buffer)
{
	char *path = "HOME=";
	char *tmp = NULL;
	int i, j, k;

	if (args[1] == NULL)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (path[j] != env[i][j])
					break;
			}
			if (j == 5)
				break;
		}
		tmp = malloc(_strlen(env[i]) + 1);
		if (tmp == NULL)
			perror("");
		for (k = 0; env[i][j] != '\0'; j++, k++)
			tmp[k] = env[i][j];
		if (chdir(tmp) != 0)
		{
			free(tmp);
			perror("");
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			free(tmp);
			perror("");
		}
	}
		free(buffer);
		free(args);
		return (0);
}

char *checkexec(char *file, char **environ)
{
	char *buff, *buff2, *buff3, PATH[] = "PATH";
	int a = 0, b;
	struct stat st;

	if (stat(file, &st) == 0)
		return (file);
	buff3 = _strcon("/", file);
	while (environ[a] != NULL)
	{
		buff = malloc(sizeof(char) * 20);
		for (b = 0; environ[a][b] != '='; b++)
			buff[b] = environ[a][b];
		if (_strcmp(buff, PATH) == 0)
		{
			free(buff);
			break;
		}
		free(buff);
		a++;
	}
	b = _strlen(environ[a]);
	buff = malloc(sizeof(char) * b);
	_strcpy(buff, environ[a]);
	strtok(buff, "=");
	buff2 = strtok(NULL, ":");
	while (buff2 != NULL)
	{
		buff2 = _strcon(buff2, buff3);
		if (stat(buff2, &st) == 0)
		{
			/*free(file),*/ free(buff), free(buff3);
			return (buff2);
		}
		free(buff2);
		buff2 = strtok(NULL, ":");
	}
	free(file), free(buff), free(buff3);
	return (NULL);
}
char *_strcon(char *dest, char *src)
{
	int a, b, size;
	char *buff;

	size = (_strlen(dest)) + (_strlen(src)) + 1;
	buff = malloc(sizeof(char) * size);
	for (a = 0; dest[a] != '\0'; a++)
	{
		buff[a] = dest[a];
	}
	for (b = 0; src[b] != '\0'; b++)
	{
		buff[a + b] = src[b];
	}
	buff[a + b] = '\0';
	return (buff);
}
