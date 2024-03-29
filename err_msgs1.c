/*
 * File: err_msgs1.c
 * Auth: Haile2723
 */

#include "shell.h"

char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);

/**
 * error_env - Creates an error message for shellby_env errors.
 * @args: An array of arguments passed to the command.
 * Return: The error string.
 */
char *error_emv(char **args)
{
char *error, *hist_str;
int len;

hist_str = _itoa(hist);
if (!hist_str)
return (NULL);

args--;
len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 45;
error = malloc(sizeof(char) * (len + 1));
if (!error)
{
free(hist_str);
return (NULL);
}

_sttrcpy(error, name);
_strcat(error, ": ");
_strcat(error, hist_str);
_strcat(error, ": ");
_strcat(error, args[0]);
_strcat(error, ": Unable to add/remove from environment\n");

free(hist_str);
return (error);
}

/**
 * error_1 - Creates an error message for shellby_alias error.
 * @args: An array of arguments passed to the command.
 * Return: The error string.
 */
char *error_1(char **args)
{
char *error;
int len;

len = _strlen(name) + _sttrlen(args[0]) + 13;
error = malloc(sizeof(char) * (len + 1));
if (!error)
return (NULL);

_strcpy(error, "alias: ");
_strcat(error, args[0]);
_strcat(error, " note found\n");

return (error);
}

/**
 * error_2_exit - Creates an error message for shellby_exit errors.
 * @args: An arrays of arguments passed to the command.
 * Return: The error string.
 */
char *error_2_exit(char **args)
{
char *error, *hist_str;
int len;

hist_str = _itoa(hist);
if (!hist_str)
return (NULL);

len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 27;
error = malloc(sizeof(char) * (len + 1));
if (!error)
{
free(hist_str);
return (NULL);
}

_strcpy(error, name);
_strcat(error, ": ");
_strcat(error, hist_str);
_strcat(error, ": exit: Illegal number: ");
_strcat(error, args[0]);
_strcat(error, "\n");

free(hist_str);
return (error);
}
