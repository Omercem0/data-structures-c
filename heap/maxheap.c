#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Maksimum kapasite
#define MAX_SIZE 100

// Max-Heap veri yapısı
typedef struct {
    int size;                   // Mevcut eleman sayısı
    int arr[MAX_SIZE];          // Elemanları saklayan dizi
} MaxHeap;

// Yeni bir Max-Heap oluştur
MaxHeap* createMaxHeap() {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->size = 0; // Başlangıç boyutu 0
    return heap;
}

// İki elemanın yerini değiştir
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bir düğümün ebeveynini bul
int parent(int i) {
    return (i - 1) / 2;
}

// Sol çocuk düğüm
int leftChild(int i) {
    return 2 * i + 1;
}

// Sağ çocuk düğüm
int rightChild(int i) {
    return 2 * i + 2;
}

// Max-Heap'e eleman ekle
void insert(MaxHeap* heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap dolu!\n");
        return;
    }

    // Elemanı sona ekle
    int i = heap->size;
    heap->arr[i] = value;
    heap->size++;

    // Heap özelliğini korumak için yukarı doğru hareket et
    while (i != 0 && heap->arr[parent(i)] < heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }
}

// Max-Heap'ten maksimum değeri çıkar
int extractMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        return INT_MIN; // Heap boş
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    // Kökü al ve son elemanı köke taşı
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Heapify işlemi
    int i = 0;
    while (1) {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;

        if (left < heap->size && heap->arr[left] > heap->arr[i])
            largest = left;

        if (right < heap->size && heap->arr[right] > heap->arr[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&heap->arr[i], &heap->arr[largest]);
        i = largest;
    }

    return root;
}

// Max-Heap'i yazdır
void printHeap(MaxHeap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

// Ana program
int main() {
    MaxHeap* heap = createMaxHeap();

    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 30);
    insert(heap, 40);
    insert(heap, 50);
    insert(heap, 5);

    printHeap(heap);

    printf("Cikarilan maksimum: %d\n", extractMax(heap));
    printHeap(heap);

    printf("Cikarilan maksimum: %d\n", extractMax(heap));
    printHeap(heap);

    free(heap);
    return 0;
}
