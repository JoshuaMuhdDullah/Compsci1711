#include <stdio.h>

typedef struct {
    double x;
    double y;
} point;

void main() {
    double xinp, yinp;
    printf("x: ");
    scanf("%lf",&xinp); 
    printf("y: ");
    scanf("%lf",&yinp); 

    point pointinp = {xinp, yinp};
    printf("(%.2lf,%.2lf)",pointinp.x,pointinp.y);
}