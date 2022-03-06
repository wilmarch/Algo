#include <stdio.h>
#include <string.h>

void strUppercase(char *str, int len){
  for(int i=0; i<len; i++){
    if(str[i] >= 'a' && str[i] <= 'z'){
      str[i] -= 32;
    }
  }
}

void strLowercase(char *str, int len){
  for(int i = 0; i < len; i++){
    if(str[i] >= 'A' && str[i] <= 'Z'){
      str[i] += 32;
    }
  }
}

void strSwitching(char *str, int len) {
  for(int i = 0; i < len; i++){
    if(str[i] >= 'A' && str[i] <= 'Z'){
      str[i] += 32;
    }
    else if (str[i] >= 'a' && str[i] <= 'z'){
      str[i] -= 32;
    }
  }
}

int main(){
  while (1){
    int menu;
    char kata[50];

    printf("1. Uppercase\n");
    printf("2. Lowercase\n");
    printf("3. Switching\n");
    printf("4. Exit\n");
    printf("Pilihan : ");

    scanf("%i%*c", &menu);
    if(menu >= 4){
      break;
    }

    printf("Masukkan kata: ");
    scanf("%[^\n]%*c", kata);
    int len = strlen(kata);

    switch (menu){
    case 1:
      strUppercase(kata, len);
      break;
    case 2:
      strLowercase(kata, len);
      break;
    case 3:
      strSwitching(kata, len);
      break;
    }

    printf("%s\n\n", kata);
  }
}
