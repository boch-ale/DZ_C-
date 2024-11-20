#include <stdint.h>      //  Сделать функцию вычисляющую факториал 
#include <inttypes.h>    // 
#include <stdio.h>       //  

uint64_t My_Factorial(uint64_t  n )
{
    uint64_t n_fact = 1, i;

    for ( i = 2; i <= n; i++)
    {
        n_fact *= i;
    }
    
    return n_fact;
}


int main() 
{                                                                         
    uint64_t num_N ;

    scanf("%" SCNu64 , &num_N );

    printf("%" PRIu64 , My_Factorial(num_N) );
    
    return 0;
}
