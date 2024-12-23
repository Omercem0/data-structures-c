#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Kuyruğun maksimum boyutu

typedef struct
{
    int items[MAX];
    int front, rear;
} Queue;

// Queue başlatma fonksiyonu
void initializeQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Queue boş mu kontrolü
int isEmpty(Queue *q)
{
    return q->front == -1;
}

// Queue dolu mu kontrolü
int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

// Kuyruğa eleman ekleme (Enqueue)
void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Kuyruk dolu! Eleman eklenemedi.\n");
    }
    else
    {
        if (isEmpty(q))
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Kuyruga eklenen eleman: %d\n", value);
    }
}

// Kuyruktan eleman çıkarma (Dequeue)
int dequeue(Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Kuyruk boş! Eleman çikarilamadi.\n");
        return -1;
    }
    else
    {
        item = q->items[q->front];
        if (q->front >= q->rear)
        {
            // Son eleman da çıkarıldığında kuyruğu sıfırla
            q->front = q->rear = -1;
        }
        else
        {
            q->front++;
        }
        printf("Kuyruktan cikarilan eleman: %d\n", item);
        return item;
    }
}

// Kuyruğun en önündeki elemanı görme (Peek)
int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Kuyruk boş!\n");
        return -1;
    }
    else
    {
        return q->items[q->front];
    }
}

// Kuyruğu ekrana yazdırma
void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Kuyruk boş!\n");
    }
    else
    {
        printf("Kuyruktaki elemanlar: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->items[i]);
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
    enqueue(&q, 50);
    enqueue(&q, 60); // Bu ekleme başarısız olacak çünkü kuyruk dolu.
    display(&q);

    return 0;
}
