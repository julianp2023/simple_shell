/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s)
{
	int sign = 1;
	int i = 0;
	int output = 0;

	/* Handle negative numbers */
	if (s[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	/* Process digits and build the result */
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			output = output * 10 + (s[i] - '0');
		}
		else
		{
			/* Stop if a non-digit character is encountered */
			break;
		}
		i++;
	}

	return (sign * output);
}

