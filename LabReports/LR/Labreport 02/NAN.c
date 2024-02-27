#include <stdio.h>
#include <math.h>
float velocityCalc(float v, float u, float a, float t) {
    if (isnan(v)) {
        return u + (a * t);
    } else if (isnan(u)) {
        return v - (a * t);
    } else if (isnan(a)) {
        return (v - u) / t;
    } else if (isnan(t)) {
        return (v - u) / a;
    } else {
        return NAN;
    }
}
int main() {
    printf("When t is nan, result is %f \n",velocityCalc(20, 30, 40, NAN));
    printf("When a is nan, result is %f \n",velocityCalc(22, 33, NAN, 77));
    printf("When u is nan, result is %f \n",velocityCalc(88, NAN, 100, 44.6));
    printf("When v is nan, result is %f \n",velocityCalc(NAN, 78, 93, 89));
    return 0;
}


