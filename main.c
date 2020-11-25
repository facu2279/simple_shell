#include "holberton.h"
/**
 * main - Entry point
 * @ac: ac
 * @av: av
 * @env: environment variables
 * Return: void;
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	char **args = NULL;
	char *path = NULL;
	int built_in = 0;
	(void)ac;
	(void)av;

	signal(SIGINT, controlcfun);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt_0();
		}
		buffer = getline_1();
		if (space_check(buffer) != 0 && buffer[0] != '\0')
		{
			args = split_line_2(buffer);
			built_in = find_built_in_3(args, env, buffer);
			if (built_in == 0)
			{
				continue;
			}
			if (main_extension(args, path, buffer, env) == 1)
				continue;
			free(buffer);
		}
		else
		{
			free(buffer);
			continue;
		}
	}
	return (0);
}

/**
 * main_extension - extension for the main function
 * @args: arguments from the main
 * @path: command path
 * @buffer: user buffer
 * @env: environment variables
 * Return: 0 on succes, 1 on failure.
 */
int main_extension(char **args,char *path, char *buffer, char **env)
{
	struct stat st;

	if (stat(args[0], &st) != 0)
	{
		/*path = getpath_4(args[0], env);*/
		path = checkexec(args[0], env);
		if (path == NULL)
		{
			free(buffer);
			free(args);
			return (1);
		}
	}
	else
	{
		if (dir_check(args[0]) == 1)
		{
			free(buffer);
			free(args);
			free(path);
			return (1);
		}
	}
	execute_5(path, args, env);
	free(path);
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
			/*free(file), */free(buff), free(buff3);
			return (buff2);
		}
		free(buff2);
		buff2 = strtok(NULL, ":");
	}
	/*free(file), */free(buff), free(buff3);
	return (NULL);
}

/**
 * _strcon - concatenates two strings
 *
 * @dest: destiny string
 * @src: string to add
 * Return: pointer to dest
 */

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