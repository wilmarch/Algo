#include <stdio.h>
#include <stdlib.h>

void swap(int *bil1, int *bil2){
    int temp;

    temp = *bil1;
    *bil1 = *bil2;
    *bil2 = temp;
}

void selectionSort(int *bil, int n){
    int i, j, temp;

    for(i = 0; i < n; i++){
        //Menempatkan element di index ke-1 sebagai nilai minimum------
        temp = i;

        //pengecekan nilai minimum terhadap elemen selanjutnya-----
        for(j = i+1; j < n; j++){
            if(bil[j] < bil[temp])
                temp = j;
        }

        //Melakukan pertukaran-----
        if(temp != i)
            swap(&bil[temp], &bil[i]);
    }
}

int main(int argc, char const *argv[]){
    int i;
    int n;
    int *bil;

    //Menentukan banyak data-----
    printf("Banyak bilangan: ");
    scanf("%d", &n);

    //Proses memasukan data-----
    for(i = 0; i < n; i++){
        printf("Input bilangan ke-%d: ", i+1);
        scanf("%d", &bil[i]);
    }
    printf("\n");

    //Menjalankan algoritma selection sort-----
    selectionSort(bil, n);

    //Proses mengeluarkan data yang sudah terurut-----
    printf("Hasil Sort: ");
    for(i = 0; i < n; i++){
        printf("%d ", bil[i]);
    }
    printf("\n");

    //proses pembebasan memori-----
    free(bil);

    return 0;
}
