#include <stdint.h>   // Определить количество положительных элементов квадратной матрицы, превышающих по величине
#include <stdio.h>    // среднее арифметическое всех элементов главной диагонали. Реализовать функцию
#include <inttypes.h> // среднее арифметическое главной диагонали.
#include <string.h>   //

#define ARR_SIZE 5
#define RIGHT_SHIFT_FOR_INT64_t 31 // количество сдвигаемых разрядов для int

//---------------------------------------------------------------------------------------
int64_t num_Znak(int64_t num) // знак числа, отрицательное или положительное
{
    int64_t maska_num_1 = 1;
    num = num >> RIGHT_SHIFT_FOR_INT64_t; // смещение старшего разряда в младший разряд, если он "1", число отрицательное

    return maska_num_1 & num; // побитовое умножение для проверки знака
}

//--------------------------------------------------------------------------------

int64_t my_cmp(int64_t num1, int64_t num2) //   сравнение двух чисел  num1 < num2 ->  1
{                                          //                         num1 > num2 -> -1
    uint64_t i = 0, j = 0;                 //                         num1 == num2 -> 0
    int64_t cmp = 0;

    if (num_Znak(num1) && num_Znak(num2)) // если оба сравниваемых числа отрицательные
    {
        if (-num1 > -num2) // сравнение по модулю
        {
            cmp = -1;
        } //
        else
        {
            cmp = 1;
        }
    }
    else
    {
        if (num_Znak(num1) || num_Znak(num2)) //  если oдно отрицательное другое положительное
        {
            if (num_Znak(num1))
            {
                cmp = -1;
            } //
            else
            {
                cmp = 1;
            }
        }
        else
        {                    //
            if (num1 < num2) // если оба числа положительные
            {
                cmp = -1;
            }
            else
            {
                cmp = 1;
            }
        }
    }

    return cmp;
}

//--------------------------------------------------------------------------------

uint64_t qu_more_srdn_Arifm(int64_t sr_arf, uint64_t size_arr, int64_t (*arr_S)[size_arr]) //   сумма цифр главной диагонали
{
    uint64_t i = 0, j = 0, qnt = 0;

    for (i = 0; i < size_arr; i++)
        for (j = 0; j < size_arr; j++)
            if (my_cmp(sr_arf, arr_S[i][j]) == -1)
                qnt++; // колиество чисел, которые больше, чем среднее арифметическое в главной диагонали

    return qnt;
}
//--------------------------------------------------------------------------------

int64_t sled_Array(uint64_t size_arr, int64_t (*arr_S)[size_arr]) //   сумма цифр главной диагонали
{
    uint64_t i = 0, j = 0;
    int64_t sled = 0, sr_arf = 0;

    for (i = 0; i < size_arr; i++)
        for (j = 0; j < size_arr; j++)
            if (i == j)
                sled += arr_S[i][i]; // Сумма чисел в главной диагонали

    return sled;
}
//--------------------------------------------------------------------------------

void input_Array(uint64_t size_arr, int64_t (*arr_S)[size_arr]) //   заполнение матрицы
{
    uint64_t i = 0, j = 0;

    for (i = 0; i < size_arr; i++)
        for (j = 0; j < size_arr; j++)
            scanf("%d", &arr_S[i][j]);
}

//--------------------------------------------------------------------------------
int64_t main() //   1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5
{
    uint64_t size_arr = ARR_SIZE, i = 0, j = 0, qnt = 0;
    int64_t arr_S[ARR_SIZE][ARR_SIZE] = {0}, sled = 0, sr_arf = 0;

    input_Array(size_arr, arr_S); //   заполнение матрицы

    sr_arf = sled_Array(size_arr, arr_S) / size_arr; // среднее арифметическое главной диагонали матрицы

    qnt = qu_more_srdn_Arifm(sr_arf, size_arr, arr_S); // Количество цифр в матрице, которые больше по своему значению , чем среднее арифметическое

    printf("%d", qnt);

    return 0;
}
/*

1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5

*/