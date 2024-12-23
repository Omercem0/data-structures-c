#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp = NULL;

int SumData();
int countNodes();
void ReverseTheList();
void DeleteBetweenOfList(int sira);
void DeleteEndOfList();
void DeleteHeadOfList();
void AddBetweenOfTheList(int sayi, int sira);
void AddEndOfTheList(int sayi);
void AddHeadOfTheList(int sayi);
void printList();
void menubas();

int main()
{
    int islem, sayi, sira, adet, toplam;

    do
    {
        menubas();
        scanf("%d", &islem);

        switch (islem)
        {
        case 0:
            printf("Cikis yapiliyor!!!\n");
            break;
        case 1:
            printf("Eklenecek sayiyi giriniz.\n");
            scanf("%d", &sayi);
            AddHeadOfTheList(sayi);
            printList();
            break;
        case 2:
            printf("Eklenecek sayiyi giriniz.\n");
            scanf("%d", &sayi);
            AddEndOfTheList(sayi);
            printList();
            break;
        case 3:
            printf("Eklenecek sayiyi giriniz.\n");
            scanf("%d", &sayi);
            printf("Hangi sayidan once eklenecek?.\n");
            scanf("%d", &sira);
            AddBetweenOfTheList(sayi, sira);
            printList();
            break;
        case 4:
            DeleteHeadOfList();
            printList();
            break;
        case 5:
            DeleteEndOfList();
            printList();
            break;
        case 6:
            printf("Aradan silmek istediginiz elemanin degeri?\n");
            scanf("%d", &sira);
            DeleteBetweenOfList(sira);
            printList();
            break;
        case 7:
            ReverseTheList();
            printList();
            break;
        case 8:
            adet = countNodes();
            printList();
            if (adet != 0)
            {
                printf("%d adet eleman var.\n", adet);
            }
            break;
        case 9:
            toplam = SumData();
            printList();
            printf("Verilerin toplami: %d", toplam);
            break;
        case 10:
            printList();
            break;
        default:
            printf("Gecersiz islem girdiniz!!\n");
            break;
        }
    } while (islem != 0);

    return 0;
}

int SumData()
{
    int toplam = 0;
    temp = head;
    while (temp != NULL)
    {
        toplam += temp->data;
        temp = temp->next;
    }
    return toplam;
}

int countNodes()
{
    int adet=0;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        adet++;
    }
    return adet;
}

void ReverseTheList()
{
    struct node *temp2 = NULL;
    struct node *prev = NULL;

    temp = head;

    while (temp != NULL)
    {
        temp2 = temp->next;
        temp->next = prev;
        prev = temp;
        temp = temp2;
    }
    head = prev;
}

void DeleteBetweenOfList(int sira)
{
    temp = head;
    if (temp->data == sira)
    {
        DeleteHeadOfList();
    }
    else
    {
        struct node *temp2;
        temp2 = (struct node *)malloc(sizeof(struct node));

        while (temp->next->data != sira)
        {
            temp = temp->next;
        }
        if (temp->next->next == NULL)
        {
            DeleteEndOfList();
        }
        else
        {
            temp2 = temp->next->next;
            free(temp->next);
            temp->next = temp2;
        }
    }
}

void DeleteEndOfList()
{
    if (head->next != NULL)
    {
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    else
    {
        DeleteHeadOfList();
    }
}

void DeleteHeadOfList()
{
    if (head == NULL)
    {
        free(head);
    }
    else
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}

void AddBetweenOfTheList(int sayi, int sira)
{

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = sayi;
    temp = head;
    while (temp->next->data != sira)
    {
        temp = temp->next;
    }
    struct node *temp2;
    temp2 = (struct node *)malloc(sizeof(struct node));

    temp2 = temp->next;
    temp->next = newnode;
    newnode->next = temp2;
}

void AddHeadOfTheList(int sayi)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = sayi;
    newnode->next = head;
    head = newnode;
}

void AddEndOfTheList(int sayi)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = sayi;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void printList()
{
    system("cls");
    if (head != NULL)
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("Eleman yok !!!\n");
    }
}

void menubas()
{
    printf("\n1-) Listenin Basina eleman eklemek.\n");
    printf("2-) Listenin sonuna eleman eklemek.\n");
    printf("3-) Araya eleman eklemek.\n");
    printf("4-) Listenin basindaki elemani silmek.\n");
    printf("5-) Listenin sonundaki elemani silmek.\n");
    printf("6-) Aradan eleman silmek.\n");
    printf("7-) Listeyi tersine cevir.\n");
    printf("8-) Eleman (dugum) sayisi\n");
    printf("9-) Datalarin toplami.\n");
    printf("10-) Listeyi yazdirmak.\n");
    printf("0-) Cikis.\n");
}