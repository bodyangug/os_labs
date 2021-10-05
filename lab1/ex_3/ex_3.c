#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char lastName[12];
    int group;
    double webTechnologies;
    double ukrLanguage;
    double designInformationSystems;
}Student;

double averageScoreByGroup(Student students[], int len, int group);
void printAllStudentsWhoHaveDebts(Student students[], int len);
double percentageOfStudentsWhoPassedWellOrExcellently(Student students[], int len);
void nameOfTheItemThatWereHandedOverBest(Student students[], int len);
int worstGroup(Student students[], int len);
void genetrateStudents(Student students[], int len);

int main(int argc, char const *argv[])
{
    Student students [30];
    srand(time(NULL));
    genetrateStudents(students, 30);

    printAllStudentsWhoHaveDebts(students, 30);
    printf("Percentage of students who passed: %lf\n",percentageOfStudentsWhoPassedWellOrExcellently(students, 30));
    
    nameOfTheItemThatWereHandedOverBest(students, 30);
    
    printf("Group, which has the worst performing : %d\n", worstGroup(students, 30));
    return 0;
}

void genetrateStudents(Student students[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        students[i].designInformationSystems = rand() % 100 + 1;
        students[i].ukrLanguage = rand() % 100 + 1;
        students[i].webTechnologies = rand() % 100 + 1;
        students[i].group = rand() % 4 + 1;
        students[i].lastName[0] = '\0';
        for (size_t j = 0; j < 11; j++){
           students[i].lastName[j] = rand()%(90 - 65) + 65;
        }
        students[i].lastName[11] = '\0';
    }
}

void printAllStudentsWhoHaveDebts(Student students[], int len)
{
    int count = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (students[i].designInformationSystems < 50 || students[i].ukrLanguage < 50|| students[i].webTechnologies <50)
        {
            printf("Name : %s | Ukr language: %0.2lf | Design information systems: %0.2lf | Web technologies: %0.2lf \n", 
                students[i].lastName, students[i].ukrLanguage, students[i].designInformationSystems, students[i].webTechnologies);
            count++;
        }
    }
    printf("Count of students who have debts: %d\n", count);
}

double percentageOfStudentsWhoPassedWellOrExcellently(Student students[], int len)
{
    int count = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (students[i].designInformationSystems > 50 
            && students[i].ukrLanguage > 50
            && students[i].webTechnologies > 50)
        {
            count++;
        }
    }
    return (double)(count * 100) / len;
}

void nameOfTheItemThatWereHandedOverBest(Student students[], int len)
{
    double webTechnologies = 0;
    double ukrLanguage = 0;
    double designInformationSystems = 0;

    for (size_t i = 0; i < len; i++)
    {
        webTechnologies = students[i].webTechnologies;
        designInformationSystems = students[i].designInformationSystems;
        ukrLanguage = students[i].ukrLanguage;
    }
    if (ukrLanguage > designInformationSystems 
        && ukrLanguage > webTechnologies)
    {
        printf("Best to pass the subject of Ukr Language\n");

    }
    else if (webTechnologies > ukrLanguage
        && webTechnologies > designInformationSystems)
    {
        printf("Best to pass the subject of Design Information Systems\n");
    }
    else
    {
        printf("Best to pass the subject of  Web Technologies\n");
    }  
}

int worstGroup(Student students[], int len)
{
    double averageScoreByGroup1 = averageScoreByGroup(students,len,1);
    double averageScoreByGroup2 = averageScoreByGroup(students,len,2);
    double averageScoreByGroup3 = averageScoreByGroup(students,len,3);
    double averageScoreByGroup4 = averageScoreByGroup(students,len,4);

    if (averageScoreByGroup1 > averageScoreByGroup2 
        && averageScoreByGroup1 > averageScoreByGroup3
        && averageScoreByGroup1 > averageScoreByGroup4)
    {
        return 1;
    }
    else if (averageScoreByGroup2 > averageScoreByGroup3
        && averageScoreByGroup2 > averageScoreByGroup1
        && averageScoreByGroup2 > averageScoreByGroup4)
    {
        return 2;
    }
    else if (averageScoreByGroup3 > averageScoreByGroup1
        && averageScoreByGroup3 > averageScoreByGroup2
        && averageScoreByGroup3 > averageScoreByGroup4)
    {
        return 3;
    }
    else
    {
        return 4;
    } 

}

double averageScoreByGroup(Student students[], int len, int group)
{
    int count = 0;
    double sum = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (students[i].group == group)
        {
            count++;
            sum += students[i].designInformationSystems + 
            students[i].ukrLanguage + students[i].webTechnologies;
        }
    }
    return sum / count;
}
