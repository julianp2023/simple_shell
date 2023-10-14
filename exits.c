#include <stdio.h>

/**
 * my_function - Example function
 * @param1: Description of param1
 * @param2: Description of param2
 * Return: Description of the return value
 */
int my_function(int param1, int param2)
{
    /* Code here */
    if (param1 > param2) {
        /* Handle the case */
        return param1;
    } else {
        /* Handle the other case */
        return param2;
    }
}

/**
 * another_function - Another example function
 * @param: Description of the parameter
 * Return: Description of the return value
 */
char *another_function(char *param)
{
    /* Code here */
    return param;
}

/**
 * main - Main function
 * Return: Always 0
 */
int main(void)
{
    int result;
    char *str;

    result = my_function(10, 20);
    str = another_function("Hello, world!");

    /* Further code */

    return 0;
}

