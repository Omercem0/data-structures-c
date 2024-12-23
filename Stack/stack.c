#include <stdio.h>
#include <stdlib.h>

// Stack Linked List ile

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

// Stack başlatma fonksiyonu
void initializeStack(Stack *s)
{
    s->top = NULL;
}

// Yığına eleman ekleme (Push)
void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("Stack'e eklenen eleman: %d\n", value);
}

// Yığından eleman çıkarma (Pop)
int pop(Stack *s)
{
    if (s->top == NULL)
    {
        printf("Stack boş!\n");
        return -1;
    }

    int item = s->top->data;
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    printf("Stack'ten çikarilan eleman: %d\n", item);
    return item;
}

// Yığının en üstündeki elemanı görme (Peek)
int peek(Stack *s)
{
    if (s->top == NULL)
    {
        printf("Stack boş!\n");
        return -1;
    }
    return s->top->data;
}

// Yığını ekrana yazdırma
void display(Stack *s)
{
    Node *current = s->top;
    if (current == NULL)
    {
        printf("Stack boş!\n");
    }
    else
    {
        printf("Stack'teki elemanlar: ");
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
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
    display(&s);

    return 0;
}
