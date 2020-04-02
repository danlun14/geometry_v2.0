#include "parse_functions.h"

int get_radius(circle* cir, check_info* a)
{
    char *arr, *end;
    float rad;
    arr = a->cur;
    rad = strtof(arr, &end);
    if (arr - end != 0) {
        a->cur = end;
        cir->radius = rad;
        return 0;
    }
    strcpy(a->check_report, "ERROR: INCORRECT RADIUS\n");
    return -1;
}