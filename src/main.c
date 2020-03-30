#include "functions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num_of_cir = 0, num_of_tri = 0, index = 0;
    check_info status;
    circle mid_cir, cir[3];
    triangle mid_tri, tri[3];
    int f_res = 0;
    char all[128];
    while (1 != 0) {
        for (int i = 0; i < 1; i++) {
            printf("Введите входные данные формата:\n");
            printf("circle(x y, r) - для круга\n");
            printf("triangle (x1 y2, x2 y2, x3 y3) - для треугольника\n");
            fgets(all, 128, stdin);
            if (strcmp(all, "quit\n") == 0) {
                return 0;
            }
            f_res = fcheck(all, &status);
            if (f_res == -1) {
                printf("%s\n", status.check_report);
                break;
            }
            if (f_res == 1) {
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
                cir[num_of_tri].center.x = mid_cir.center.x;
                cir[num_of_tri].center.y = mid_cir.center.y;
                cir[num_of_tri].radius = mid_cir.radius;
                num_of_cir++;
            } else if (f_res = 2) {
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
                num_of_tri++;
            }

        } // printf("%f\n", cir1.radius);
    }
}