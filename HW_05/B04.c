#include <stdint.h>      //  ввести число , определить что в нем ровно три цифры. Или YES или NO
#include <inttypes.h>
#include <stdio.h>

int main()  // 
{  
	int64_t num_Input, x;   uint64_t i = 0, j = 1;
    scanf("%" SCNd64 , &num_Input);
  
    while ( (num_Input/j) > 0 )
    {
        j *= 10;
        i++;
    }

    (i == 3) ? printf("YES") : printf("NO") ;
     
     return 0;
}
