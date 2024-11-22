#include <stdint.h>      //  составить рекурсивную функцию , которая будет находить сумму всех чисел от 1 до N 
#include <inttypes.h>    //  
#include <stdio.h>

int64_t rec_Sum(uint64_t   n)
{
    int64_t sum ;
    if (n > 0)
        return  n + rec_Sum(n-1);
        
    return 0;
}


int64_t main() 
{                                                                         
    int64_t num_Input;

    scanf("%" SCNd64, &num_Input);

    printf(" %" PRId64, rec_Sum(num_Input) );
    
    return 0;
}
