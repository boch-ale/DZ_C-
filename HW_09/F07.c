#include <stdint.h>   // Написать функцию, которая сжимает серии массива, состоящего из единиц и нулей по следующему принципу:
#include <stdio.h>    // например, массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1] преобразуется в [4,7,2,4] (т.к. начинается с нуля,
#include <inttypes.h> // то сразу записывается количество элементов первой серии); а массив [1,1,1,0,0,0,0,0,0,0] преобразуется
#include <string.h>   //  в [0,3,7] (т.к. первая серия - это единицы, то первый элемент преобразованного массива 0).
                      // Необходимо реализовать только одну функцию, всю программу загружать не надо. Прототип функции:
                      // int compression(int a[], int b[], int N)  fункция принимает исходный массив a[] и сжимает в массив b[],
                      // N - число элементов в массиве a[].    Функция возвращает число элементов сжатого массива b[]

//--------------------------------------------------------------------------
int size_array_B(int *a, int N) // расчёт размерности результирующего массива
{
    int size_arr_b = 1, i = 0;

    for (i = 1; i < N; i++)
        size_arr_b += (*(a + i) == *(a + i - 1)) ? 0 : 1;

    size_arr_b += (*a) ? 1 : 0; // если входной массив начинается с "1", то добавляю один элемент в результирующий массив под учёт "0"
    // printf("size_b_func = %d\n", size_arr_b );
    return size_arr_b;
}
//--------------------------------------------------------------------------
int compression(int *a, int *b, int N) // функция заданная условием задачи
{

    int size_arr_b = size_array_B(a, N);
    // for (int i = 0; i < size_arr_b; i++)        printf("%d ", *(b+i)) ;
    int i = 1, j = 0, sum_elements_b = 0, compress = 1;
    // int b1[size_arr_b] ;

    if (*a) // если исходный массив начинается с "1", формируется начало результирующего массива с учётом нуля
    {
        b[0] = 0;
        j = 1;
        compress = 1;
    }
    else
    {
        b[0] = 1;
        j = 0;
    }

    for (i = 1; i < N; i++)
    {
        if (*(a + i) == *(a + i - 1))
            compress++;
        else
        {
            sum_elements_b += compress;
            *(b + j) = compress;
            j++;
            compress = 1;
        }
        // printf("i = %d   N = %d   a[%d] =  %d   a[%d] = %d    compress = %d    j = %d\n", i, N, i, *(a+i), i-1, *(a+i-1), compress, j ) ;
    }

    *(b + j) = compress;
    // for (int i = 0; i < size_arr_b; i++)        printf("b[%d] =  %d\n", i, *(b+i)) ;

    return size_arr_b;
}
//--------------------------------------------------------------------------
/*   0 1 0 1 1 0 1 1 1 0  0 0 1 0 0 1 0 0 0 0  0 0 0 1 1 1 1 0 1 0  1 1 1 1 0 1 1 0 0 1  1 1 0 0 0 0 1 0 0 0
     1 1 0 0 1 1 0 1 1 1  0 0 1 0 0 1 1 0 1 0  0 0 1 1 1 1 0 0 1 0  1 1 1 0 0 1 0 1 1 0  1 0 0 1 0 1 1 0 0 1
     0                   10                   20                   30                   40                49
    [1,1,1,2,1,3,3,1,2,1, 7,4,1,1,1,4,1,2,2,3, 4,1,3,2,2,2,1,3,2,1, 2,2,1,1,3,4,2,1,1,3, 2,1,1,2,1,1,2,1,1,2, 2,1] = 52
                       10                   20                   30                   40        45         50 51 52
*/
/*
int64_t main()
{
    int arr_S[100]={
                     0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0,
                     1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1

                   } ;
    int size_arr = 100 ;  //17 ;

    int size_arr_b = size_array_B(arr_S, size_arr) ;                                printf("size_b = %d\n", size_arr_b );
    int arr_b[size_arr_b] ;


    compression(arr_S, arr_b,  size_arr) ;
    //printf("%d", is_two_same(size_arr, arr_S) );

    return 0;
}
*/