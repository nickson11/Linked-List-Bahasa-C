#include <stdio.h>
#include <stdlib.h>

struct Node
{
int isian;
struct Node *next;
};

int main() {
int pilihan;
    printf("Crazy Linked List \n");
    printf("=================");
    printf("\n1. Input Data");
    printf("\n2. Keluar");
    printf("\npilihan : ");
    scanf("%d",&pilihan);
    printf("================= \n");
    switch(pilihan) {
    case 1:
        cetak();
        break;
    case 2:
        printf("Terima Kasih :D ");
        return 0;
    default :
        return 0;
}
}


void masuk(struct Node** head_ref, int new_isian)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->isian = new_isian;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


void isi(struct Node** head_ref, int new_isian)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *head_ref;
	new_node->isian = new_isian;
	new_node->next = NULL;
        if (*head_ref == NULL)
        {
        *head_ref = new_node;
        return;
        }

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	return;
}

void sisipkan(struct Node* prev_node, int new_isian)
{
	if (prev_node == NULL){
	printf("Node selanjutnya tidak boleh kosong !");
	return;
	}
	struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
	new_node->isian = new_isian;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void cetak()
{
    struct Node* head = NULL;
    int awal,akhir,baru,sisip,hasil;
    printf("\n");
    printf("Masukkan Data Awal : ");
    scanf("%d",&awal);
    printf("Masukkan Data Akhir : ");
    scanf("%d",&akhir);
    printf("Sisipkan Data Baru : ");
    scanf("%d",&baru);
    isi(&head, baru);
    masuk(&head, awal);
    isi(&head, akhir);

    printf("\nNilai Linked List Sekarang : ");
    tampil(head);
    printf("\nSisipkan Data : ");
    scanf("%d",&sisip);
    sisipkan(head->next, sisip);
    printf("\nNilai Linked List Sekarang : ");
    tampil(head);
    while (head == head){
        printf("\nSisipkan Isian : ");
        scanf("%d",&hasil);
        sisipkan(head->next , hasil);
        printf("\nNilai Linked List Sekarang : ");
        tampil(head);
    }

return 0;
}

void tampil (struct Node *node)
{
    while (node != NULL)
    {
	printf(" %d ", node->isian);
	node = node->next;
    }
}


