#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} point;

typedef struct
{
    point center;
    float radius;
} circle;

int get_center(circle *cir, char *arr)
{
    char *cur, *end;
    int num, i = 0;
    float rad;
    num = arr[i];
    while (num != ',')
    {
        i++;
        num = arr[i];
    }
    cur = arr + 1 + i;
    rad = strtof(cur, &end);
    if (cur - end != 0)
    {
        cir->radius = rad;
        num = *end;
        while (num == ' ')
        {
            end++;
            num = *end;
        }
        if (num == ')')
        {
            end++;
            num = *end;
            while (num == ' ')
            {
                end++;
                num = *end;
            }
            if (num == '\n')
            {
                printf("Successfully");
                return 1;
            }
        }
    }
    return -1;
}