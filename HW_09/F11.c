#include <stdint.h>   // Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения
#include <stdio.h>    // помещающиеся в int. Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух
#include <inttypes.h> // элементов массива, сумма которых минимальна.
#include <string.h>

#define SIZE_ARR 30
#define RIGHT_SHIFT 31 // количество сдвигаемых разрядов

//---------------------------------------------------------------------------------------
int64_t num_Znak(int64_t num) // знак числа, отрицательное или положительное
{
    int64_t maska_num_1 = 1;
    num = num >> RIGHT_SHIFT; // смещение старшего разряда в младший разряд, если он "1", число отрицательное

    return maska_num_1 & num; // побитовое умножение для проверки знака
}

//---------------------------------------------------------------------------------------
int64_t my_ABS(int64_t num) // получение числа по модулю
{
    return (num < 0) ? -num : num;
}

//--------------------------------------------------------------------------------
void i_to_j_in_arr(uint64_t *arr_S, uint64_t i, uint64_t j) // перемена местами двух элементов массива
{
    *(arr_S + j) = *(arr_S + j) ^ *(arr_S + i);
    *(arr_S + i) = *(arr_S + j) ^ *(arr_S + i);
    *(arr_S + j) = *(arr_S + j) ^ *(arr_S + i);
}
//--------------------------------------------------------------------------------
uint64_t arr_date_Input(uint64_t size_arr, int64_t *arr_S) //  заполнение входного массива
{                                                          // подсчёт отрицательных значений
    int64_t n_input = 0;
    uint64_t i, mng_negativ = 0;

    for (i = 0; i < size_arr; i++)
    {
        scanf("%d", &n_input);
        *(arr_S + i) = n_input;

        if (num_Znak(n_input))
            mng_negativ++;
    }

    return mng_negativ; // количество отрицательных чисел во входных данных
}

//--------------------------------------------------------------------------------
void create_work_Array(uint64_t size_arr, int64_t *arr_S,                             //  заполнение рабочх массивов
                       uint64_t s_arr_neg, int64_t *arr_neg_0, uint64_t *arr_neg_idx, // с отрицательными и положительными
                       uint64_t s_arr_pos, int64_t *arr_pos_0, uint64_t *arr_pos_idx) //  значениями
{
    uint64_t i, i_neg = 0, i_pos = 0;
    int64_t temp = 0;

    for (uint64_t i = 0; i < size_arr; i++)
    {
        temp = *(arr_S + i);

        if (num_Znak(temp))
        {
            arr_neg_0[i_neg] = temp; // массив с отрицательными значениями
            arr_neg_idx[i_neg] = i;  // и индексами к ним
            i_neg++;
        }
        else
        {
            arr_pos_0[i_pos] = temp;
            arr_pos_idx[i_pos] = i;
            i_pos++;
        }
    }
}

//--------------------------------------------------------------------------------
uint64_t sort_array_Negativ(uint64_t size_arr, int64_t *arr_work, uint64_t *arr_work_idx)
{
    //  создаётся два массива, из знaчений и индексов принятого на  вход массива.
    // Затем он сортируется по возрастанию два первых элемента сортированного массива дадут минимальную сумму

    uint64_t i, j; //

    // print_Int_array(size_arr, arr_work);

    for (i = 0; i < size_arr - 1; i++)
        for (j = i + 1; j < size_arr; j++)
        {
            if (my_ABS(*(arr_work + i)) > my_ABS(*(arr_work + j)))
            {
                i_to_j_in_arr(arr_work, i, j);
                i_to_j_in_arr(arr_work_idx, i, j);
            }
        } // for j

    // for ( i = 0; i < size_arr; i++)        printf("%d ", arr_work[i] );

    if (size_arr > 1)
    {
        if (arr_work_idx[0] > arr_work_idx[1])
            printf("%d %d", arr_work_idx[1], arr_work_idx[0]);
        else
            printf("%d %d", arr_work_idx[0], arr_work_idx[1]);
        return 1;
    }
    return 0;
}

