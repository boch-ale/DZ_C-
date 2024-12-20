#include <stdint.h>   // Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для массива. 
#include <stdio.h>    // Прототип функции int count_between(int from, int to, int size, int a[]) Например, на отрезке [4, 6]
#include <inttypes.h> //  в массиве 1 2 3 4 5 6 7 8 9 10 функция вернет 3 значения
#include <string.h>



//--------------------------------------------------------------------------------
int count_between(int from, int to, int size, int *arr)          // Функция заданная условием задачи
{
    int i = 0, j = 0, rez =0 ;

    for ( i = from; i <= to; i++)
        for ( j = 0; j < size; j++)
            if( *(arr + j) == i )
                rez++ ;
        
    
    return rez ;
}

/*
int main()  //  80 89 77 81 2 88 57 64 49 33 28 58
{ // 
  //  -10 25 -20 25 -11 -32 -5 3 3 -34 -12 36 37 2 8 49 30 30 -12 14 -40 -24 40 -27 3 49 13 44 -33 2

    int size_arr = 10 ; // SIZE_ARR;
    int arr_S[10] = { 77, 81, 2, 88, 57, 64, 49, 33, 28, 58};
    int from = 80, to = 89, rez = 0 ;                           

    rez = count_between( from,  to,  size_arr,  arr_S) ;         // Функция заданная условием задачи

    printf(" %d ", rez );
    

    return 0;
}
*/
