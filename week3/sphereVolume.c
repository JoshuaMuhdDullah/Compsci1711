#include <stdio.h>
#include <math.h>

float sphereVolume(float radius) {
    int volume;
    volume = (4/3)*3.14*(radius*radius*radius);
    return volume;
}

void main() {
    printf("%f\n",sphereVolume(2));
}