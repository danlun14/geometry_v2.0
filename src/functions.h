#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char check_report[48];
    char* cur;
} check_info;

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point center;
    float radius;
    int P; //периметр
} circle;

typedef struct {
    point A;
    point B;
    point C;
    int P;
} triangle;

int fcheck(char* arr, check_info* a);
int lpar(check_info* a);
int get_point(point* p, check_info* a);
int take_zpt(check_info* a);
int get_radius(circle* cir, check_info* a);
int rpar(check_info* a);
int last_check(check_info* a);

#endif