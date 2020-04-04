#include "f.h"

int get_radius(circle* cir, check_info* a)
{
    char *arr, *end;
    float rad;
    arr = a->cur;
    rad = strtof(arr, &end);
    if (arr - end != 0) {
        a->cur = end;
        cir->radius = rad;
        if (cir->radius <= 0) {
            strcpy(a->check_report, "ERROR: RADIUS CAN'T BE NEGATIVE\n");
            return -1;
        }
        return 0;
    }
    strcpy(a->check_report, "ERROR: INCORRECT RADIUS\n");
    return -1;
}