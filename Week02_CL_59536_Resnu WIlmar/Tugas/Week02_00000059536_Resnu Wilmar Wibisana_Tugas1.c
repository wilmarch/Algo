#include <stdio.h>

struct student {
    char name[47];
    char major [20];
    double gpa;
};


int main() {
    int count = 0;
    int a = 0;
    int max_val = 20;
    struct student murid[20];
    int menu;

    int keep = 1;
    while (keep)
    {
    printf("    Welcome To Simple Student Database (%i/20)\n", count);
    printf("\n");
    printf("    1. Show All Student\n");
    printf("    2. Input New Student\n");
    printf("    3. Exit\n");
    printf("\n");
    printf("    Choose: ");
    scanf("%i%*c", &menu);


    switch (menu)
    {
    case 1 :
        if (count == 0){
            printf("\n");
            printf("    Database Is Empty\n");
            printf("\n");
        } else {
            printf("    ------------------------------------------------------------------------------------\n");
            printf("    |                            LIST OF STUDENT INFORMATION                           |\n");
            printf("    ------------------------------------------------------------------------------------\n");
            printf("    |No|                   STUDENT NAME                  |         MAJOR        |  GPA | \n" );
            printf("    ------------------------------------------------------------------------------------\n");
            for (a = 0; a < count; a++){
            printf("    |%2i| %-47s | %-20s | %4.2lf |\n", a+1, murid[a].name, murid[a].major, murid[a].gpa);
            }
            printf("    ------------------------------------------------------------------------------------ \n");
            printf ("\n");
        }
            break;
    case 2 :
        if(count == 20){
            printf("\n");
            printf("    Database is Full\n");
            printf("\n");
        } else {
        printf("\n");
        printf("    ------------------------------\n");
        printf("      Insert Student Information \n");
        printf("    ------------------------------\n");
        printf("    Name    :");
        scanf( "    %[^\n]%*c", &murid[count].name);
        printf("    Major   :");
        scanf( "    %[^\n]%*c", &murid[count].major);
        printf("    GPA     :");
        scanf( "    %lf", &murid[count].gpa);
        printf("\n");
        count++;
    }
        break;
    case 3:
        printf("\n");
        printf("    Press Any Button To Close The Program");
        printf("\n");
        keep = 0;
        break;

    default:
        printf("Invalid\n");
        break;
    }

    }
}




