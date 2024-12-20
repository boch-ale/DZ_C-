#include <stdint.h>   //  оставить функцию которая возвращает сумму элементов в заданном отрезке
#include <stdio.h>    // С [from, to] для массива. Прототип функции int sum_between_ab(int from, int to, int size, int a[])
#include <inttypes.h> // 
#include <string.h>



//--------------------------------------------------------------------------------
int  sum_between_ab(int from, int to, int size, int *arr)          // Функция заданная условием задачи
{
    if (from >= to)
    {
        from = from ^ to ;
        to   = from ^ to ;
        from = from ^ to ;
    }
    
    int i = 0, j = 0, rez =0 ;

    for ( i = from; i <= to; i++)
        for ( j = 0; j < size; j++)
            if( *(arr + j) == i )
                rez += i ;
        
    
    return rez ;
}

/*
int main()  //  80 89 77 81 2 88 57 64 49 33 28 58         60 50 89 71 6 40 61 75 53 64 79 97
{ // 
  //  -10 25 -20 25 -11 -32 -5 3 3 -34 -12 36 37 2 8 49 30 30 -12 14 -40 -24 40 -27 3 49 13 44 -33 2

    int size_arr = 10 ; // SIZE_ARR;
    int arr_S[10] = { 89, 71, 6, 40, 61, 75, 53, 64, 79, 97};
    int from = 60, to = 50, rez = 0 ;                           

    rez = sum_between_ab( from,  to,  size_arr,  arr_S) ;         // Функция заданная условием задачи

    printf(" %d ", rez );
    

    return 0;
}
*/
