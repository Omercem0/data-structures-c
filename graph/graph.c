#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/*
        Düğüm (Node / Vertex): Grafın temel elemanlarıdır.
        Kenar (Edge): İki düğüm arasındaki bağlantıyı temsil eder.
        Yönlü Graf (Directed Graph): Kenarlar yönlüdür (A -> B).
        Yönsüz Graf (Undirected Graph): Kenarlar yönsüzdür (A - B).
        Ağırlıklı Graf (Weighted Graph): Kenarlara ağırlık atanmıştır.
        Bağlantılı Graf (Connected Graph): Tüm düğümler birbirine bağlantılıdır.
*/

// Node yapısı
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Graf yapısı
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("%d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Graph* graph = createGraph(SIZE);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 4, 1);

    printGraph(graph);

    return 0;
}