#include "parse_functions.h"

int parse_circle_info(check_info* status, circle* mid_cir)
{
    int f_res = lpar(status);
    if (f_res == -1) {
        return -1;
    }
    f_res = get_point(&mid_cir->center, status);
    if (f_res == -1) {
        return -1;
    }
    f_res = take_zpt(status);
    if (f_res == -1) {
        return -1;
    }
    f_res = get_radius(mid_cir, status);
    if (f_res == -1) {
        return -1;
    }
    f_res = rpar(status);
    if (f_res == -1) {
        return -1;
    }
    f_res = last_check(status);
    if (f_res == -1) {
        return -1;
    }
    return 0;
}

int parse_triangle_info(check_info* status, triangle* mid_tri)
{
    int f_res = lpar(status);
    if (f_res == -1) {
        return -1;
    }
    f_res = get_point(&mid_tri->A, status);
    if (f_res == -1) {
        return -1;
    }
    f_res = take_zpt(status);
    if (f_res == -1) {
        return -1;
    }
    f_res = get_point(&mid_tri->B, status);
    if (f_res == -1) {
        return -1;
    }
    f_res = take_zpt(status);
    if (f_res == -1) {
        return -1;
    }
    f_res = get_point(&mid_tri->C, status);
    if (f_res == -1) {
        return -1;
    }
    f_res = rpar(status);
    if (f_res == -1) {
        return -1;
    }
    f_res = last_check(status);
    if (f_res == -1) {
        return -1;
    }
    return 0;
}

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

int main()
{
    int num_of_cir = 0, num_of_tri = 0, index = 0;
    check_info status;
    circle mid_cir, cir[3];
    triangle mid_tri, tri[3];
    int f_res = 0;
    char all[128];
    while ((num_of_tri != num_of_cir) || (num_of_cir != 3)) {
        for (int i = 0; i < 1; i++) {
            printf("Введите данные фигуры:\n");
            printf("circle(x y, r) - для круга( осталось %d)\n",
                   3 - num_of_cir);
            printf("triangle (x1 y2, x2 y2, x3 y3) - для треугольника( "
                   "осталось %d)\n",
                   3 - num_of_tri);
            printf("quit - выключить программу\n");
            fgets(all, 128, stdin);
            if (strcmp(all, "quit\n") == 0) {
                return 0;
            }
            f_res = fcheck(all, &status);
            if (f_res == -1) {
                printf("%s\n", status.check_report);
                break;
            }
            if ((f_res == 1) && (num_of_cir != 3)) {
                f_res = parse_circle_info(&status, &mid_cir);
                if (f_res == 0) {
                    circle_copy(&cir[num_of_tri], &mid_cir);
                    print_circle(&cir[num_of_cir]);
                    num_of_cir++;
                } else {
                    printf("%s\n", status.check_report);
                }
            } else if ((f_res == 2) && (num_of_tri != 3)) {
                f_res = parse_triangle_info(&status, &mid_tri);
                if (f_res == 0) {
                    triangle_copy(&tri[num_of_tri], &mid_tri);
                    print_triangle(&tri[num_of_tri]);
                    num_of_tri++;
                } else {
                    printf("%s\n", status.check_report);
                }
            }
        }
    }
    printf("Завершаю работу\n");
}