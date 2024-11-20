#include <stdint.h>      //  вычислить сумму от 1 до N 
#include <inttypes.h>    //  
#include <stdio.h>

uint64_t My_Sum_1_to_N(uint64_t a)
{
    uint64_t sum_N = 0;
    for (uint64_t i = 1; i <= a; i++)
    {
        sum_N += i; 
    }
    
    return sum_N;
}


int main() 
{                                                                         
    uint64_t num_N ;

    scanf("%" SCNd64 , &num_N);

    printf("%" PRId64 , My_Sum_1_to_N(num_N) );
    
    return 0;
}
