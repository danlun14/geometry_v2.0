#define NUM_SYS 10
#include "functions.h"

int get_point(point* p, check_info* a)
{
    char *curr, *end, *arr;
    arr = a->cur;
    int i = 0;
    long int coordinate;
    curr = arr + 1 + i;
    coordinate = strtol(curr, &end, NUM_SYS);
    if (curr - end != 0) {
        p->x = coordinate;
        curr = end;
        coordinate = strtol(curr, &end, NUM_SYS);
        if (curr - end != 0) {
            p->y = coordinate;
            a->cur = end;
            return 0;
        }
    }
    strcpy(a->check_report, "ERROR: INCORRECT COORDINATE");
    return -1;
}