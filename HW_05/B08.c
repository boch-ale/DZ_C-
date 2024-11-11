#include <stdint.h>      //  ввести число , определить что  число "9" повторяется только один раз. Или YES или NO
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
            
        j *= 10;
    }
    
    ( arr_Num[9] == 1 ) ? printf("YES") : printf("NO");
     
     return 0;
}
