#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* generateMass(int from, int to, int lenght);
double getAverage(double* mass, int lenght);
int numberElementsGreaterAverageElementsArray(double* mass, int lenght);
double sumModulesArrayElementsLocatedAfterFirstNegativeElement(double* mass, int lenght);

int main(int argc, char const *argv[]){
    srand(time(NULL));
    int lenght = 10;
    double* mass = generateMass(-10,10,lenght);

    for (int i = 0; i < lenght; i++){
        printf("%.2lf  ", mass[i]);
    }
    printf("\n");
    printf("Number elements greater average elements array : %d\n", numberElementsGreaterAverageElementsArray(mass,lenght));
    printf("Sum modules array elements located after first negative element : %lf\n", sumModulesArrayElementsLocatedAfterFirstNegativeElement(mass,lenght));

    return 0;
}

double* generateMass(int from, int to, int lenght){
    double* mass = malloc(sizeof(double) * lenght);

    for (int i = 0; i < lenght; i++){
        mass[i] = rand()%(to-from) + from;
    }
    return mass;
}

double getAverage(double* mass, int lenght){
    double sum = 0;

    for (int i = 0; i < lenght; i++){
        sum += mass[i];
    }
    return sum/lenght;
}

int numberElementsGreaterAverageElementsArray(double* mass, int lenght){
    int count = 0;
    double aver = getAverage(mass,lenght);

    for (int i = 0; i < lenght; i++){
        if (mass[i] < aver){
            count++;
        }
    }
    return count;    
}

double sumModulesArrayElementsLocatedAfterFirstNegativeElement(double* mass, int lenght){
    int flag = 0;
    double sum = 0;
    for (int i = 0; i < lenght; i++){
        if (flag){
            sum += abs(mass[i]);
        }
        
        if (!flag && mass[i] < 0){
            flag = 1;
        }
    }
    return sum;
}
