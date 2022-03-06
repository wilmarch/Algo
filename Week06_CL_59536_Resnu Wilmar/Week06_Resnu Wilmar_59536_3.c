#include<stdio.h>
#include <stdlib.h>

void shellsort(int *arr, int n){
    int i, j, gap;

    for(gap = n/2; gap >0; gap /= 2){
        for(i = gap; i < n; i++){
        int temp = arr[i];{
        for(j = i; j >= gap && arr[j - gap] < temp; j -= gap)
            arr[j] = arr[j-gap];
         }
         arr[j] = temp;
        }
    }
}

int main(int argc, char const *argv[]){
    int i,n, *arr;
    printf("input N = ");
    scanf("%d", &n);
    arr = (int *) malloc(sizeof(int)*n);

    printf("Masukkan bilangan : ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[1]);
    }

    shellsort(arr, n);
    printf("Hasil Sort: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
