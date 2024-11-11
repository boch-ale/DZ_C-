#include <stdint.h>      //  ввести число , определить что числа идут по возрвстанию. Или YES или NO
#include <inttypes.h>
#include <stdio.h>

int main()  // 
{                                                                         
	int64_t num_Input, num_Post = 10;   uint64_t i = 1, j = 1, k = 10;

    scanf("%" SCNd64 , &num_Input);                                       
      
    while ( (num_Input/j) > 0 )
    {
        num_Post = (num_Input/j) % 10 ;  // выделяю по одному числу

        if (num_Post < k)   // проверка с конца каждого числа
        {
            i = 1;
        } // if
        else 
        {
            i = 0;
            break;
        }  // else

        j *= 10;
        k = num_Post;
    }
    
    ( i > 0 ) ? printf("YES") : printf("NO");
     
     return 0;
}
