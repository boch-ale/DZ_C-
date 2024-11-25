#include <stdint.h>      //  ввести десять элементов массива. 
#include <inttypes.h>    //  Считать массив из 10 элементов и отсортировать его по последней цифре.
#include <stdio.h>

# define SIZE_ARR 10
////////////////////////////////////////////////////////////
void i_to_j_in_arr(int64_t   *arr_S, uint64_t i, uint64_t j)  // перемена местами значений массива
{
    arr_S[j] = arr_S[j] ^ arr_S[i] ;
    arr_S[i] = arr_S[j] ^ arr_S[i] ;
    arr_S[j] = arr_S[j] ^ arr_S[i] ;
}
//////////////////////////////////////////////////////////////                            
void sort_to_increasin_or_decreasing( uint64_t   inc1_or_dec0,  // сортировка по возрастанию - 1. Сортировка по убыванию - 0
                                      int64_t   *arr_S,                        
                                      uint64_t   i_begin,       //  с какого элемента начать цикл          
                                      uint64_t   i_end    )     //  до какого элемента вести цикл    
{
    for(uint64_t i = i_begin ; i < i_end-1 ; i++)    // 
    {
        for (uint64_t j = i+1; j < i_end; j++)
        {
            if ( ( arr_S[j] < arr_S[i] ) && ( inc1_or_dec0 == 1  ) )      // сортировка во возрастанию
            {
                i_to_j_in_arr(arr_S, i, j);
            }

            if ( ( arr_S[j] > arr_S[i] ) && ( inc1_or_dec0 == 0 ) )      // сортировка по убыванию
            {
                i_to_j_in_arr(arr_S, i, j);
            }

        }  // for j
    }  // for i
}
//////////////////////////////////////////////////////////////

int64_t main()               //   14  25  13  30  76        58  32  11  41  97
{                            //   13  14  25  30  76        97  58  41  32  11                                        
    int64_t   arr_S[SIZE_ARR] = {0};               //{14,25,13,30,76,58,32,11,41,97} ;
    uint64_t  median_arr = SIZE_ARR / 2 ;
    
    for(uint64_t i=0; i<SIZE_ARR; i++)  
        scanf(" %" SCNd64 , &arr_S[i] );
       
    sort_to_increasin_or_decreasing( 1, arr_S, 0, median_arr );           //  сортировка по возрастанию первой части массива 

    sort_to_increasin_or_decreasing( 0, arr_S, median_arr, SIZE_ARR );    //  сортировка по убыванию второй части массива

    for (uint64_t i = 0; i < SIZE_ARR; i++)
        printf(" %d", arr_S[i] ) ;
        
    return 0;
}
