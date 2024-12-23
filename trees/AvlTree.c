#include <stdio.h>
#include <stdlib.h>

/*      AVL Ağacı Özellikleri:

            Yükseklik Dengesi: Her düğüm için, sol alt ağacın yüksekliği ile sağ alt ağacın yüksekliği
            arasındaki fark |hsol - hsağ| <= 1 olmalıdır
            
            Düğümlerin Sıralı Yerleşimi: Tüm BST özelliklerini taşır:
            Sol alt ağaçtaki tüm düğümlerin değerleri, kök düğümden küçüktür.
            Sağ alt ağaçtaki tüm düğümlerin değerleri, kök düğümden büyüktür
                        
        AVL Ağacında Rotasyonlar

            AVL ağacı dengesiz hale geldiğinde, dengeyi sağlamak için rotasyon kullanılır. Dört tür rotasyon vardır:

            Tek Sağ Rotasyon (Right Rotation, RR): Sol-alt ağacın fazla büyümesi durumunda yapılır.
            Tek Sol Rotasyon (Left Rotation, LL): Sağ-alt ağacın fazla büyümesi durumunda yapılır.
            Sol-Sağ Rotasyon (Left-Right Rotation, LR): Sol-alt ağacın sağ tarafının fazla büyümesi durumunda yapılır.
            Sağ-Sol Rotasyon (Right-Left Rotation, RL): Sağ-alt ağacın sol tarafının fazla büyümesi durumunda yapılır.
*/

// AVL Ağacı Düğüm Yapısı
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Düğümün Yüksekliğini Döndürür
int height(Node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

// Maksimum Değeri Döndüren Fonksiyon
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Yeni Düğüm Oluşturma Fonksiyonu
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Yeni düğümün başlangıç yüksekliği 1'dir
    return node;
}

// Sağ Rotasyon
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Rotasyonu Uygula
    x->right = y;
    y->left = T2;

    // Yükseklikleri Güncelle
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // Yeni kök
}

// Sol Rotasyon
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Rotasyonu Uygula
    y->left = x;
    x->right = T2;

    // Yükseklikleri Güncelle
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // Yeni kök
}

// Dengelenme Faktörünü Döndürür
int getBalance(Node* n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

// En Küçük Değerli Düğümü Bulma (Min Value Node)
Node* minValueNode(Node* node) {
    Node* current = node;

    // En sol düğüme gidene kadar ilerle
    while (current->left != NULL)
        current = current->left;

    return current;
}

// AVL Ağacına Yeni Düğüm Ekleme Fonksiyonu
Node* insert(Node* node, int key) {
    // 1. Normal BST Ekleme
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Aynı anahtardan tekrar eklenmez
        return node;

    // 2. Yüksekliği Güncelle
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Dengelenme Faktörünü Kontrol Et ve Gerekirse Dengele
    int balance = getBalance(node);

    // Sol-Sol Durumu
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Sağ-Sağ Durumu
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Sol-Sağ Durumu
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Sağ-Sol Durumu
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Dengeli düğümü döndür
}

// AVL Ağacından Düğüm Silme Fonksiyonu
Node* deleteNode(Node* root, int key) {
    // 1. Normal BST Silme
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Silinecek düğüm bulundu
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            // Tek çocuk veya hiç çocuğu yok
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp; // Tek çocuk varsa onu yukarı taşı

            free(temp);
        } else {
            // İki çocuk varsa
            Node* temp = minValueNode(root->right);

            // Sağ alt ağaçtaki en küçük değeri köke taşı
            root->key = temp->key;

            // Sağ alt ağaçtan bu düğümü sil
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // Eğer sadece bir düğüm varsa
    if (root == NULL)
        return root;

    // 2. Yüksekliği Güncelle
    root->height = 1 + max(height(root->left), height(root->right));

    // 3. Dengelenme Faktörünü Kontrol Et ve Gerekirse Dengele
    int balance = getBalance(root);

    // Sol-Sol Durumu
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Sol-Sağ Durumu
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Sağ-Sağ Durumu
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Sağ-Sol Durumu
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Ağaç İçeriklerini Sıralı Yazdırma (Inorder Traversal)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Ana Fonksiyon
int main() {
    Node* root = NULL;

    // AVL Ağacına Elemanlar Ekle
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("AVL Agaci Sirali Gostergesi: ");
    inorder(root);

    // Düğüm Silme
    printf("\n30 siliniyor...\n");
    root = deleteNode(root, 30);
    printf("Guncel AVL Agaci: ");
    inorder(root);

    return 0;
}
