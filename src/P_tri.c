#include "f.h"
#include <math.h>
float side_len(point* a, point* b)
{
    return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}

void P_tri(triangle* tri)
{
    tri->P = side_len(&tri->A, &tri->B) + side_len(&tri->B, &tri->C)
            + side_len(&tri->A, &tri->C);
}