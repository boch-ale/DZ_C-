#include <stdint.h>   // Составить функцию которая находит след матрицы в двумерном массиве. Показать пример ее работы
#include <stdio.h>    //  на матрице из 5 на 5 элементов. След матрицы - это сумма элементов на главной диагонали.
#include <inttypes.h> // 
#include <string.h>   // 

#define ARR_SIZE 5

//--------------------------------------------------------------------------------
int64_t main()  //   1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5
{ 
    uint64_t size_arr = ARR_SIZE,    i = 0,  j = 0 ;
    int64_t arr_S[ARR_SIZE][ARR_SIZE] = {0}, sled = 0, n_input = 0 ;

    for(i=0; i < size_arr; i++)
        for ( j = 0; j < size_arr; j++)
            scanf("%d", &arr_S[i][j]) ;

    for(i=0; i < size_arr; i++)
        for ( j = 0; j < size_arr; j++)
            if( i == j ) 
                sled += arr_S[i][i] ;
    
    printf("%d", sled);

    return 0;
}

