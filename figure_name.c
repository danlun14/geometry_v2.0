#include <stdlib.h>
#include <ctype.h>

int equals_string(char *arr1, char *arr2, int n)
{
    int num;
    for (int i = 0; i < n; i++)
    {
        num = arr1[i];
        arr1[i] = toupper(num);
        if (arr1[i] != arr2[i])
        {
            return 0;
        }
    }
    return 1;
}

int fcheck(char *arr)
{
    int i = 0, num, cir = 6, tri = 8;
    char CIRCLE[7] = "CIRCLE",
         TRIANGLE[9] = "TRIANGLE";
    num = arr[i];
    while (num == ' ')
    {
        i++;
        num = arr[i];
    }
    if (equals_string((arr + i), CIRCLE, cir) == 1)
    {
        i = i + cir;
        num = arr[i];
        while (num == ' ')
        {
            i++;
            num = arr[i];
        }
        if (num == '(')
        {
            return 1;
        }
    }
    else if (equals_string((arr + i), TRIANGLE, cir) == 1)
    {
        i = i + tri;
        num = arr[i];
        while (num == ' ')
        {
            i++;
            num = arr[i];
        }
        if (num == '(')
        {
            return 2;
        }
    }
    return -1;
}
