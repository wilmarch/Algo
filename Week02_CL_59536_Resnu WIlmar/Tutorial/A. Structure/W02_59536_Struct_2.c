#include <stdio.h>

struct Student{
    char name[50];
    char major[35];
    float gpa;
};

int main(){
    struct Student waldo = {"Waldo", "Informatika", 3.98};
    struct Student *WaldoPtr = &waldo;

    printf("Without Pointer\n");
    printf("Name   : %s\n", waldo.name);
    printf("Major  : %s\n", waldo.major);
    printf("GPA    : %.2f\n", waldo.gpa);

    printf("\nWith Pointer\n");
    printf("Name   : %s\n", WaldoPtr->name);
    printf("Major  : %s\n", WaldoPtr->major);
    printf("GPA    : %.2f\n", WaldoPtr->gpa);
    return 0;
}
