#include "f.h"

void S_tri(triangle* tri)
{
    tri->S = fabs((tri->B.x - tri->A.x) * (tri->C.y - tri->A.y)
                  + (tri->C.x - tri->A.x) * (tri->B.y - tri->A.y))
            / 2;
}