#include <stdint.h>      //  Найти сумму цифр числа и убедиться , что это чётное число   YES  NO 
#include <inttypes.h>    //  
#include <stdio.h>       //  

uint64_t sum_find(uint64_t  num_Input ) 
{
    
    uint64_t   sum = 0, j = 1;
      
    while ( (num_Input/j) > 0 )
    {
        sum += (num_Input/j) % 10 ;
        j *= 10;
    }
    return sum;
}


int main() 
{                                                                         
    uint64_t num_N ;

    scanf("%" SCNu64 , &num_N );

    ( (sum_find(num_N) % 2) == 0) ? printf("YES") : printf("NO") ;
    
    return 0;
}
