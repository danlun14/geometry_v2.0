#include "f.h"

int rpar(check_info* a)
{
    char* arr = a->cur;
    int num, i = a->cur - arr;
    num = *(arr + i);
    while (num != ')') {
        if (num == '\n') {
            strcpy(a->check_report, "ERROR: SYMBOL \")\" NOT FOUND\n");
            return -1;
        } else if (num != ' ') {
            strcpy(a->check_report, "ERROR: INCORRECT SYMBOL\n");
            return -1;
        }
        i++;
        num = arr[i];
    }
    a->cur = a->cur + 1 + i;
    return 0;
}