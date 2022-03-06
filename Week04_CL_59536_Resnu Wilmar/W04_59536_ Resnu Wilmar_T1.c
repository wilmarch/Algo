#include <stdio.h>
#include <malloc.h>

struct tnode {
    int data;
    struct tnode *next, *prev;
};

int main(int argc, char const *argv[]) {
    int bil, n, inp=1;
    struct tnode *head, *node, *tail, *curr;

    head = NULL;

    printf("Masukkan jumlah data: "); scanf("%d", &n);

    while(n > 0) {
        printf("Masukkan bil = "); scanf("%d", &bil);

        node = (struct tnode*) malloc(sizeof(struct tnode));
        node->next = NULL;
        node->prev = NULL;
        node->data = bil;

        if(head == NULL){
            head = node;
            tail = node;
        }
        else {
            tail->next = node ;
            node->prev = tail;
            tail = node;
        }
        n--;
    }
    curr = head;

    while(1){
        system("cls");
        printf("%d\n", curr->data);
        printf("1. Maju\n");
        printf("2. Mundur\n");
        printf("0. Keluar\n");
        printf("Pilihan: "); scanf("%d", &inp);

        if(inp == 1){
            if(curr->next == NULL) {
            printf("Tidak dapat maju karena node selanjutnya kosong\n");
            getch();
            }
            else curr=curr->next;
        }
        else if(inp == 2){
            if(curr->prev == NULL){
                printf("tidak dapat mundur karena node sebelumnya kosong\n");
                getch();
                }
                else curr=curr->prev;
                }
                else if(!inp) break;
        };

        return 0;
    }
