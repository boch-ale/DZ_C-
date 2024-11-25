#include <stdint.h>      //  ввести десять элементов массива. 
#include <inttypes.h>    //  Считать массив из 10 элементов и отсортировать его по последней цифре.
#include <stdio.h>

# define SIZE_ARR 10


int64_t main()               
{                                                                           //  { 40, 105, 203, 1, 14, 1000, 22, 33, 44, 55 }                                   
    int64_t   arr_S[SIZE_ARR] = {0},  arr_C[SIZE_ARR] = {0};               //{14,25,13,30,76,58,32,11,41,97} ;
    int64_t  a = 0 ;

    for(uint64_t i=0; i<SIZE_ARR; i++)    //  считывание массива
    {    
        scanf(" %" SCNd64 , &arr_S[i] );
      
        a = arr_S[i]/10;
        arr_C[i] = (a%10 == 0) ? arr_S[i] : 0 ;
    }   
    
    for (uint64_t i = 0; i < SIZE_ARR; i++)
        (arr_C[i]) > 0 ? printf(" %d", arr_C[i] ) : 0 ;
        
    return 0;
}
