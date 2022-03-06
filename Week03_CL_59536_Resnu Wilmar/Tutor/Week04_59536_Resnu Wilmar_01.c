#include <malloc.h>
#include <stdio.h>

int main() {
  // Bikin array 3 dimensi
  // Dimensi pertama
  int ***arr = (int ***)malloc(sizeof(int **) * 10);
  for (int i = 0; i < 10; i++) {
    // Dimensi kedua
    arr[i] = (int **)malloc(sizeof(int *) * 10);
    for (int j = 0; j < 10; j++) {
      // Dimensi ketiga
      arr[i][j] = (int *)malloc(sizeof(int) * 10);
    }
  }

  int count = 0;

  // Isi elemennya dari 1 sampai 1000 dalam array
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      for (int k = 0; k < 10; k++)
        arr[i][j][k] = ++count;

  // Print arraynya
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        printf("%d ", arr[i][j][k]);
      }
    }
  }
}
