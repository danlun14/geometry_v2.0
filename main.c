#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    circle *p;
    circle cir1;
    p = &cir1;
    int f_res = 0;
    char all[128];
    printf("Введите входные данные формата:\n");
    printf("circle(x y, r) - для круга\n");
    fgets(all, 128, stdin);
    printf("%s", all);
    f_res = fcheck(all);
    printf("%d\n", f_res);
    f_res = get_center(p, all);
    printf("%d\n", f_res);
    get_radius(p, all);
    printf("%d  %d      %f\n", cir1.center.x, cir1.center.y, cir1.radius);
}
