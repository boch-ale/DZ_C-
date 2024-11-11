#include <stdint.h>   //  ввести число от 1 до 100, вывести квадраты и кубы этого числа 
#include <stdio.h>
#include <inttypes.h>

int main()  // 
{  
    uint64_t num_Val = 1;

    scanf("%" SCNu64, &num_Val);
    
    num_Val = (num_Val<1) ? 1 : num_Val ;     // проверка введённого числа
    num_Val = (num_Val>100) ? 100 : num_Val;

    for(uint64_t i=1; i<=num_Val; i++)
    {
	    printf("%" PRIu64 " %" PRIu64 " %" PRIu64 "\n", i, i*i, i*i*i);
    }
    return 0;
}
