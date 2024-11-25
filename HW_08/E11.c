#include <stdint.h>      //  ввести десять элементов массива. 
#include <inttypes.h>    //  Считать массив из 10 элементов и отсортировать его по последней цифре.
#include <stdio.h>

# define SIZE_ARR 10

////////////////////////////////////////////////////////////
void i_to_j_in_arr(int64_t   *arr_S, uint64_t i, uint64_t j)  // перемена местами двух элементов массива
{
    arr_S[j] = arr_S[j] ^ arr_S[i] ;
    arr_S[i] = arr_S[j] ^ arr_S[i] ;
    arr_S[j] = arr_S[j] ^ arr_S[i] ;
}

//////////////////////////////////////////////////////////////

int64_t main()               
{                                                                    
    int64_t   arr_S[SIZE_ARR] = {0};               //{14,25,13,30,76,58,32,11,41,97} ;
    uint64_t  median_arr = SIZE_ARR / 2 ;
    
    for(uint64_t i=0; i<SIZE_ARR; i++)    //  считывание массива
        scanf(" %" SCNd64 , &arr_S[i] );
       
    for(uint64_t i =0 ; i < SIZE_ARR-1 ; i++)    //  сортирую массив по возрастанию по последней цифре
    {
        for (uint64_t j = i+1; j < SIZE_ARR; j++)
        {
            if (arr_S[j]%10 < arr_S[i]%10)
                i_to_j_in_arr(arr_S, i, j );

        }  // for j
    }  // for i

    
    for (uint64_t i = 0; i < SIZE_ARR; i++)
        printf(" %d", arr_S[i] ) ;
        
    return 0;
}
