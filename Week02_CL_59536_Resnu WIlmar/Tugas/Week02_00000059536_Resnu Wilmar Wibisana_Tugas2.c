#include <stdio.h>
#include <string.h>

#define max_user 100
typedef enum {FALSE, TRUE} bool;

typedef struct {
  char name[50];
  char major[30];
  char nim[25];
} Student;

typedef struct {
  char nim[25];
  int uas;
  int uts;
  int tugas;
  float gpa;
  char grade[2];
} StudentGrade;

typedef struct {
  Student student[max_user];
  StudentGrade grade[max_user];
  int count;
} Students;

void addStudent(Students *db);
int menu(int count);
void printInfo(Students db);
void printGrades(Students db);
void calculateGrade(StudentGrade *student);
void readFile(Students *db);
void saveFile(Students db);

int main() {
  Students db;
  db.count = 0;
  readFile(&db);

  int keepGoing = TRUE;
  while (keepGoing) {
    switch (menu(db.count)) {
    case 1:
      printInfo(db);
      break;
    case 2:
      printGrades(db);
      break;
    case 3:
      if (db.count >= max_user) {
        printf("Database is full\n");
        break;
      }
      addStudent(&db);
      saveFile(db);
      db.count++;
      break;

    case 4:
      keepGoing = FALSE;
      break;

    default:
      printf("Invalid input\n\n");
      break;
    }
  }
}

void readFile(Students *db) {
  FILE *data = fopen("dataMahasiswa.txt", "r");
  FILE *nilai = fopen("nilaiMahasiswa.txt", "r");

  while (!(feof(data) && feof(nilai))) {
    Student newStudent;
    StudentGrade newGrade;

    fscanf(data, "%[^#]#%[^#]#%[^\n\r]\n", newStudent.nim, newStudent.name,
           newStudent.major);

    fscanf(nilai, "%[^#]#%i#%i#%i#%f#%[^\n\r]\n", newGrade.nim, &newGrade.tugas,
           &newGrade.uts, &newGrade.uas, &newGrade.gpa, newGrade.grade);

    db->student[db->count] = newStudent;
    db->grade[db->count] = newGrade;
    db->count++;
  }
  fclose(data);
  fclose(nilai);
}

void saveFile(Students db) {
  FILE *data = fopen("dataMahasiswa.txt", "w");
  FILE *nilai = fopen("nilaiMahasiswa.txt", "w");


  for (int i = 0; i <= db.count; i++) {
    Student student = db.student[i];
    StudentGrade grade = db.grade[i];
    fprintf(data, "%s#%s#%s\n", student.nim, student.name, student.major);
    fprintf(nilai, "%s#%i#%i#%i#%f#%s\n", grade.nim, grade.tugas, grade.uts,
            grade.uas, grade.gpa, grade.grade);
  }
  fclose(data);
  fclose(nilai);
  printf("Data Saved!\n\n");
}

void addStudent(Students *db) {
  Student data;
  StudentGrade grade;

  printf("\n");
  printf("    INSERT STUDENT INFORMATION  \n");
  printf("  ------------------------------\n");

  printf("  Name        : ");
  scanf("   %[^\n]%*c", data.name);
  printf("  Major       : ");
  scanf("   %[^\n]%*c", data.major);
  printf("  NIM         : ");
  scanf("   %[^\n]", data.nim);
  fflush(stdin);

  strcpy(grade.nim, data.nim);

  printf("      INSERT STUDENT GRADES     \n");
  printf("  ------------------------------\n");

  printf("  Assignments : ");
  scanf("%i%*c", &grade.tugas);
  printf("  UTS         : ");
  scanf("%i%*c", &grade.uts);
  printf("  UAS         : ");
  scanf("%i%*c", &grade.uas);
  fflush(stdin);
  calculateGrade(&grade);

  db->student[db->count] = data;
  db->grade[db->count] = grade;

  printf("\n\n");
}

void calculateGrade(StudentGrade *student) {
  student->gpa =
      (student->tugas * 0.4) + (student->uts * 0.25) + (student->uas * 0.35);

  float gpa = student->gpa;

  if (gpa >= 95 && gpa <= 100) {
    strcpy(student->grade, "A+");
  }
  if (gpa < 95 && gpa >= 85) {
    strcpy(student->grade, "A");
  }
  if (gpa < 85 && gpa >= 80) {
    strcpy(student->grade, "A-");
  }
  if (gpa < 80 && gpa >= 75) {
    strcpy(student->grade, "B+");
  }
  if (gpa < 75 && gpa >= 70) {
    strcpy(student->grade, "B");
  }
  if (gpa < 70 && gpa >= 65) {
    strcpy(student->grade, "C");
  }
  if (gpa < 65 && gpa >= 60) {
    strcpy(student->grade, "C-");
  }
  if (gpa < 60 && gpa >= 55) {
    strcpy(student->grade, "D");
  }
  if (gpa < 55) {
    strcpy(student->grade, "E");
  }
}

int menu(int count) {
  int menu;
  printf("  Welcome To Simple Student Database (%i/%i)\n\n", count, max_user);
  printf("  1. Show All Students\n");
  printf("  2. Show All Grades\n");
  printf("  3. Input New Student\n");
  printf("  4. Exit\n\n");
  printf("  Choose: ");
  scanf("   %i%*c", &menu);
  return menu;
}

void printInfo(Students db) {
  if (db.count == 0) {
    printf("\n");
    printf("Database Is Empty\n");
    printf("\n");
    return;
  }
  printf(
      "                     List of Student Information                  \n");
  printf(
      "------------------------------------------------------------------\n");
  printf(
      "|No |           Name           |       Major       |     NIM     |\n");
  printf(
      "------------------------------------------------------------------\n");

  for (int i = 0; i < db.count; i++) {
    Student data = db.student[i];
    printf("|%-3i| %-25s| %-18s| %-12s|\n", i + 1, data.name, data.major,
           data.nim);
  }
  printf(
      "------------------------------------------------------------------\n");
  printf("\n\n");
}

void printGrades(Students db) {
  if (db.count == 0) {
    printf("\n");
    printf("Data still empty\n");
    printf("\n");
    return;
  }
  printf("                  List of Student Grades                       \n");
  printf("------------------------------------------------------------------\n");
  printf("|No |      NIM       | Assignments | UTS | UAS |  GPA  | Grades  |\n");
  printf("------------------------------------------------------------------\n");

  for (int i = 0; i < db.count; i++) {
    StudentGrade data = db.grade[i];
    printf("|%-3i| %-15s| %-12i| %-4i| %-4i| %-6.2f| %-8s|\n", i + 1, data.nim,
           data.tugas, data.uts, data.uas, data.gpa, data.grade);
  }
  printf("------------------------------------------------------------------\n");
  printf("\n\n");
}
