#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib/customMath.h"

double function(double x);
double getDistance(double x1, double y1, double x2, double y2);

double EPS = 0.0001;

int main(int argc, char const *argv[])
{
    printf("5! : %lf\n", facktorial(5));
    printf("2^3 : %lf\n", pow(2,3));
    printf("sin(1) : %lf\n", sinus(1,EPS));
    printf("cos(1) : %lf\n", cosine(1,EPS));
    printf("f(x) : %lf\n", function(1));

    int from;
    int to;
    int count;

    printf("From: ");
    scanf("%d",&from);
    printf("To: ");
    scanf("%d", &to);
    printf("Enter count: ");
    scanf("%d",&count);

    double strLength = (double)(to - from) / count; 
    double sum = 0;
    double copyFrom = from;

    for (int i = 0; i < count; i++)
    {
        sum += getDistance(copyFrom, function(copyFrom), copyFrom-strLength, function(copyFrom+strLength));
        copyFrom += strLength;
    }
    printf("Lenght: %lf\n", sum);
    return 0;
}

double function(double x){
    return pow(sinus(x, EPS),2) / (1+ pow(cosine(x,EPS),3));
}

double getDistance(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2 - x1),2) + pow((y2 - y1), 2)) ;
}
