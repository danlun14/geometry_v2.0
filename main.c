#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char all[128];
    printf("Введите входные данные формата:\n");
    printf("circle(x y, r) - для круга\n");
    fgets(all, 128, stdin);
    printf("%s", all);
}