#include "functions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_circle(circle* cir)
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

int print_triangle(triangle* tri)
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
            printf("Введите входные данные формата:\n");
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
                f_res = lpar(&status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                f_res = get_point(&(&mid_cir)->center, &status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                f_res = take_zpt(&status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                f_res = get_radius(&mid_cir, &status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                f_res = rpar(&status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                f_res = last_check(&status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                cir[num_of_cir].center.x = mid_cir.center.x;
                cir[num_of_cir].center.y = mid_cir.center.y;
                cir[num_of_cir].radius = mid_cir.radius;
                print_circle(&cir[num_of_cir]);
                num_of_cir++;
            } else if ((f_res == 2) && (num_of_tri != 3)) {
                f_res = lpar(&status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                f_res = get_point(&(&mid_tri)->A, &status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                f_res = take_zpt(&status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                f_res = get_point(&(&mid_tri)->B, &status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                f_res = take_zpt(&status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                f_res = get_point(&(&mid_tri)->C, &status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                f_res = rpar(&status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                f_res = last_check(&status);
                if (f_res == -1) {
                    printf("%s\n", status.check_report);
                    break;
                }
                tri[num_of_tri].A.x = mid_tri.A.x;
                tri[num_of_tri].A.y = mid_tri.A.y;
                tri[num_of_tri].B.x = mid_tri.B.x;
                tri[num_of_tri].B.y = mid_tri.B.y;
                tri[num_of_tri].C.x = mid_tri.C.x;
                tri[num_of_tri].C.y = mid_tri.C.y;
                print_triangle(&tri[num_of_tri]);
                num_of_tri++;
            }
        }
    }
    printf("Завершаю работу\n");
}