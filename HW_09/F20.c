#include <stdint.h>   // Дан целочисленный массив из 10 элементов. Необходимо определить количество четных и нечетных чисел.
#include <stdio.h>    // Если количество чётных чисел больше, чем количество нечётных, заменить каждое нечетное число
#include <inttypes.h> // на произведение нечетных цифр . в его десятичной записи. Если количество нечётных чисел больше
#include <string.h>   // или равно количеству чётных, заменить каждое чётное число на произведение чётных цифр в его десятичной записи.

#define SIZE_ARR 10

//---------------------------------------------------------------------------------------
int64_t my_Even(int64_t num) // проверка на чётность.   0 - чётное число    1 - число не чётное
{
    return num % 2;
}

//---------------------------------------------------------------------------------------
int64_t multi_Chlen(uint64_t even_or_not_even, int64_t num)
{
    int64_t multi = 1, num_chlen = 0;
    uint64_t i;

    while (num)
    {
        num_chlen = num % 10;
        num /= 10;

        if (my_Even(num_chlen) && even_or_not_even)
        {
            multi *= num_chlen;
        }

        if (!(my_Even(num_chlen)) && !even_or_not_even)
        {
            multi *= num_chlen;
        }
    }

    return multi;
}

//--------------------------------------------------------------------------------
void sort_Even(uint64_t even_or_not_even, uint64_t size_arr, int64_t *arr_S) //
{
    uint64_t i, j, even = 0, not_even = 0;

    for (i = 0; i < size_arr; i++)
    {
        if (my_Even(*(arr_S + i)) && even_or_not_even)
        {
            *(arr_S + i) = multi_Chlen(even_or_not_even, *(arr_S + i)); //   действия с нечётными
        }
        if (!(my_Even(*(arr_S + i))) && !even_or_not_even)
        {
            *(arr_S + i) = multi_Chlen(even_or_not_even, *(arr_S + i)); //  действия с чётными
        }
    } // for
}

//--------------------------------------------------------------------------------
void input_Array(uint64_t size_arr, int64_t *arr_S) //   заполнение массива
{
    uint64_t i = 0, j = 0;

    for (i = 0; i < size_arr; i++)
        scanf("%d", &arr_S[i]);
}
//--------------------------------------------------------------------------------

void find_Even(uint64_t size_arr, int64_t *arr_S) //   поиск чётных чисел
{
    uint64_t i, j, even = 0, not_even = 0;

    for (i = 0; i < size_arr; i++)
        if (my_Even(*(arr_S + i)))
            not_even++;

    even = size_arr - not_even;

    if (not_even >= even) // если количество нечётных больше или равно кол.чётных
    {
        sort_Even(0, size_arr, arr_S); // заменить каждое чётное произведением чётных цифр в его десятичной записи
    }
    else
    {
        sort_Even(1, size_arr, arr_S); // заменить каждое нечётное произведением нечётных цифр в его десятичной записи
    }
}
//---------------------------------------------------------------------------------------

int64_t main()
{
    uint64_t size_arr = SIZE_ARR;
    int64_t arr_S[SIZE_ARR] = {0};

    input_Array(size_arr, arr_S); //   заполнение матрицы

    find_Even(size_arr, arr_S); //   Поиск чётных чисел

    for (uint64_t i = 0; i < size_arr; i++)
        printf(" %d ", *(arr_S + i));

    return 0;
}
/*
48 31 20 61 97 12 18 100 200 123

48 25 57 34 23 91 90 85 30 79
*/
