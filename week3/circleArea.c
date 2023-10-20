#include <stdio.h>

float circleArea(float radius) {
    float area;
    area = 3.14*(radius*radius);
    return area;
}

int main() {
    printf("%f\n",circleArea(2.0));
    return 0;
}
