#include <stdint.h>      //  Вывести все простые множители числа
#include <inttypes.h>    // 
#include <stdio.h>       //  

void print_simple(uint64_t n)
{
    uint64_t ostatok = 0, i = 2;

    while ( !(n == 1) )
    {
        ostatok = n % i ;

        if (ostatok == 0)
        {
            printf(" %" PRIu64, i );           
            n = n/i ; 
        }
        else
        {
            i++;
        }
    }
}


int main() 
{                                                                         
    uint64_t num_N ;

    scanf("%" SCNu64 , &num_N );

    print_simple(num_N ) ;

    return 0;
}
