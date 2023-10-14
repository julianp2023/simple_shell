#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments.
 * Return: exits with a given exit status
 */
int _myexit(info_t *info)
{
	int exit_status = 0;

	if (info->argv[1])
	{
		exit_status = _erratoi(info->argv[1]);
		if (exit_status == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = exit_status;
	}
	else
		info->err_num = -1;

	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: 0 on success, 1 on failure
 */
int _mycd(info_t *info)
{
	char *dir;
	char buffer[1024];

	if (!info->argv[1])
		dir = _getenv(info, "HOME=") ?: _getenv(info, "PWD=") ?: "/";
	else if (_strcmp(info->argv[1], "-") == 0)
		dir = _getenv(info, "OLDPWD=") ?: "/";
	else
		dir = info->argv[1];

	if (chdir(dir) == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(dir);
		_eputchar('\n');
		return (1);
	}

	_setenv(info, "OLDPWD", _getenv(info, "PWD="));
	_setenv(info, "PWD", getcwd(buffer, 1024));

	return (0);
}

/**
 * _myhelp - displays help information (not yet implemented)
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	(void)info;
	_puts("Help information is not yet implemented.\n");
	return (0);
}

