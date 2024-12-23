#include <stdio.h>
#include <stdlib.h>
/*
        Root (Kök): Ağacın en üstteki düğümüdür. Ağacın başlangıç noktasıdır.
        Parent (Ebeveyn): Bir düğümün altındaki düğümlere bağlantı kurduğu düğümdür.    
        Child (Çocuk): Bir düğümün bağlı olduğu alt düğümler.
        Leaf (Yaprak): Çocuk düğümü olmayan düğümlerdir.
        Height (Yükseklik): Kökten yaprağa kadar olan en uzun yolun uzunluğudur.
        Subtree (Alt Ağaç): Bir düğüm ve onun altındaki tüm düğümler bir alt ağaç oluşturur.

        Ekleme (Insertion): Ağaca yeni bir düğüm eklemek.
        Silme (Deletion): Ağaçtan bir düğüm silmek.
        Arama (Search): Belirli bir düğümün ağacın içinde olup olmadığını kontrol etmek.
        Dolaşma (Traversal): Ağacın düğümlerini belirli bir sıraya göre ziyaret etmek.
            Pre-order Traversal (Kök-Sol-Sağ): İlk kökü, sonra sol alt ağacı, ardından sağ alt ağacı ziyaret eder.
            In-order Traversal (Sol-Kök-Sağ): İlk sol alt ağacı, sonra kökü, ardından sağ alt ağacı ziyaret eder.
            Post-order Traversal (Sol-Sağ-Kök): İlk sol alt ağacı, sonra sağ alt ağacı, ardından kökü ziyaret eder
*/

// Binary Tree düğüm yapısı
struct Node {
    int data;                // Düğümün içeriği
    struct Node* left;       // Sol çocuk
    struct Node* right;      // Sağ çocuk
};

// Yeni bir düğüm oluşturma fonksiyonu
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);  // Sol alt ağaca ekle
    } else if (value > root->data) {
        root->right = insert(root->right, value); // Sağ alt ağaca ekle
    }
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;  // En sol düğüme git
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    // Silinecek düğümü arıyoruz
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {  
        // Silinecek düğüm bulundu
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // İki çocuğu varsa
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Pre-order Traversal
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Kök
        preOrder(root->left);       // Sol alt ağaç
        preOrder(root->right);      // Sağ alt ağaç
    }
}

// In-order Traversal
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);       // Sol alt ağaç
        printf("%d ", root->data); // Kök
        inOrder(root->right);      // Sağ alt ağaç
    }
}

// Post-order Traversal
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);     // Sol alt ağaç
        postOrder(root->right);    // Sağ alt ağaç
        printf("%d ", root->data); // Kök
    }
}

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int search(struct Node* root, int value) {
    if (root == NULL) {
        return 0;  // Değer bulunamadı
    }
    if (root->data == value) {
        return 1;  // Değer bulundu
    } else if (value < root->data) {
        return search(root->left, value);  // Sol alt ağacı ara
    } else {
        return search(root->right, value); // Sağ alt ağacı ara
    }
}

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;  // Yaprak bulundu
    }
    return countLeaves(root->left) + countLeaves(root->right);
}


int main() {
    struct Node* root = NULL;

    // Ağaca düğümler ekle
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Pre-order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrder(root);
    printf("\n");

    printf("Agacin yuksekligi: %d\n", height(root));

    int value = 40;
    if (search(root, value)) {
        printf("%d degeri bulundu.\n", value);
    } else {
        printf("%d degeri bulunamadi.\n", value);
    }

    return 0;
}
