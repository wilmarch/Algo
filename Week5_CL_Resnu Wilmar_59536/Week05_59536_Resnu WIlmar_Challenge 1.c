#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define MAX_USERS 10

typedef enum { FALSE, TRUE } bool;


typedef struct {
  char nama[75];
  int tinggi;
  int berat;
} Person;

typedef struct {
  Person *data;
  int used;
} DB;


void swap(Person *a, Person *b) {
  Person temp = *a;
  *a = *b;
  *b = temp;
}


void printDB(DB input) {
  if(input.used == 0) return;
  printf("Array's data currently\n"
         "======================\n");

  for (int i = 0; i < input.used; i++) {
    Person data = input.data[i];
    printf("%-7s : %i", "No.", i + 1);
    printf("%-7s : %s\n", "Nama", data.nama);
    printf("%-7s : %i\n", "Tinggi", data.tinggi);
    printf("%-7s : %i\n", "Berat", data.berat);
    printf("\n");
  }
}


int mainMenu(DB input) {
  int menu;
  printDB(input);
  printf("---------------------------\n"
         "          NESTED SORT     \n"
         "---------------------------\n");
  printf("1. Insert Data\n"
         "2. Bubble Sort\n"
         "3. Selection Sort\n"
         "4. Insertion Sort\n"
         "5. Exit\n"
         "Your choice: ");
  scanf("%d%*c", &menu);
  return menu;
}


void bubbleSort(Person **input, int n) {
  char choice;
  printf("Sort ascending (a) or descending (d)? ");
  scanf("%c%*c", &choice);
  choice = tolower(choice);

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n - 1; j++) {
      Person *curr = &(*input)[j];
      Person *next = &(*input)[j + 1];

      if (choice == 'a') {
        if (strcmp(curr->nama, next->nama) > 0) {
          swap(curr, next);
        } else if (strcmp(curr->nama, next->nama) == 0) {
          if (curr->tinggi > next->tinggi) {
            swap(curr, next);
          } else if (curr->tinggi == next->tinggi) {
            if (curr->berat > next->berat) {
              swap(curr, next);
            }
          }
        }
      } else if (choice == 'd') {
        if (strcmp(curr->nama, next->nama) < 0) {
          swap(curr, next);
        } else if (strcmp(curr->nama, next->nama) == 0) {
          if (curr->tinggi < next->tinggi) {
            swap(curr, next);
          } else if (curr->tinggi == next->tinggi) {
            if (curr->berat < next->berat) {
              swap(curr, next);
            }
          }
        }
      }
    }
  }
}


void selectionSort(Person **input, int n) {
  char choice;
  printf("Sort ascending (a) or descending (d)? ");
  scanf("%c%*c", &choice);
  choice = tolower(choice);

  for (int i = 0; i < n; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      Person *curr = &(*input)[j];
      Person *next = &(*input)[min];
      if (choice == 'a') {
        if (curr->tinggi < next->tinggi) {
          min = j;
        } else if (curr->tinggi == next->tinggi) {
          if (curr->berat < next->berat) {
            min = j;
          } else if (curr->berat == next->berat) {
            if (strcmp(curr->nama, next->nama) < 0) {
              min = j;
            }
          }
        }
      } else if (choice == 'd') {
        if (curr->tinggi > next->tinggi) {
          min = j;
        } else if (curr->tinggi == next->tinggi) {
          if (curr->berat > next->berat) {
            min = j;
          } else if (curr->berat == next->berat) {
            if (strcmp(curr->nama, next->nama) > 0) {
              min = j;
            }
          }
        }
      }
    }
    if (min != i) {
      swap(&(*input)[i], &(*input)[min]);
    }
  }
}



void insertionSort(Person **input, int n) {
  char choice;
  printf("Sort ascending (a) or descending (d)? ");
  scanf("%c%*c", &choice);
  choice = tolower(choice);

  for (int i = 1; i < n; i++) {
    int j;
    Person temp, *curr, *next;
    temp = (*input)[i];
    if (choice == 'a') {
      for (j = i - 1; j >= 0; j--) {
        curr = &(*input)[j];
        next = &(*input)[j + 1];
        if (curr->berat > temp.berat) {
          *next = *curr;
          continue;
        } else if (curr->berat == temp.berat) {
          if (strcmp(curr->nama, temp.nama) > 0) {
            *next = *curr;
            continue;
          } else if (strcmp(curr->nama, temp.nama) == 0) {
            if (curr->tinggi > temp.tinggi) {
              *next = *curr;
              continue;
            }
          }
        }
        break;
      }
    } else if (choice == 'd') {
      for (j = i-1; j >= 0; j--) {
        curr = &(*input)[j];
        next = &(*input)[j + 1];
        if (curr->berat < temp.berat) {
          *next = *curr;
          continue;
        } else if (curr->berat == temp.berat) {
          if (strcmp(curr->nama, temp.nama) < 0) {
            *next = *curr;
            continue;
          } else if (strcmp(curr->nama, temp.nama) == 0) {
            if (curr->tinggi < temp.tinggi) {
              *next = *curr;
              continue;
            }
            else {
              break;
            }
          }
        }
      }
    }
    (*input)[j+1]= temp;
  }
}


void addData(DB *inputDB) {
  Person input;
  printf("%-7s : ", "Nama");
  scanf("%[^\n]", input.nama);
  printf("%-7s : ", "Tinggi");
  scanf("%i", &input.tinggi);
  printf("%-7s : ", "Berat");
  scanf("%i", &input.berat);

  inputDB->data[inputDB->used] = input;
  inputDB->used++;
  printf("---------------------------\n"
         "\n");
}

int main() {
  DB inputDB;
  inputDB.data = (Person *)malloc(sizeof(Person) * MAX_USERS);
  inputDB.used = 0;

  bool keepGoing = TRUE;
  while (keepGoing) {
    switch (mainMenu(inputDB)) {
    case 1:
      addData(&inputDB);
      break;
    case 2:
      bubbleSort(&inputDB.data, inputDB.used);
      break;
    case 3:
      selectionSort(&inputDB.data, inputDB.used);
      break;
    case 4:
      insertionSort(&inputDB.data, inputDB.used);
      break;
    case 5:
      keepGoing = FALSE;
      break;
    }
  }
}
