#include <stdint.h>      //  ввести пять элементов массива. Найти минимальное значение в массиве
#include <inttypes.h>    //  
#include <stdio.h>

# define SIZE_ARR 5

int main() 
{                                                                         
    int64_t   arr_S[SIZE_ARR] = {0}, min_arr = 0;
    
    for(uint64_t i=0; i<SIZE_ARR; i++)  
    {  
        scanf(" %" SCNd64 , &arr_S[i] );
        min_arr = (i == 0) ? arr_S[i] : min_arr ;
        min_arr = (min_arr > arr_S[i]) ?  arr_S[i] : min_arr ;
    }
    printf("%d", min_arr ) ;
    return 0;
}
