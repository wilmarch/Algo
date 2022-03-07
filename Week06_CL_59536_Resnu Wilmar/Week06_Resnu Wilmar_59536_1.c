#include <stdio.h>
#include <malloc.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *bil, int l, int r)
{
    int pivot = bil[r];
    int i = l - 1;
    int j;
    for (j = l; j <= r - 1; j++)
    {
        if (bil[j] >= pivot)
        {
            i++;
            swap(&bil[i], &bil[j]);
        }
    }
    swap(&bil[i + 1], &bil[r]);
    return (i + 1);
}

void quickSort(int *bil, int l, int r)
{
    if (l < r)
    {
        int pi = partition(bil, l, r);
        quickSort(bil, l, pi - 1);
        quickSort(bil, pi + 1, r);
    }
}
int main(int argc, char const *argv[])
{
    int *bil, i, n;

    printf("Jumlah bilangan: ");
    scanf("%d", &n);
    bil = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        printf("Masukkan bilangan : ");
        scanf("%d", &bil[i]);
    }
    quickSort(bil, 0, n - 1);

    printf("Hasil pegurutan: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", bil[i]);
    }
    return 0;
}
