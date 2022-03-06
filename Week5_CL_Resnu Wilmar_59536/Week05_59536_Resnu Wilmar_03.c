#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *bil, int n){
    int i, j, temp;

    for(i=1; i<n; i++){
        temp = bil[i];
        for(j = i-1; j>=0 && bil[j] > temp; j--){
            bil[j+1] = bil[j];
        }

        bil[j+1] = temp;
    }
}

int main(int argc, char const *argv[]){
    int i, j, temp;
    int n;
    int *bil;

    //Menentukan banyak data------------
    printf("Banyak bilangan: ");
    scanf("%d", &n);

    //Proses alokasi memori-------------
    bil = (int*) malloc(sizeof(int)*n);

    //Proses memasukan data-------------
    for(i=0; i<n; i++){
        printf("Input bilangan ke-%d: ", i+1);
        scanf("%d", &bil[i]);
    }
    printf("\n");

    //Menjalankan algoritma Insertion sort---------
    insertionSort(bil, n);

    //Proses mengeluarkan data yang sudah terurut------
    printf("Hasil sort: ");
    for(i=0; i<n; i++){
        printf("%d ", bil[i]);
    }
    printf("\n");

    //Proses pembebasan memori---------
    free(bil);

    return 0;
}
