#include <stdio.h> // Stack Array ile
#include <stdlib.h>
#define MAX 5 // Stack'in maksimum boyutu

typedef struct
{
    int items[MAX];
    int top;
} Stack;

// Stack başlatma fonksiyonu
void initializeStack(Stack *s)
{
    s->top = -1;
}

// Stack boş mu kontrolü
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Stack dolu mu kontrolü
int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

// Yığına eleman ekleme (Push)
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack dolu! Eleman eklenemedi.\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = value;
        printf("Stack'e eklenen eleman: %d\n", value);
    }
}

// Yığından eleman çıkarma (Pop)
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack boş! Eleman çikarilamadi.\n");
        return -1;
    }
    else
    {
        int item = s->items[s->top];
        s->top--;
        printf("Stack'ten cikarilan eleman: %d\n", item);
        return item;
    }
}

// Yığının en üstündeki elemanı görme (Peek)
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack boş!\n");
        return -1;
    }
    else
    {
        return s->items[s->top];
    }
}

// Yığını ekrana yazdırma
void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack boş!\n");
    }
    else
    {
        printf("Stack'teki elemanlar: ");
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main()
{
    Stack s;
    initializeStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    pop(&s);
    display(&s);

    printf("En ustteki eleman: %d\n", peek(&s));

    push(&s, 40);
    push(&s, 50);
    push(&s, 60); // Bu ekleme başarısız olacak çünkü stack dolu.
    display(&s);

    return 0;
}
