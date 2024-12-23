#include <stdio.h>
#include <stdlib.h>

struct node                     // yapı oluşturma
{
    int data;
    struct node * next; 
};

int main () {

    //düğüm oluşturma ve bellekte yer ayırma

    struct node * node1;
    node1= (struct node *) malloc(sizeof(struct node));

    struct node * node2;
    node2= (struct node *) malloc(sizeof(struct node));

    struct node * node3;
    node3= (struct node *) malloc(sizeof(struct node));

    struct node * node4;
    node4= (struct node *) malloc(sizeof(struct node));

    // veri girişi ve bir sonraki düğüme bağlama

    node1->data=11;
    node2->data=22;
    node3->data=33;
    node4->data=44;

    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=NULL;

    printf("%d - %d - %d - %d",node1->data,node2->data,node3->data,node4->data);

    return 0;
}