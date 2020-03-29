#include "functions.h"

int last_check(check_info *a)
{
    char *arr = a->cur;
    int num = *arr;
    while (num == ' ')
    {
        arr++;
        num = *arr;
    }
    if (num == '\n')
    {
        return 0;
    }
    strcpy(a->check_report, "ERROR: INCORRECT SYMBOL BEFORE \"\\n\"");
    return -1;
}