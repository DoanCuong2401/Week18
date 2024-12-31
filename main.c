#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cấu trúc đồ thị sử dụng ma trận lân cận
typedef struct {
    int vertices;
    int Matrix[MAX][MAX];
} GraphMatrix;

// Khởi tạo đồ thị sử dụng ma trận lân cận
void initMatrix(GraphMatrix* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->Matrix[i][j] = 0;
        }
    }
}

// Thêm cạnh vào ma trận lân cận
void addMatrix(GraphMatrix* graph, int start, int end) {
    graph->Matrix[start][end] = 1;
}

// Hiển thị ma trận lân cận
void displayMatrix(GraphMatrix* graph) {
    printf("Ma tran lan can:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->Matrix[i][j]);
        }
        printf("\n");
    }
}

// Cấu trúc danh sách lân cận
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int vertices;
    Node* adjList[MAX];
} GraphList;

// Tạo một nút mới
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Khởi tạo đồ thị sử dụng danh sách lân cận
void initList(GraphList* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
}

// Thêm cạnh vào danh sách lân cận
void addList(GraphList* graph, int start, int end) {
    Node* newNode = createNode(end);
    newNode->next = graph->adjList[start];
    graph->adjList[start] = newNode;
}

// Hiển thị danh sách lân cận
void displayList(GraphList* graph) {
    printf("Danh sach lan can:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d: ", i);
        Node* temp = graph->adjList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Chương trình chính
int main() {
    int vertices = 7; 

    // Ma trận lân cận
    GraphMatrix graphMatrix;
    initMatrix(&graphMatrix, vertices);

    // Thêm các cạnh
    addMatrix(&graphMatrix, 0, 1); // a -> b
    addMatrix(&graphMatrix, 0, 2); // a -> c
    addMatrix(&graphMatrix, 0, 3); // a -> d
    addMatrix(&graphMatrix, 1, 4); // b -> e
    addMatrix(&graphMatrix, 2, 4); // c -> e
    addMatrix(&graphMatrix, 3, 5); // d -> f
    addMatrix(&graphMatrix, 4, 6); // e -> g
    addMatrix(&graphMatrix, 5, 6); // f -> g

    // Hiển thị ma trận lân cận
    displayMatrix(&graphMatrix);

    // Danh sách lân cận
    GraphList graphList;
    initList(&graphList, vertices);

    // Thêm các cạnh
    addList(&graphList, 0, 1); // a -> b
    addList(&graphList, 0, 2); // a -> c
    addList(&graphList, 0, 3); // a -> d
    addList(&graphList, 1, 4); // b -> e
    addList(&graphList, 2, 4); // c -> e
    addList(&graphList, 3, 5); // d -> f
    addList(&graphList, 4, 6); // e -> g
    addList(&graphList, 5, 6); // f -> g

    // Hiển thị danh sách lân cận
    displayList(&graphList);

    return 0;
}
