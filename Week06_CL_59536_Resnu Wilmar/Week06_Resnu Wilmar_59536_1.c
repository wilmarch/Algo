#include <stdio.h>
#include <malloc.h>

void swap(int *a, int*b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

int partition(int *bil, int l, int r)
{
    int pivot = bil[r];
    int i = l-1;

    for (int j=l; j<=r-1; j++)
    {
        if (bil[j] <= pivot)
        {
            i++;
            swap(&bil[i], &bil[j]);
        }
    }

    swap(&bil[i + 1], &bil[r]);

    return(i + 1);
}

void quicksort(int *bil, int l, int r)
{
    if (l < r)
    {
        int pi = partition(bil, l, r);

        quicksort(bil, l, pi - 1);
        quicksort(bil, pi + 1, r);
    }
}

int main(int argc, char const *argv[])
{
     int *bil;
     int n;
     int i;

     printf("Jumlah bilangan : ");
     scanf("&d", &n);

     bil = (int *)malloc(sizeof(int)*n);

     for(i = 0; i < n; i++)
     {
         scanf("%d", &bil[i]);
     }

     quicksort(bil, 0, n-1);

     printf("Hasil pengurutan: ");
     for(i = 0; i < n; i++)
     {
         printf("%d ", bil[i]);
     }

     return 0;
}

