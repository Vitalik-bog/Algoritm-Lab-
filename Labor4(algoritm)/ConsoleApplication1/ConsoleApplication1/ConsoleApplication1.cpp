#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root;

// Структура для очереди узлов
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

// Функция для создания нового узла дерева
struct Node* CreateNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Функция для добавления элемента в дерево
struct Node* CreateTree(struct Node* root, struct Node* r, int data) {
    if (r == NULL) {
        r = CreateNode(data);
        return r;
    }

    if (data == r->data) {
        printf("Элемент %d уже существует в дереве, добавление не выполнено.\n", data);
        return r;
    }

    if (data < r->data) {
        r->left = CreateTree(root, r->left, data);
    }
    else {
        r->right = CreateTree(root, r->right, data);
    }

    return r;
}

// Функции для работы с очередью
struct QueueNode* Enqueue(struct QueueNode* tail, struct Node* treeNode) {
    struct QueueNode* newQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    if (tail != NULL) {
        tail->next = newQueueNode;
    }
    return newQueueNode;
}

struct QueueNode* Dequeue(struct QueueNode** head) {
    if (*head == NULL) return NULL;
    struct QueueNode* temp = *head;
    *head = (*head)->next;
    free(temp);
    return *head;
}

// Функция для вывода дерева сверху вниз (по уровням)
void PrintTree(struct Node* root) {
    if (root == NULL) {
        printf("Дерево пусто\n");
        return;
    }

    struct QueueNode* head = NULL;
    struct QueueNode* tail = NULL;

    head = Enqueue(head, root);
    tail = head;

    while (head != NULL) {
        struct Node* current = head->treeNode;
        printf("%d ", current->data);

        if (current->left != NULL) {
            tail = Enqueue(tail, current->left);
        }
        if (current->right != NULL) {
            tail = Enqueue(tail, current->right);
        }

        head = Dequeue(&head);
    }

    printf("\n");
}

int main() {
    setlocale(LC_ALL, "");
    int D, start = 1;

    root = NULL;
    printf("-1 - окончание построения дерева\n");
    while (start) {
        printf("Введите число: ");
        scanf_s("%d", &D);
        if (D == -1) {
            printf("Построение дерева окончено\n\n");
            start = 0;
        }
        else {
            root = CreateTree(root, root, D);
        }
    }

    printf("Вывод дерева сверху вниз:\n");
    PrintTree(root);

    // Поиск элемента в дереве
    printf("Введите число для поиска: ");
    scanf_s("%d", &D);
    if (Search(root, D)) {
        printf("Элемент %d найден в дереве\n", D);
    }
    else {
        printf("Элемент %d не найден в дереве\n", D);
    }

    // Подсчет числа вхождений элемента в дереве
    printf("Введите число для подсчета числа вхождений: ");
    scanf_s("%d", &D);
    int count = CountOccurrences(root, D);
    printf("Число вхождений элемента %d в дереве: %d\n", D, count);

    scanf_s("%d", &D);
    return 0;
}


