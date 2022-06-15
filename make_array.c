#include "monty.h"
/**
 * make_array - makes an array strings from a line of string
 * @s: line of string
 * @dl: delimeter
 * @arr: array to save string
 * Return: 1 or 0
 */
int make_array(char *s, const char *dl, char *arr[])
{
	char *token = strtok(s, dl);
	int i = 0;

	while (token)
	{
		arr[i] = token;
		token = strtok(NULL, dl);
		i++;
	}
	arr[i] = NULL;

	return (1);
}
