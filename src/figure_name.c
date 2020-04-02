#include "parse_functions.h"

char* equals_string(char* arr1, char* arr2, int n)
{
    int num;
    for (int i = 0; i < n; i++) {
        num = arr1[i];
        arr1[i] = toupper(num);
        if (arr1[i] != arr2[i]) {
            return arr1 + i;
        }
    }
    return NULL;
}

int fcheck(char* arr, check_info* a)
{
    int i = 0, num, cir = 6, tri = 8;
    char *a_eq, *b_eq, *temp, *st_of_fig;
    char CIRCLE[7] = "CIRCLE", TRIANGLE[9] = "TRIANGLE";
    num = arr[i];
    while (num == ' ') {
        i++;
        num = arr[i];
    }
    a->cur = arr + i;
    st_of_fig = a->cur;
    a_eq = equals_string((arr + i), CIRCLE, cir);
    b_eq = equals_string((arr + i), TRIANGLE, tri);
    if (a_eq == NULL) {
        a->cur += cir;
        return 1;
    } else if (b_eq == NULL) {
        a->cur += tri;
        return 2;
    }
    if (a_eq > b_eq) {
        temp = a_eq;
    } else {
        temp = b_eq;
    }
    strcpy(a->check_report, "ERROR: INCORRECT FIGURE NAME          \n");
    for (i = 0; i < temp - st_of_fig + 2; i++) {
        if (arr[i] != *temp) {
            a->check_report[31 + i] = tolower(arr[i]);
        } else {
            a->check_report[31 + i] = *temp;
        }
    }

    return -1;
}
