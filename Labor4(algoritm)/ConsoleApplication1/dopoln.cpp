﻿#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root;

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
	// Добавление одинаковых значений в правое поддерево
	if (data <= r->data) {
		r->left = CreateTree(root, r->left, data);
	}
	else {
		r->right = CreateTree(root, r->right, data);
	}
	return r;
}

// Функция для поиска элемента в дереве
int Search(struct Node* r, int data) {
	if (r == NULL) {
		return 0;
	}
	if (data == r->data) {
		return 1;
	}
	else if (data < r->data) {
		return Search(r->left, data);
	}
	else {
		return Search(r->right, data);
	}
}

// Функция для подсчета уровня последнего вхождения элемента в дереве
int Uroven(struct Node* r, int data, int urov) {
	if (r == NULL) {
		return -1; // Элемент не найден
	}

	int level = -1;
	if (data == r->data) {
		level = urov;
	}

	int leftLevel = Uroven(r->left, data, urov + 1);
	int rightLevel = Uroven(r->right, data, urov + 1);

	// Возвращаем самый глубокий уровень, где было найдено число
	if (leftLevel > level) {
		level = leftLevel;
	}
	if (rightLevel > level) {
		level = rightLevel;
	}
	return level;
}

// Функция для подсчета числа вхождений элемента в дереве
int CountOccurrences(struct Node* r, int data) {
	if (r == NULL) {
		return 0;
	}
	int count = 0;
	if (data == r->data) {
		count = 1;
	}
	return count + CountOccurrences(r->left, data) + CountOccurrences(r->right, data);
}

// Функция для вывода дерева на экран
void PrintTree(struct Node* r, int space) {
	if (r == NULL) {
		return;
	}

	space += 5;
	PrintTree(r->right, space);

	for (int i = 5; i < space; i++) {
		printf(" ");
	}
	printf("%d\n", r->data);

	PrintTree(r->left, space);
}

int main() {
	setlocale(LC_ALL, "");
	int D, start = 1;

	root = NULL;
	printf("-1 - окончание построения дерева\n");
	while (start) {
		printf("Введите число: ");
		scanf("%d", &D);
		if (D == -1) {
			printf("Построение дерева окончено\n\n");
			start = 0;
		}
		else {
			root = CreateTree(root, root, D);
		}
	}

	PrintTree(root, 0);

	// Поиск элемента в дереве
	printf("Введите число для поиска: ");
	scanf("%d", &D);
	if (Search(root, D)) {
		printf("Элемент %d найден в дереве\n", D);
	}
	else {
		printf("Элемент %d не найден в дереве\n", D);
	}

	// Подсчет числа вхождений элемента в дереве
	printf("Введите число для подсчета числа вхождений: ");
	scanf("%d", &D);
	int count = CountOccurrences(root, D);
	printf("Число вхождений элемента %d в дереве: %d\n", D, count);

	// Определение уровня последнего вхождения числа
	printf("Введите число для подсчета уровня последнего вхождения: ");
	scanf("%d", &D);
	int uroven = Uroven(root, D, 0);
	if (uroven != -1) {
		printf("Уровень последнего вхождения числа %d в дереве: %d\n", D, uroven);
	}
	else {
		printf("Число %d не найдено в дереве\n", D);
	}

	return 0;
}