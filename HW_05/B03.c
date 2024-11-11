
#include <stdint.h>      //  ввести два числа (a<=b), вывести сумму квадратов всех чисел между ними
#include <stdio.h>
#include <inttypes.h>

int main()  // 
{  
    uint64_t num_A, num_B, sum_Q = 0;

    scanf("%" SCNu64 " %" SCNu64, &num_A, &num_B);
    
    num_A = (num_A>num_B) ? num_B : num_A ;
    num_B = (num_B>100) ? 100 : num_B;

    for(uint64_t i=num_A; i<=num_B; i++)
    {
	    sum_Q += i * i;
    }
    printf(" %" PRIu64 , sum_Q );
    return 0;
}
