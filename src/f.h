#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// libraries

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structs

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
    float P; //периметр
    float S; //площадь
} circle;

typedef struct {
    point A;
    point B;
    point C;
    float P;
    float S;
} triangle;

// standart figure functions

void circle_copy(circle* cir1, circle* cir2);
void triangle_copy(triangle* tri1, triangle* tri2);
void print_circle(circle* cir);
void print_triangle(triangle* tri);
// figure math

void P_tri(triangle* tri);
void S_tri(triangle* tri);

// parse functions

int fcheck(char* arr, check_info* a);
int lpar(check_info* a);
int get_point(point* p, check_info* a);
int take_zpt(check_info* a);
int get_radius(circle* cir, check_info* a);
int rpar(check_info* a);
int last_check(check_info* a);

#endif