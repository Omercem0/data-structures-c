#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp = NULL;
struct node *prev = NULL;
struct node *last = NULL;

int datatoplam();
int dugumadet();
void sondansil();
void bastansil();
void basaEkle(int sayi);
void sonaEkle(int sayi);
void listele();

int main()
{

    int secim, sayi, sonuc;

    while (1)
    {
        printf("1--> basa eleman eklemek icin \n");
        printf("2--> listelemek icin \n");
        printf("3--> sona eleman eklemek icin \n");
        printf("4--> bastan eleman silmek icin \n");
        printf("5--> sondan eleman silmek icin \n");
        printf("6--> eleman adedi icin\n");
        printf("7--> datalarin toplami icin \n");
        printf("8--> Cikmak icin \n");
        printf("Seciminizi yapin\n");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:
            printf("Datayi giriniz: ");
            scanf("%d", &sayi);
            basaEkle(sayi);
            break;
        case 2:
            listele();
            break;
        case 3:
            printf("Datayi giriniz: ");
            scanf("%d", &sayi);
            sonaEkle(sayi);
            break;
        case 4:
            bastansil();
            break;
        case 5:
            sondansil();
            break;
        case 6:
            sonuc = dugumadet();
            printf("Dugum adedi : %d\n", sonuc);
            break;
        case 7:
            sonuc = datatoplam();
            printf("Datalarin toplami : %d\n", sonuc);
            break;
        case 8:
            printf("Cikis yapiliyor!!");
            return 0;
            break;
        default:
            printf("Yanlis secim yaptiniz");
            break;
        }
    }
    return 0;
}

int datatoplam()
{
    int toplam = 0;
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            toplam += temp->data;
            temp = temp->next;
        }
        toplam += temp->data;
        return toplam;
    }
}

int dugumadet()
{
    int sayac = 0;
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            sayac++;
            temp = temp->next;
        }
        sayac++;
        return sayac;
    }
}

void sondansil()
{

    if (head == NULL)
    {
        printf("Listede silinecek eleman yok\n");
    }
    else
    {
        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            last = head;
            while (last->next->next != head)
            {
                last = last->next;
            }
            free(last->next);
            last->next = head;
        }
    }
}

void bastansil()
{

    if (head == NULL)
    {
        printf("Listede silinecek eleman yok\n");
    }
    else
    {
        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            temp = head->next;
            free(head);
            last->next = temp;
            head = temp;
        }
    }
}

void sonaEkle(int sayi)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = sayi;

    if (head == NULL)
    {
        head = newnode;
        head->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

void basaEkle(int sayi)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = sayi;

    if (head == NULL)
    {
        head = newnode;
        head->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void listele()
{
    system("cls");
    if (head == NULL)
    {
        printf("Liste bos!!\n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        printf("%d\n\n", temp->data);
    }
}