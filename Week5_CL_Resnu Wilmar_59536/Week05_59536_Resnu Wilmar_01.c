#include <stdio.h>
#include <stdlib.h>

void swap(int *bil1, int *bil2){
    int temp = *bil1;
    *bil1 = *bil2;
    *bil2 = temp;
}

void bubbleSort(int *bil, int n){
    int i,j;

    for(i=1; i<n; i++){                          //Jumlah banyak iterasi
        for(j=n-1; j >= 1; j--){                 //Jumlah pengecekan yang dilakukan iterasi
            if(bil[j] < bil[j-1]){               //Pengecekan untuk ascending
                swap(&bil[j] , &bil[j-1]);
            }
        }
    }
}

int main(int argc, char const *argv[]){
    int i,n, *bil;

    printf("Banyak bilangan: ");
    scanf("%d", &n);
    bil = (int*) malloc(sizeof(int)*n);    //Alokasi memori sesuai kebutuhan

    for(i=0; i<n; i++){
        printf("Input bilangan ke-%d: ", i+1);
        scanf("%d", &bil[i]);
    }
    bubbleSort(bil, n);                           //Menjalankan algoritma bubble sort

    printf("Hasil sort: ");
    for(i=0; i<n; i++){
        printf("%d ", bil[i]);
    }
    printf("\n");
    free(bil);                                 //Free memory

    return 0;
}
