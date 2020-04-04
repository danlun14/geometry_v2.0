#include "f.h"
#define MAX_OF_CIR 3
#define MAX_OF_TRI 3
// parse circle

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
    S_cir(mid_cir);
    P_cir(mid_cir);
    return 0;
}

// parse triangle

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
    P_tri(mid_tri);
    S_tri(mid_tri);
    return 0;
}

int main()
{
    int num_of_cir = 0, num_of_tri = 0, index = 0;
    check_info status;
    circle mid_cir, cir[MAX_OF_CIR];
    triangle mid_tri, tri[MAX_OF_TRI];
    int f_res = 0;
    char all[128];
    while ((num_of_tri != num_of_cir) || (num_of_cir != MAX_OF_CIR)
           || (num_of_tri != MAX_OF_TRI)) {
        for (int i = 0; i < 1; i++) {
            printf("Введите данные фигуры:\n");
            printf("circle(x y, r) - для круга( осталось %d)\n",
                   MAX_OF_CIR - num_of_cir);
            printf("triangle (x1 y2, x2 y2, x3 y3) - для треугольника( "
                   "осталось %d)\n",
                   MAX_OF_TRI - num_of_tri);
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
            if ((f_res == 1) && (num_of_cir != MAX_OF_CIR)) {
                f_res = parse_circle_info(&status, &mid_cir);
                if (f_res == 0) {
                    circle_copy(&cir[num_of_cir], &mid_cir);
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