//--------------------------------------------------------------------------------
uint64_t sort_array_Positiv(uint64_t size_arr, int64_t *arr_work, uint64_t *arr_work_idx)
{
    //  создаётся два массива, из знaчений и индексов принятого на  вход массива.
    // Затем он сортируется по возрастанию два первых элемента сортированного массива дадут минимальную сумму

    uint64_t i, j; //

    for (i = 0; i < size_arr - 1; i++)
        for (j = i + 1; j < size_arr; j++)
        {
            if ((*(arr_work + i)) > (*(arr_work + j)))
            {
                i_to_j_in_arr(arr_work, i, j);
                i_to_j_in_arr(arr_work_idx, i, j);
            }
        } // for j

    return 0;
}

//--------------------------------------------------------------------------------
int64_t main()
{ // -1000 25 -20 25 -11 -32 -5 3 3 -34 -12 36 37 2 8 49 30 30 -12 14 -40 -24 40 -27 3 49 13 44 -33 -1000
  // 1 2  30  3  4  5  6  7  8  9  10  11  12  13  14  15  16  -17  18  19  20  21  22  23  24  25  26  27 28  29
  //  -10 25 -20 25 -11 -32 -5 3 3 -34 -12 36 37 2 8 49 30 30 -12 14 -40 -24 40 -27 3 49 13 44 -33 2

    uint64_t size_arr = SIZE_ARR;
    int64_t arr_S[SIZE_ARR];

    int64_t index_arr_min_negativ = 0, index_arr_min_positiv = 0;

    uint64_t size_arr_negativ = 0;                      // размерность массива отрицательных значений
    size_arr_negativ = arr_date_Input(size_arr, arr_S); // заполение входного массива

    uint64_t size_arr_positiv = size_arr - size_arr_negativ; // размерность массива положительных значений

    int64_t arr_work_negativ_0[size_arr_negativ];
    uint64_t arr_work_negativ_idx[size_arr_negativ];

    int64_t arr_work_positiv_0[size_arr_positiv];
    uint64_t arr_work_positiv_idx[size_arr_positiv];

    create_work_Array(size_arr, arr_S,
                      size_arr_negativ, arr_work_negativ_0, arr_work_negativ_idx,
                      size_arr_positiv, arr_work_positiv_0, arr_work_positiv_idx); // заполнение рабочих массивов

    if (size_arr_negativ) // если отрицательные значения есть во входящих данных, то сортировка
    {
        if (sort_array_Negativ(size_arr_negativ, arr_work_negativ_0, arr_work_negativ_idx))
        {
            return 0; // если во входящих данных два и более отрицательных чисел, печать из сортировки и завершение программы
        }
        else
        { // если во входящих данных только одно отрицательное число, его печать + сортировка положительного массива

            sort_array_Positiv(size_arr_positiv, arr_work_positiv_0, arr_work_positiv_idx);
            if (arr_work_negativ_idx[0] > arr_work_positiv_idx[0])
            {
                printf("%d ", arr_work_positiv_idx[0]);
                printf("%d ", arr_work_negativ_idx[0]);
            }
            else
            {
                printf("%d ", arr_work_negativ_idx[0]);
                printf("%d ", arr_work_positiv_idx[0]);
            }
            return 0;
        }
    }
    else
    { // если во входящих данных отрицательных чисел нет, то сортировка положительного массива и печать двух первых значенний
        sort_array_Positiv(size_arr_positiv, arr_work_positiv_0, arr_work_positiv_idx);
        if (arr_work_positiv_idx[0] > arr_work_positiv_idx[1])
            printf("%d %d", arr_work_positiv_idx[1], arr_work_positiv_idx[0]);
        else
            printf("%d %d", arr_work_positiv_idx[0], arr_work_positiv_idx[1]);
    }

    return 0;
}