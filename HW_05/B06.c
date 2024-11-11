#include <stdint.h>      //  ввести число , определить есть ли рядомстоящие одинаковые цифры. Или YES или NO
#include <inttypes.h>
#include <stdio.h>

int main()  // 
{  
	int64_t num_Input, num_Post = 10;   uint64_t i = 0, j = 1;
    scanf("%" SCNd64 , &num_Input);
  
    while ( (num_Input/j) > 0 )
    {
        i = (num_Post == (num_Input/j) % 10) ? 1 : i ;
        num_Post = (num_Input/j) % 10;
        j *= 10;
    }

    (i>0) ? printf("YES") : printf("NO");
     
     return 0;
}
