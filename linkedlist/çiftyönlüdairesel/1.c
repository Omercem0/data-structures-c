#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;
struct node *temp;
struct node *temp2;
struct node *last;

void listele();
void basaEkle(int sayi);
void sonaEkle(int sayi);
void bastanSil();
void sondanSil();
int elemanSayisi();
int dataToplam();

int main()
{
    int secim, sayi;

    while (1)
    {
        printf("1--> Listelemek icin\n");
        printf("2--> Basa eleman eklemek icin\n");
        printf("3--> Sona eleman eklemek icin\n");
        printf("4--> Bastan eleman silmek icin\n");
        printf("5--> Sondan eleman silmek icin\n");
        printf("6--> Eleman sayisi icin\n");
        printf("7--> Datalarin toplami icin icin\n");
        printf("0--> Cikis yapmak icin\n");
        printf("Seciminizi yapiniz\n");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:
            listele();
            break;
        case 2:
            printf("Datayi giriniz: ");
            scanf("%d", &sayi);
            basaEkle(sayi);
            break;
        case 3:
            printf("Datayi giriniz: ");
            scanf("%d", &sayi);
            sonaEkle(sayi);
            break;
        case 4:
            bastanSil();
            break;
        case 5:
            sondanSil();
            break;
        case 6:
            printf("Eleman sayisi: %d\n", elemanSayisi());
            break;
        case 7:
            printf("Datalarin toplami: %d\n", dataToplam());
            break;
        case 0:
            printf("Cikis yapiliyor!!");
            return 0;
            break;
        default:
            printf("Yanlis secim yaptiniz yeniden giriniz.");
            break;
        }
    }

    return 0;
}

void listele() {
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
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

void basaEkle(int sayi) {
    struct node *newnode;
    newnode=(struct node * )malloc(sizeof(struct node));
    newnode->data=sayi;

    if (head==NULL)
    {
        head=newnode;
        head->next=head;
        head->prev=head;
    }
    else
    {
        if (head->next==head)
        {
            head->next=newnode;
            head->prev=newnode;
            newnode->next=head;
            newnode->prev=head;
            head=newnode;
        }
        else
        {
            temp=head;
            while (temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }
}

void sonaEkle(int sayi) {
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=sayi;
    newnode->next=head;

    if (head==NULL)
    {
        head=newnode;
        head->next=head;
        head->prev=head;
    }
    else
    {
        if (head->next==head)
        {
            head->next=newnode;
            head->prev=newnode;
            newnode->prev=head;
        }
        else
        {
            temp=head;
            while (temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            head->prev=newnode;
        }
    }
}

void bastanSil() {
    if (head==NULL)
    {
        printf("Liste bos, silinecek eleman yok\n");
    }
    else
    {
        if (head->next==head)
        {
            free(head);
            head=NULL;
        }
        else
        {
            temp=head;
            while (temp->next!=head)
            {
                temp=temp->next;
            }
            temp2=head->next;
            free(head);
            temp->next=temp2;
            temp2->prev=temp;
            head=temp2;
        }
    }
}

void sondanSil() {
    if (head==NULL)
    {
        printf("Liste bos, silinecek eleman yok\n");
    }
    else
    {
        if (head->next==head)
        {
            free(head);
            head=NULL;
        }
        else
        {
            temp=head;
            while (temp->next!=head)
            {
                temp=temp->next;
            }

            temp2=temp->prev;
            free(temp);
            temp2->next=head;
            head->prev=temp2;
        }
    }
}

int elemanSayisi() {
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

int dataToplam() {
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