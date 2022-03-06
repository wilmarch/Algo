#include <stdio.h>
#include <stdlib.h>

struct linkedList{
    int value;
    struct linkedList *next;
};

//function untuk membuat node baru dan insert ke belakang linked list
void insertNode(int val, struct linkedList **Head){ //Head merupakan bucket[i]

    //Membuat node baru
    struct linkedList *temp = (struct linkedList*) malloc(sizeof(struct linkedList));
    temp->value =val;
    temp->next = NULL;

    //Jika bucket[i] masih kosong
    if(*Head == NULL){
        *Head = temp;
    }
    else{
        struct linkedList *ptr = *Head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

int main(int argc, char const *argv[]){
    int i, j, n, data[100], maks;

    //*bucket sebagai *Head pada RadixSort
    //Karena menginginkan sort integer (0-9), jadi terdapat 10 Head (array of linked list)
    struct linkedList *bucket[10];
    for(i=0; i<10; i++){
        bucket[i] = NULL;  //Inisialisaso semua bucket menjadi NULL
    }

    //Input data
    printf("Masukan jumlah data yang akan di sort: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Masukan data ke-%d: ", i+1);
        scanf("%d", &data[i]);
        if(i == 0 || maks < data[i]){
            maks = data[i];
        }
    }
    //Menentukan Jumlah iterasi
    int totalIterasi = 0;
    while(maks > 0){
        maks /= 10;
        totalIterasi++;
    }
    printf("\nTotal iterasi yang akan dilakukan: %d\n", totalIterasi);

    //Iterasi sebanyak total iterasi yang didapat
    int pembagi = 1;
    for(i=0; i<totalIterasi; i++){
        //Masukan data dari array ke bucket yang sesuai
        for(j=0; j<n; j++){
            int digit = (data[j] / pembagi) % 10;  //Mendapatkan digit untuk dimasukkan ke bucket
            insertNode(data[j], &bucket[digit]);
        }
        pembagi *= 10;  //Untuk bisa mendapatkan digit selanjutnya di iterasi berikutnya

        //Start output isi bucket sementara
        printf("\n=====\nIterasi %d\n", i+1);
        for(j=0; j<10; j++){
            printf("Bucket[%d] : ", j);
            struct linkedList *ptr = bucket[j];
            while(ptr != NULL){
                printf("%d, ", ptr->value);
                ptr = ptr->next;
            }
            printf("\n");
        }
        //End output

        //Start pindahkan kembali data dari bucket ke array
        int idx=0;
        for(j=0; j<10; j++){
            struct linkedList *ptr = bucket[j];
            while(ptr != NULL){
                data[idx] = ptr->value;
                idx++;
                ptr = ptr->next;
            }
        }
        //End pindah data

        //Start output isi array
        printf("Hasil array sementara: ");
        for(j=0; j<n; j++){
            printf("%d, ", data[j]);
        }
        printf("\n=====\n\n");
        //End output isi array

        //Start kosongkan bucket
        for(j=0; j<10; j++){
            struct linkedList *temp, *ptr = bucket[j];
            while(ptr != NULL){
                temp = ptr;
                ptr = ptr->next;
                free(temp);
            }
            bucket[j] = NULL;
        }
        //End kosongkan bucket
    }
    //End radix sort

    //Output hasil
    printf("Hasil setelah di sort: ");
    for(i=0; i<n; i++){
        printf("%d, ", data[i]);
    }
    printf("\n");

    return 0;
}
