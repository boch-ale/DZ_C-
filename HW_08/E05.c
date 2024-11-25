#include <stdint.h>      //  ввести 10 элементов массива. сложить все положительные
#include <inttypes.h>    //  
#include <stdio.h>

# define SIZE_ARR 10

int main() 
{                                                                         
    int64_t   arr_S[SIZE_ARR] = {0}, sum_P = 0;
    
    for(uint64_t i=0; i<SIZE_ARR; i++)  
    {  
        scanf(" %" SCNd64 , &arr_S[i] );
        sum_P += (arr_S[i] > 0) ? arr_S[i] : 0 ;
    }
    printf("%d", sum_P ) ;
    
    return 0;
}
