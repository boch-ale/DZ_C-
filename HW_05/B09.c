#include <stdint.h>      //  ввести число , определить что каждое число является чётным. Или YES или NO
#include <inttypes.h>
#include <stdio.h>

int main()  // 
{                                                                         
	int64_t num_Input, num_Post = 10;   uint64_t i = 0, j = 1;

    scanf("%" SCNd64 , &num_Input);                                       
      
    while ( (num_Input/j) > 0 )
    {
        num_Post = (num_Input/j) % 10 ;  // выделяю по одному числу

        if ( (num_Post % 2) == 0 )   // проверка на чётность
        {
            i = 1;
        } // if
        else 
        {
            i = 0;
            break;
        }  // else

        j *= 10;
    }
    
    ( i > 0 ) ? printf("YES") : printf("NO");
     
     return 0;
}
