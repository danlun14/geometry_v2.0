#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdlib.h>
#include "functions.h"

/*
int fcheck(char *arr, check_info *a);
int lpar(check_info *a);
int get_point(point *p, check_info *a);
int take_zpt(check_info *a);
int get_radius(circle *cir, check_info *a);
int lpar(check_info *a);
int last_check(check_info *a);
*/

int main()
{
    check_info a;
    circle *p;
    circle cir1;
    p = &cir1;
    int f_res = 0;
    char all[128];
    printf("Введите входные данные формата:\n");
    printf("circle(x y, r) - для круга\n");
    fgets(all, 128, stdin);
    printf("%s", all);
    f_res = fcheck(all, &a);
    if (f_res == -1)
    {
        printf("%s\n", a.check_report);
        return -1;
    }
    printf("%d\n", f_res);
    f_res = lpar(&a);
    if (f_res == -1)
    {
        printf("%s\n", a.check_report);
        return -1;
    }
    printf("%d\n", f_res);
    f_res = get_point(&p->center, &a);
    if (f_res == -1)
    {
        printf("%s\n", a.check_report);
        return -1;
    }
    printf("%d\n", f_res);
    f_res = take_zpt(&a);
    if (f_res == -1)
    {
        printf("%s\n", a.check_report);
        return -1;
    }
    printf("%d\n", f_res);
    f_res = get_radius(p, &a);
    if (f_res == -1)
    {
        printf("%s\n", a.check_report);
        return -1;
    }
    printf("%d\n", f_res);
    f_res = rpar(&a);
    if (f_res == -1)
    {
        printf("%s\n", a.check_report);
        return -1;
    }
    printf("%d\n", f_res);
    f_res = last_check(&a);
    if (f_res == -1)
    {
        printf("%s\n", a.check_report);
        return -1;
    }
    printf("%d\n", cir1.center.x);
    printf("%d\n", cir1.center.y);
    printf("%f\n", cir1.radius);
}