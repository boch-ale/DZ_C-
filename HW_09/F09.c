#include <stdint.h>   // Составить только функцию которая в массиве находит максимальный из отрицательных элементов и меняет его местами
#include <stdio.h>    // с последним элементом массива. Гарантируется, что в массиве только один такой элемент или же такой элемент
#include <inttypes.h> // отсутствует. Если отрицательных элементов нет - массив не менять
#include <string.h>   // Прототип функции: void swap_negmax_last(int size, int a[])

#define SIZE_ARR 10

//---------------------------------------------------------------------------------------
int my_ABS(int num) // получение числа по модулю
{
    return (num < 0) ? -num : num;
}

//---------------------------------------------------------------------------------------
void print_Array(int size_arr, int *arr_S) // печать полученного массива
{
    for (int i = 0; i < size_arr; i++)
        printf("%d ", *(arr_S + i));
}
//---------------------------------------------------------------------------------------
void i_to_j_in_arr(int *arr_S, int i, int j) // перемена местами двух элементов массива
{
    *(arr_S + j) = *(arr_S + j) ^ *(arr_S + i);
    *(arr_S + i) = *(arr_S + j) ^ *(arr_S + i);
    *(arr_S + j) = *(arr_S + j) ^ *(arr_S + i);
}
//---------------------------------------------------------------------------------------
void swap_negmax_last(int size_arr, int *arr_S)
{
    int i = 0, j = -1, neganiv_max = 0, number_first_negativ = 0;

    while ((*(arr_S + i) > 0) && (i < size_arr))
        i++; // поиск первого отрицательного числа в массиве

    if (i == size_arr)
        return; // В массиве нет отрицательных чисел
    else
    {
        neganiv_max = *(arr_S + i);
        number_first_negativ = i;
        j = i; // присвоение на случай если отрицательный элемент в массиве один одинешенек
    }

    for (i = number_first_negativ; i < size_arr; i++)                           //  поиск максимального из отрицательных элементов массива
        if ((*(arr_S + i) < 0) && (my_ABS(neganiv_max) > my_ABS(*(arr_S + i)))) // номер элемента в массиве
        {
            neganiv_max = *(arr_S + i);
            j = i;
        }

    i_to_j_in_arr(arr_S, (size_arr - 1), j);

    return;
}
//---------------------------------------------------------------------------------------
/*
int main()
{
    int   size_arr = SIZE_ARR ;  //  0    1    2    3    4    5    6    7    8    9
    int   arr_Source[SIZE_ARR] =  {-14, -40, -84, -60, -81, -11, -12, -76, -31, -80} ; //{1, -2, -3, -4, 5, 6, 7, 8, 9, 10 } ;
    //{0} ;

    swap_negmax_last( size_arr, arr_Source) ;
    print_Array( size_arr,  arr_Source );

    return 0;
}
*/