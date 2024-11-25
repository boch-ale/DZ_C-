#include <stdint.h>      //  ввести пять элементов массива. Найти среднее арифметическое. Результат оформить как 3f%
#include <inttypes.h>    //  
#include <stdio.h>

# define SIZE_ARR 5

int main() 
{                                                                         
    int64_t   arr_S[SIZE_ARR] = {0}, sr_ar=0;
    
    for(uint64_t i=0; i<SIZE_ARR; i++)  
    {  
        scanf(" %" SCNd64 , &arr_S[i] );
        sr_ar += arr_S[i];
    }
    printf("%.3f", ((sr_ar * 1.0)/SIZE_ARR) ) ;
    
    return 0;
}
