#include "shell.h"

/**
 * init_info - initializes the info_t struct
 * @info: struct address
 */
void init_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
	info->fname = NULL;
	info->env = NULL;
	info->history = NULL;
	info->alias = NULL;
	info->environ = NULL;
	info->cmd_buf = NULL;
	info->readfd = STDIN_FILENO;
}

/**
 * set_info - initializes info_t struct with arguments
 * @info: struct address
 * @av: argument vector
 */
void set_info(info_t *info, char **av)
{
	int i;

	info->fname = av[0];

	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}

		for (i = 0; info->argv && info->argv[i]; i++)
			;

		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - frees allocated memory in info_t struct
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *info, int all)
{
	if (info->argv)
		ffree(info->argv);
	if (info->path)
		free(info->path);
	if (info->arg && !info->cmd_buf)
		free(info->arg);

	if (all)
	{
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		if (info->environ)
			ffree(info->environ);
		if (info->cmd_buf)
			bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
	}
}

