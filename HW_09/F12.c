#include <stdint.h>   // Составить функцию которая меняет в массиве минимальный и максимальный элемент местами.
#include <stdio.h>    //  Прототип функции void change_max_min(int size, int a[])
#include <inttypes.h> // 
#include <string.h>

#define RIGHT_SHIFT_FOR_INT 31     // количество сдвигаемых разрядов для int

//---------------------------------------------------------------------------------------
int num_Znak(int num) // знак числа, отрицательное или положительное
{
    int maska_num_1 = 1;
    num = num >> RIGHT_SHIFT_FOR_INT; // смещение старшего разряда в младший разряд, если он "1", число отрицательное

    return maska_num_1 & num; // побитовое умножение для проверки знака
}

//---------------------------------------------------------------------------------------
int my_ABS(int num) // получение числа по модулю
{
    return (num < 0) ? -num : num;
}

//--------------------------------------------------------------------------------
void i_to_j_in_arr(int *arr_S, int i, int j) // перемена местами двух элементов массива
{
    *(arr_S + j) = *(arr_S + j) ^ *(arr_S + i);
    *(arr_S + i) = *(arr_S + j) ^ *(arr_S + i);
    *(arr_S + j) = *(arr_S + j) ^ *(arr_S + i);
}
//--------------------------------------------------------------------------------
int arr_date_Input(int size_arr, int *arr_S) //  заполнение входного массива
{                                                          // подсчёт отрицательных значений
    int i, mng_negativ = 0;

    for (i = 0; i < size_arr; i++)
        if (num_Znak(*(arr_S + i)))
            mng_negativ++;

    return mng_negativ; // количество отрицательных чисел во входных данных
}

//--------------------------------------------------------------------------------
void create_work_Array(int size_arr,  int *arr_S,                             //  заполнение рабочх массивов
                       int s_arr_neg, int *arr_neg_0, int *arr_neg_idx,       // с отрицательными и положительными
                       int s_arr_pos, int *arr_pos_0, int *arr_pos_idx)       //  значениями
{
    int i, i_neg = 0, i_pos = 0;
    int temp = 0;

    for (int i = 0; i < size_arr; i++)
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
int sort_array_Negativ(int size_arr, int *arr_work, int *arr_work_idx)
{
    //  создаётся два массива, из знaчений и индексов принятого на  вход массива.
    // Затем он сортируется по возрастанию два первых элемента сортированного массива дадут минимальную сумму

    int i, j; //

    for (i = 0; i < size_arr - 1; i++)
        for (j = i + 1; j < size_arr; j++)
        {
            if (my_ABS(*(arr_work + i)) > my_ABS(*(arr_work + j)))
            {
                i_to_j_in_arr(arr_work, i, j);
                i_to_j_in_arr(arr_work_idx, i, j);
            }
        } // for j

    return *(arr_work_idx + size_arr - 1 ) ;
}

//--------------------------------------------------------------------------------
int sort_array_Positiv(int size_arr, int *arr_work, int *arr_work_idx)
{
    //  создаётся два массива, из знaчений и индексов принятого на  вход массива.
    // Затем он сортируется по возрастанию два первых элемента сортированного массива дадут минимальную сумму

    int i, j; //

    for (i = 0; i < size_arr - 1; i++)
        for (j = i + 1; j < size_arr; j++)
        {
            if ((*(arr_work + i)) > (*(arr_work + j)))
            {
                i_to_j_in_arr(arr_work, i, j);
                i_to_j_in_arr(arr_work_idx, i, j);
            }
        } // for j

    return *(arr_work_idx + size_arr - 1);
}

//--------------------------------------------------------------------------------
void change_max_min(int size_arr, int *arr_S)           // Функция заданная условием задачи
{
    int size_arr_negativ = 0;                      // размерность массива отрицательных значений
    size_arr_negativ = arr_date_Input(size_arr, arr_S); // заполение входного массива

    int size_arr_positiv = size_arr - size_arr_negativ; // размерность массива положительных значений

    int arr_work_negativ_0[size_arr_negativ];
    int arr_work_negativ_idx[size_arr_negativ];

    int arr_work_positiv_0[size_arr_positiv];
    int arr_work_positiv_idx[size_arr_positiv];

    create_work_Array(size_arr, arr_S,
                      size_arr_negativ, arr_work_negativ_0, arr_work_negativ_idx,
                      size_arr_positiv, arr_work_positiv_0, arr_work_positiv_idx); // заполнение рабочих массивов

    int min_element_arr_idx = 0,  max_element_arr_idx = 0;                  

    if (size_arr_negativ) // если отрицательные значения есть во входящих данных, то сортировка
    {
        min_element_arr_idx = sort_array_Negativ(size_arr_negativ, arr_work_negativ_0, arr_work_negativ_idx) ;

        if (size_arr == size_arr_negativ)  // есди массив состоит полностью из отрицательных чисел
            max_element_arr_idx = *arr_work_negativ_idx ;
        else    
            max_element_arr_idx = sort_array_Positiv(size_arr_positiv, arr_work_positiv_0, arr_work_positiv_idx); 
    }
    else
    { // если во входящих данных отрицательных чисел нет, то сортировка положительного массива 
        max_element_arr_idx = sort_array_Positiv(size_arr_positiv, arr_work_positiv_0, arr_work_positiv_idx); 
        min_element_arr_idx = *arr_work_positiv_idx ;
    }
    
  //  printf("min = %d  max = %d\n", min_element_arr_idx, max_element_arr_idx);
    i_to_j_in_arr(arr_S, max_element_arr_idx, min_element_arr_idx);  

}

/*
int main()
{ // -1000 25 -20 25 -11 -32 -5 3 3 -34 -12 36 37 2 8 49 30 30 -12 14 -40 -24 40 -27 3 49 13 44 -33 -1000
  // 1 2  30  3  4  5  6  7  8  9  10  11  12  13  14  15  16  -17  18  19  20  21  22  23  24  25  26  27 28  29
  //  -10 25 -20 25 -11 -32 -5 3 3 -34 -12 36 37 2 8 49 30 30 -12 14 -40 -24 40 -27 3 49 13 44 -33 2

    int size_arr = 30 ; // SIZE_ARR;
    int arr_S[30] = { -1000, 25, -20, 25, -11, -32, -5, 3, 3, -34, -12, 36, 37, 2, 8, 49, 30,
                               30, -12, 14, -40, -24, 40, -27, 3, 49, 13, 44, -33, -1000};

    change_max_min( size_arr, arr_S) ;

    for (int i = 0; i < size_arr; i++)   printf(" %d ", *(arr_S + i));
    

    return 0;
}

*/