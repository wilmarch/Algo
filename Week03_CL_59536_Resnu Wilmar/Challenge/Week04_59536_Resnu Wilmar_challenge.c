#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct Request {
  char name[50];
  char nim[25];
  char major[25];
  char angkatan[5];
  char gedung;
  char noRuang[5];
} Request;

typedef struct Node {
  Request data;

  struct Node *next;
} Node;

int menu() {
  int menu;
  printf("=========================\n");
  printf(" Menu Peminjaman Ruangan\n");
  printf("=========================\n");
  printf("1. Pinjam ruangan\n"
         "2. List ruangan yang dipinjam\n"
         "3. Hapus list ruangan yang dipinjam (Clear All)\n"
         "4. Exit\n");
  printf("Input : ");
  scanf("%i%*c", &menu);
  return menu;
}

void newReq(Node **head) {
  printf("\n");
  Request data;
  Node *node = (Node *)malloc(sizeof(Node));
  printf("===============================\n");
  printf(" Input Data Peminjaman Ruangan \n");
  printf("===============================\n");
  printf("%-15s : ", "Nama");
  scanf("%[^\n]%*c", data.name);
  printf("%-15s : ", "NIM");
  scanf("%[^\n]%*c", data.nim);
  printf("%-15s : ", "Program Studi");
  scanf("%[^\n]%*c", data.major);
  printf("%-15s : ", "Angkatan");
  scanf("%[^\n]%*c", data.angkatan);
  printf("%-15s : ", "Gedung (A-D)");
  scanf("%c%*c", &data.gedung);
  printf("%-15s : ", "Nomor Ruangan");
  scanf("%[^\n]%*c", data.noRuang);

  node->data = data;

  if (*head == NULL) {
    *head = node;
  } else {
    node->next = *head;
    *head = node;
  }
  printf("\n");
}

void printReq(Node *head) {
  int count = 0;
  if (head == NULL) {
    printf("\nData kosong!\n");
    return;
  }
  printf("-----------------------------------\n");
  while (head != NULL) {
    Request data = head->data;
    printf("Data ke-%i\n", ++count);
    printf("%-9s : %s\n", "Nama", data.name);
    printf("%-9s : %s\n", "NIM", data.nim);
    printf("%-9s : %s\n", "Prodi", data.major);
    printf("%-9s : %s\n", "Angkatan", data.angkatan);
    printf("%-9s : %c%s\n", "Ruangan", data.gedung, data.noRuang);
    printf("%-9s : %s\n", "Status", "Unapproved");
    head = head->next;
    printf("-----------------------------------\n\n");
  }
}

void clearReq(Node **head) {
  if (*head == NULL) {
    printf("\nData masih kosong!\n\n");
    return;
  }

  Node *temp = (Node *)malloc(sizeof(Node));
  while (*head != NULL) {
    temp = *head;
    *head = temp->next;
    temp->next = NULL;
    free(temp);
  }
  printf("\nData berhasil dibersihkan!\n\n");
}

int main() {
  Node *head = NULL;

  while (1) {
    switch (menu()) {
    case 1:
      newReq(&head);
      break;
    case 2:
      printReq(head);
      break;

    case 3:
      clearReq(&head);
      break;

    case 4:
      return 0;

    default:
      // TODO
      break;
    }
  }
}
