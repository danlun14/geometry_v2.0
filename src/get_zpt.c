#include "f.h"

int take_zpt(check_info* a)
{
    char* arr = a->cur;
    int num, i = a->cur - arr;
    num = *(arr + i);
    while (num != ',') {
        if (num == '\n') {
            strcpy(a->check_report, "ERROR: SYMBOL \",\" NOT FOUND\n");
            return -1;
        } else if (num != ' ') {
            strcpy(a->check_report, "ERROR: INCORRECT SYMBOL BEFORE \",\"\n");
            return -1;
        }
        i++;
        num = arr[i];
    }
    a->cur = a->cur + 1 + i;
    return 0;
}