#include <stdio.h>
void equations(double a, double b, double c, double d, double e, double f) {
    double determinant = a * e - b * d;
    
    if (determinant == 0) {
        printf("The lines are parallel. No intersection point.\n");
    } else {
        double x = (c * e - b * f) / determinant;
        double y = (a * f - c * d) / determinant;

        printf("Intersection point (x, y): (%.2lf, %.2lf)\n", x, y);
    }
}

int main() {
    double a, b, c, d, e, f;

    printf("Enter coefficients for equations (ax + by = c) and (dx + ey = f):\n");
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter c: ");
    scanf("%lf", &c);
    printf("Enter d: ");
    scanf("%lf", &d);
    printf("Enter e: ");
    scanf("%lf", &e);
    printf("Enter f: ");
    scanf("%lf", &f);

    equations(a, b, c, d, e, f);

    return 0;
}

