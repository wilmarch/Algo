#include <stdio.h>

int hitungJumlah(int *jumlah, int numbers []){
    int i=0;
    for(i=0; i<5; i++){
        *jumlah += numbers[1];

    }
}

int main(){

 int randomNumber[5] = {1, 2, 3, 4};
 int jumlah = 0;

hitungJumlah(&jumlah, randomNumber);
printf("Jumlah = %d\n", jumlah);

return 0;

}
