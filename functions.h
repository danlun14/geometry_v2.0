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

int fcheck(char *arr);
int get_center(circle *cir, char *arr);
int get_radius(circle *cir, char *arr);