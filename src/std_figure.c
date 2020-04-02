#include "f.h"

void circle_copy(circle* cir1, circle* cir2)
{
    cir1->center.x = cir2->center.x;
    cir1->center.y = cir2->center.y;
    cir1->radius = cir2->radius;
    cir1->S = cir2->S;
    cir1->P = cir2->P;
}

void triangle_copy(triangle* tri1, triangle* tri2)
{
    tri1->A.x = tri2->A.x;
    tri1->A.y = tri2->A.y;
    tri1->B.x = tri2->B.x;
    tri1->B.y = tri2->B.y;
    tri1->C.x = tri2->C.x;
    tri1->C.y = tri2->C.y;
    tri1->S = tri2->S;
    tri1->P = tri2->P;
}

void print_circle(circle* cir)
{
    printf("-------------------------\n");
    printf("______|     x      y     \n");
    printf("center|  %5d  %5d\n", cir->center.x, cir->center.y);
    printf("-------------------------\n");
    printf("radius|          %6.2f\n", cir->radius);
    printf("-------------------------\n");
    printf("square:          %6.2f\n", cir->S);
    printf("perimetr:        %6.2f\n", cir->P);
    printf("-------------------------\n");
}

void print_triangle(triangle* tri)
{
    printf("-------------------------\n");
    printf("_____|     x       y     \n");
    printf("  A  |  %5d  %5d\n", tri->A.x, tri->A.y);
    printf("  B  |  %5d  %5d\n", tri->B.x, tri->B.y);
    printf("  C  |  %5d  %5d\n", tri->C.x, tri->C.y);
    printf("-------------------------\n");
    printf("square:          %6.2f\n", tri->S);
    printf("perimetr:        %6.2f\n", tri->P);
    printf("-------------------------\n");
}
