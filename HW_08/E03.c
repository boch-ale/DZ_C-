#include <stdint.h>      //  ввести десять элементов массива. Найти максимальные и минимальные значения в массиве и их номера
#include <inttypes.h>    //  
#include <stdio.h>

# define SIZE_ARR 10

int main() 
{                                                                         
    int64_t   arr_S[SIZE_ARR] = {0}, min_arr[2] = {0},  max_arr[2] = {0};
    
    for(uint64_t i=0; i<SIZE_ARR; i++)  
    {  
        scanf(" %" SCNd64 , &arr_S[i] );
        if (i == 0)
        {
            min_arr[0] = i;
            min_arr[1] = arr_S[i] ;
            max_arr[0] = i;
            max_arr[1] = arr_S[i] ;
        }

        if (min_arr[1] > arr_S[i]) // поиск минимума
        {
            min_arr[0] = i;
            min_arr[1] = arr_S[i] ;
        }

        if (max_arr[1] < arr_S[i])  // поиск максимума
        {
            max_arr[0] = i;
            max_arr[1] = arr_S[i] ;
        }
    }  // for i

    printf("%d %d %d %d", (max_arr[0]+1), max_arr[1], (min_arr[0]+1), min_arr[1] ) ;
    return 0;
}
