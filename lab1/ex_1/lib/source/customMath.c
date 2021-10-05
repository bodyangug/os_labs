#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double facktorial(double x){
    double sum = 1;
    for (int i = 1; i <= x; i++){
        sum *= i;
    }
    return sum;
}

double sinus(double x,double eps){
    double addendum = __DBL_MAX__;
    double sum = 0;
    for (int i = 0,degree = 1; fabsl(addendum) >= eps; i++, degree +=2){
        addendum = pow(x, degree) / facktorial(degree) * pow(-1,i);
        sum += addendum;
    }
    return sum;
}

double cosinus(double x, double eps){
    double addendum = __DBL_MAX__;
    double sum = 0;

    for (int i = 0,degree = 0; fabsl(addendum) >= eps; i++, degree +=2){
        addendum = pow(x, degree) / facktorial(degree) * pow(-1,i);
        sum += addendum;
    }
    return sum;
}


