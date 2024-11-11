#include <stdint.h>      //  ввести число , определить есть ли в нем повторяющиеся цифры. Или YES или NO
#include <inttypes.h>
#include <stdio.h>

int main()  // 
{                                                                         
	int64_t num_Input, num_Post = 10;   uint64_t i = 0, j = 1, arr_Num[10] = {0,0,0,0,0,0,0,0,0,0};
    scanf("%" SCNd64 , &num_Input);                                       
      
    while ( (num_Input/j) > 0 )
    {
        num_Post = (num_Input/j) % 10 ;
        arr_Num[num_Post]++ ; 
        i = (arr_Num[num_Post] > 1) ? 1 : i ;    
        j *= 10;
    }
    
    (i>0) ? printf("YES") : printf("NO");
     
     return 0;
}
