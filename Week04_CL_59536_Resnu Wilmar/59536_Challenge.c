#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef enum { FALSE, TRUE } bool;
int nodeCount = 0;

typedef struct Request {
  char name[50];
  char nim[25];
  char major[25];
  char angkatan[5];
  char gedung;
  int noRuang;
  bool approve;
} Request;

typedef struct Node {
  Request data;

  struct Node *next, *prev;
} Node;

int menu() {
  int menu;
  printf("=========================\n");
  printf(" Menu Peminjaman Ruangan\n");
  printf("=========================\n");
  printf("1. Pinjam ruangan\n"
         "2. List ruangan yang dipinjam\n"
         "3. Hapus list ruangan yang dipinjam (Clear All)\n"
         "4. Menyetujui Ruangan\n"
         "5. Batalkan peminjaman ruangan\n"
         "6. Exit\n");
  printf("Input : ");
  scanf("%i%*c", &menu);
  system("cls");
  return menu;
}

int checkDuplicate(Node *head, Node *tail, Request newData) {
  for (int i = 0; i < nodeCount; i++) {
    Request currData = head->data;
    if ((currData.gedung == newData.gedung) &&
        (currData.noRuang == newData.noRuang)) {
      return 1;
    }
    head = head->next;
  }
  return 0;
}

Request newReq() {
    system("cls");
  printf("\n");
  Request data;
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
  scanf("%i%*c", &data.noRuang);
  data.approve = FALSE;

  printf("\n");
  system("cls");

  return data;
}

void addNode(Request data, Node **head, Node **tail) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  if (*head == NULL) {
    *head = *tail = node;
    (*head)->next = (*tail)->prev = node;
  } else {
    if (checkDuplicate(*head, *tail, data)) {
      printf("\nRuangan telah dipinjam!\n"
             "Membatalkan input...\n\n");
      return;
    }

    node->next = *head;
    node->prev = *tail;
    (*head)->prev = node;
    (*tail)->next = node;
    *tail = node;
  }
  nodeCount++;
}

void printReq(Node *head, Node *tail) {
  int count = 0;
  if (head == NULL) {
    printf("\nData Still Empty!\n");
    return;
  }
  printf("-----------------------------------\n");
  for (int i = 0; i < nodeCount; i++) {
    Request data = head->data;
    printf("Data ke-%i\n", ++count);
    printf("%-9s : %s\n", "Nama", data.name);
    printf("%-9s : %s\n", "NIM", data.nim);
    printf("%-9s : %s\n", "Prodi", data.major);
    printf("%-9s : %s\n", "Angkatan", data.angkatan);
    printf("%-9s : %c%i\n", "Ruangan", data.gedung, data.noRuang);
    printf("%-9s : %s\n", "Status", data.approve ? "Approved" : "Unapproved");
    head = head->next;
    printf("-----------------------------------\n\n");

  }
}

void reqApproval(Node **head, Node **tail) {
  Node *curr = *head;
  bool keepGoing = 1;
  int count = 0, menu;
  while (keepGoing) {
    Request data = curr->data;
    if (curr == *head)
      count = 1;
    if (curr == *tail)
      count = nodeCount;

    printf("=================================\n"
           "       Penyetujuan Ruangan       \n"
           "=================================\n");
    printf("%-9s : %i/%i\n", "Nomor", count, nodeCount);
    printf("%-9s : %s\n", "Nama", data.name);
    printf("%-9s : %s\n", "NIM", data.nim);
    printf("%-9s : %s\n", "Prodi", data.major);
    printf("%-9s : %s\n", "Angkatan", data.angkatan);
    printf("%-9s : %c%i\n", "Ruangan", data.gedung, data.noRuang);
    printf("%-9s : %s\n", "Status", data.approve ? "Approved" : "Unapproved");

    printf("Menu :\n"
           "1. Next\n"
           "2. Prev\n"
           "3. Approve\n"
           "4. Exit\n"
           "Pilihan : ");
    scanf("%i", &menu);
    system("cls");
    switch (menu) {
    case 1:
      curr = curr->next;
      count++;
      break;
    case 2:
      curr = curr->prev;
      count--;
      break;
    case 3:
      if (curr->data.approve)
        curr->data.approve = FALSE;
      else
        curr->data.approve = TRUE;
      break;
    case 4:
      return;
    default:
      printf("Menu tidak ditemukan!");
      break;
    }
  }
}

void reqDelete(Node **head, Node **tail) {

  Node *curr = *head;
  bool keepGoing = 1;
  int count = 0, menu;
  while (keepGoing) {
    Request data = curr->data;
    if (curr == *head)
      count = 1;
    if (curr == *tail)
      count = nodeCount;

    printf("=================================\n"
           "        Pembatalan Ruangan       \n"
           "=================================\n");
    printf("%-9s : %i/%i\n", "Nomor", count, nodeCount);
    printf("%-9s : %s\n", "Nama", data.name);
    printf("%-9s : %s\n", "NIM", data.nim);
    printf("%-9s : %s\n", "Prodi", data.major);
    printf("%-9s : %s\n", "Angkatan", data.angkatan);
    printf("%-9s : %c%i\n", "Ruangan", data.gedung, data.noRuang);
    printf("%-9s : %s\n", "Status", data.approve ? "Approved" : "Unapproved");

    printf("Menu :\n"
           "1. Next\n"
           "2. Prev\n"
           "3. Cancel\n"
           "4. Exit\n"
           "Pilihan : ");
    scanf("%i", &menu);
    system("cls");
    switch (menu) {
    case 1:
      curr = curr->next;
      count++;
      break;
    case 2:
      curr = curr->prev;
      count--;
      break;
    case 3:
      printf("Deleting...\n\n");
      Node *temp = curr;
      curr = curr->next;
      if (temp == *head)
        *head = temp->next;
      if (temp == *tail)
        *tail = temp->prev;

      if (temp->next != NULL)
        temp->next->prev = temp->prev;
      if (temp->prev != NULL)
        temp->prev->next = temp->next;

      temp->next = temp->prev = NULL;
      free(temp);
      nodeCount--;
      break;
    case 4:
      return;
    default:
      printf("Menu Invalid!");
      break;
    }
  }
}

void clearReq(Node **head) {
  if (*head == NULL) {
    printf("\nData Still Empty!\n\n");
    return;
  }

  Node *temp = (Node *)malloc(sizeof(Node));
  while (*head != NULL) {
    temp = *head;
    *head = temp->next;
    temp->next = NULL;
    free(temp);
  }
  printf("\nData Clear!\n\n");
}

int main() {
  Node *head = NULL;
  Node *tail = NULL;

  while (1) {
    Request data;
    switch (menu()) {
    case 1:
      data = newReq();
      addNode(data, &head, &tail);
      break;
    case 2:
      printReq(head, tail);
      break;

    case 3:
      clearReq(&head);
      break;

    case 4:
      reqApproval(&head, &tail);
      break;

    case 5:
      reqDelete(&head, &tail);
      break;

    case 6:
      printf("Thanks for using this program!\n\n");
      return 0;

    default:
      printf("\nMenu Invalid!\n\n");
      break;
    }
  }
}
