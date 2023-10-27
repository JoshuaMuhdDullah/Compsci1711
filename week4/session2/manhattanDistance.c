#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

double manhattanDistance(point point1, point point2) {
    double val;
    val = fabs(point1.x - point2.x) + fabs(point1.y - point2.y);
    return val;
}

int main() {
    int i, n = 8;
    double sum, sigma = 0;

    point points [] = {
        {1,1},
        {2,2},
        {3,3},
        {4,4},
        {5,5},
        {6,6},
        {7,7},
        {8,8},
        {9,9},
    };

    for (i = 0; i < n; i++) {
        sigma += manhattanDistance(points[i],points[i+1]);
        printf("%lf\n",sigma);
    };

    sum = sigma/(8);
    printf("Average Manhattan Distance = %lf\n", sum);
    return 1;
}