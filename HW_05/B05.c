#include <stdint.h>      //  ввести число , определить найти сумму его цифр
#include <inttypes.h>
#include <stdio.h>

int main()  // 
{  
	int64_t num_Input, sum = 0;   uint64_t i = 0, j = 1;
    scanf("%" SCNd64 , &num_Input);
  
    while ( (num_Input/j) > 0 )
    {
        sum += (num_Input/j) % 10 ;
        j *= 10;
    }

    printf("%" PRId64, sum) ;
     
     return 0;
}
