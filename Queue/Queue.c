#include <stdio.h>
#include <stdlib.h>

/*Enqueue (Ekleme): Kuyruğa bir eleman ekleme işlemi.
Dequeue (Çıkarma): Kuyruğun en önündeki elemanı çıkarma işlemi.
Peek (Ön Elemanı Görme): Kuyruğun en önündeki elemanı çıkarılmadan görme işlemi.
IsEmpty (Boş mu Kontrolü): Kuyruğun boş olup olmadığını kontrol etme işlemi.
IsFull (Dolu mu Kontrolü): Kuyruğun dolu olup olmadığını kontrol etme işlemi.*/

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

// Queue başlatma fonksiyonu
void initializeQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

// Kuyruğa eleman ekleme (Enqueue)
void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Kuyruga eklenen eleman: %d\n", value);
}

// Kuyruktan eleman çıkarma (Dequeue)
int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Kuyruk bos\n");
        return -1;
    }
    int dequeuevalue = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    printf("Kuyruktan cikarilan eleman: %d\n", dequeuevalue);
    return dequeuevalue;
}

// Kuyruğun en önündeki elemanı görme (Peek)
int peek(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Kuyruk bos\n");
        return -1;
    }
    return q->front->data;
}

// Kuyruğu ekrana yazdırma
void display(Queue *q)
{
    Node *temp = q->front;
    if (temp == NULL)
    {
        printf("Kuyruk bos\n");
    }
    else
    {
        printf("Kuyruktaki elemanlar: ");
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    dequeue(&q);
    display(&q);

    printf("En ondeki eleman: %d\n", peek(&q));

    enqueue(&q, 40);
    display(&q);

    return 0;
}