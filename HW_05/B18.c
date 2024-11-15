
#include <stdint.h>      //  ввести число ,  вывести ряд Фибоначи , где каждое последующее есть сумма двух предыдущих
#include <inttypes.h>
#include <stdio.h>

int main()  // 
{  
	int64_t num_Input = 0;   uint64_t i = 0, n_A = 1, n_B = 1, n_C = 0;
    scanf("%" SCNd64 , &num_Input);
    
    printf("%" PRId64 , n_A);
    n_A = (num_Input>1) ? 0 : 1;

    for (i=1; i<num_Input; i++)  // цикл  до введенного числа
    {  
        n_C = n_A + n_B;
        printf(" %" PRId64 , n_C);

        n_A = n_B;
        n_B = n_C;    
        
    }  //  for

    return 0;
}
