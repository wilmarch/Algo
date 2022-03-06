#include <stdio.h>
#include <malloc.h>

struct tnode {
    int data;
    struct tnode *next;
};

int main(int argc, char const *argv[]) {
    int bil, n, inp=1;
    struct tnode *head, *node, *tail, *curr;

    head = NULL;

    printf("Masukkan jumlah data: "); scanf("%d", &n);

    while(n > 0) {
        printf("Masukkan bil ke-%d = ", n); scanf("%d", &bil);

        node = (struct tnode*) malloc(sizeof(struct tnode));
        node->data = bil;

        if(head == NULL){
            head = node;
            tail = node;
            tail->next = NULL;
            head->next = NULL;
        }
        else {
            tail->next = node ;
            tail = node;
            tail->next = head;
        }
        n--;
    }
    curr = head;

    while(inp){
        system("cls");
        printf("%d\n", curr->data);
        printf("1. Maju\n");
        printf("0. Keluar\n");
        printf("Pilihan: "); scanf("%d", &inp);

        if(inp == 1){
            curr = curr->next;
        }
        else if(inp > 1 || inp < 0){
                printf("Maaf input salah !\n");
                getch();
            }
    };
    return 0;
}
