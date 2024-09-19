// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <stdio.h>
#include <limits.h>
int main()
{
    int max = INT_MIN, min = INT_MAX;
    int a[10] = { 30,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < 10; i++) {
        if (a[i] < min) {
            min = a[i];
        }
        if (a[i] > max) {
            max = a[i];
        }
    }
    printf("min= %d, max= %d difference=%d", min, max, max - min);
    return(0);
}
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int w, v[10];
    for (int i = 0; i < 10; i++) {
        w = rand() % 100;
        v[i] = w;
        printf("%d ", v[i]);
    }
    getchar();
}


//
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int w, * v, n;
    printf("enter n\n");
    scanf_s("%d", &n);
    getchar();
    v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        w = rand() % 100;
        v[i] = w;
        printf("%d ", v[i]);
    }
    free(v);
    getchar();
}
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int w, v[5][5], n = 5, sum[5]{};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            w = rand() % 100;
            v[i][j] = w;
            printf("%d     ", v[i][j]);
        }
        printf("\n");
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 5; i++) {
            sum[j] += v[i][j];

        }
    }

    for (int j = 0; j < n; j++) {
        printf("%d    ", sum[j]);
    }

    getchar();
}
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int   main()
{
    setlocale(LC_ALL, "Rus");
    int i;
    struct student
    {
        char famil[20];
        char name[20];
        int group;
    } stud[3];

    for (i = 0; i < 3; i++)
    {
        printf("Введите фамилию студента\n"); scanf("%20s", &stud[i].famil);
        printf("Введите имя студента %s\n", stud[i].famil); scanf("%20s", &stud[i].name);
        printf("Введите номер группы студента %s %s\n", stud[i].famil, stud[i].name); scanf("%d", &stud[i].group);
    }
    getchar();

    for (i = 0; i < 3; i++)
    {
        printf("Cтудент %s %s, номер группы %d \n", stud[i].famil, stud[i].name, stud[i].group);
    }
    int need_group;
    printf("Введите номер необходимой группы\n");
    scanf("%d", &need_group);
    for (i = 0; i < 3; i++)
    {
        if (stud[i].group == need_group) {
            printf("Cтудент %s %s, номер группы %d \n", stud[i].famil, stud[i].name, stud[i].group);
        }

    }
    getchar();
}
//






// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
