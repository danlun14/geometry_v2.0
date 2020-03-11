#include <stdlib.h>
#define NUM_SYS 10

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
    long int coordinate;
    num = arr[i];
    while (num != '(')
    {
        i++;
        num = arr[i];
    }
    cur = arr + 1 + i;
    coordinate = strtol(cur, &end, NUM_SYS);
    if (cur - end != 0)
    {
        cir->center.x = coordinate;
        cur = end;
        coordinate = strtol(cur, &end, NUM_SYS);
        if (cur - end != 0)
        {
            cir->center.y = coordinate;
            cur = end;
            num = *cur;
            while (num == ' ')
            {
                cur++;
                num = *cur;
            }
            if (num == ',')
            {
                return 1;
            }
        }
    }
    return -1;
}