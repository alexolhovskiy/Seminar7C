#include <stdio.h>            
#include <locale.h>

#include <stdlib.h>
#include <time.h>
#include <math.h>


void rightShift(int* arr, int size, int shift) {
    int i, j, temp, tempa, tempb;
    for (i = 0; i < shift; i++) {
        temp = arr[size - 1];
        tempa = arr[0];
        for (j = 0; j < size - 1; j++) {
            tempb = arr[j + 1];
            arr[j + 1] = tempa;
            tempa = tempb;
        }
        arr[0] = temp;
    }
}

int func(int i, int* arr, int size) {
    if (i < (size - 2)) {
        func((i + 1), arr, size);
    }
    arr[i + 1] = arr[i];
}

void rightShift2(int* arr, int size, int shift) {
    int i, j, temp;
    for (i = 0; i < shift; i++) {
        temp = arr[size - 1];
        func(0, arr, size);
        arr[0] = temp;
    }
}


int maxFind(int* arr, int size) {
    int max = 0, i;
    for (i = 0; i < size; i++) {
        if (arr[max] < arr[i]) {
            max = i;
        }
    }
    return arr[max];
}

int numMax(int* arr, int size) {
    int max = maxFind(arr, size), num = 0, i;
    for (i = 0; i < size; i++) {
        if (abs(arr[i]) > max) {
            num++;
        }
    }
    return num;
}

double medium(int* arr, int size) {
    int i, sum = 0;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / (double)size;
}

int findMin(int* arr, int size) {
    int i, min = 0;
    for (i = 0; i < size; i++) {
        if (arr[min] > arr[i]) {
            min = i;
        }
    }
    return arr[min];
}

void lastNumSort(int* arr, int size) {
    int i, j, temp = 0;
    for (j = 0; j < size - 1; j++) {
        for (i = j + 1; i < size; i++) {
            if (arr[i] % 10 < arr[j] % 10) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}


int* zeroDec(int* arr, int size, int* count) {
    int i, n = 0;

    for (i = 0; i < 10; i++) {
        if (arr[i] / 10 % 10 == 0) {
            (*count)++;
        }
    }

    int* newArr = (int*)malloc(*count);
    for (i = 0; i < 10; i++) {
        if (arr[i] / 10 % 10 == 0) {
            newArr[n++] = arr[i];
        }
    }
    return newArr;
}

int maxFindIndex(int* arr, int size) {
    int max = 0, i;
    for (i = 0; i < size; i++) {
        if (arr[max] < arr[i]) {
            max = i;
        }
    }
    return arr[max] == 1 ? -1 : max;
}

int greatestNum(int* arr, int size) {
    int i, j;
    int tempArr[10];
    for (i = 0; i < 10; i++) {
        tempArr[i] = 0;
    }
    for (j = 0; j < size; j++) {
        for (i = 0; i < size; i++) {
            if (arr[i] == arr[j]) {
                tempArr[j]++;
            }
        }
    }
    return arr[maxFindIndex(tempArr, 10)];
}


int main(void)
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    //1

    printf("Задача 1. Среднее арифметическое чисел\n\n");
    int arr[16], i;
    printf("Заполните массив: введите 5 чисел через пробел\n");
    scanf_s("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
    printf("Среднее арифметическое равно: %.2f\n", medium(arr, 5));
    printf("\n");



    //2
    printf("Задача 2. Найти минимум(массив из предыдущего задания)\n\n");
    printf("Минимальное значение: %d\n", findMin(arr, 5));
    printf("\n");



    //3
    printf("Задача 3. Циклический сдвиг массива вправо на 4\n\n");
    for (i = 0; i < 10; i++) {
        arr[i] = rand() % 10 - 5;
    }
    printf("Исходный массив (заполняется автоматически)\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", (arr[i]));
    }
    printf("\n");
    printf("Сдвинутый массив\n");
    //rightShift(arr, 10, 4);//второй вариант
    rightShift2(arr, 10, 4);
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    //4
    printf("Задача 4. Отсортировать по последней цифре\n\n");
    printf("Заполнить массив - в строку через пробел 10 элементов\n");
    scanf_s("%d %d %d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9]);
    printf("\n");
    printf("Отсортированный массив\n");
    lastNumSort(arr, 10);
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    //5
    printf("Задача 5. Вторая с конца ноль(массив из предыдущего задания)\n\n");
    int count = 0;
    int* arr2 = zeroDec(arr, 10, &count);
    for (i = 0; i < count; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");



    //6
    printf("Задача 6. Чаще других(массив из предыдущего задания)\n\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int num = greatestNum(arr, 10);
    num < 0 ? printf("Повторов нет\n") : printf("Чаще всего встречается: %d\n", num);
    printf("\n");



    return 0;
}