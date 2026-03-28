#include <stdio.h>
#define PI 3.14159

int main() {
    double radius;
    double circumference;
    double square;
    printf("中文显示测试\n");
    printf("Please enter the radius of the circle: ");
    scanf("%lf", &radius);
    circumference = 2 * PI * radius;
    square = PI * radius * radius;
    printf("The circumference of the circle is: %.2f\n", circumference);
    printf("The area of the circle is: %.2f\n", square);
    return 0;
}