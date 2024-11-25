#include <stdint.h>      //  ввести десять элементов массива. Найти  два максимальных  в массиве и сложить
#include <inttypes.h>    //  
#include <stdio.h>

# define SIZE_ARR 10

int64_t main() 
{                                                                         
    int64_t   arr_S[SIZE_ARR] = {0} ;
    
    for(uint64_t i=0; i<SIZE_ARR; i++)  
        scanf(" %" SCNd64 , &arr_S[i] );
       
    for(uint64_t i =0 ; i < SIZE_ARR-1 ; i++)    //  сортирую массив по возрастанию , затем складываю два последних элемента
    {
        for (uint64_t j = i+1; j < SIZE_ARR; j++)
        {
            if (arr_S[j] < arr_S[i])
            {
                arr_S[j] = arr_S[j] ^ arr_S[i] ;
                arr_S[i] = arr_S[j] ^ arr_S[i] ;
                arr_S[j] = arr_S[j] ^ arr_S[i] ;
            }
        }  // for j
    }  // for i

    printf("%d", arr_S[SIZE_ARR - 1] + arr_S[SIZE_ARR - 2] ) ;
    return 0;
}
