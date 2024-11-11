#include <stdint.h>      //  ввести число , найти в нем количество чётных и нечётных цифр и вывести через пробел
#include <inttypes.h>
#include <stdio.h>

int main()  // 
{                                                                         
	int64_t num_Input, num_Post;   uint64_t  j = 1, n_Even = 0, n_Odd = 0;

    scanf("%" SCNd64 , &num_Input);                                       
    n_Even = ( num_Input == 0 ) ? 1 : 0 ;

    while ( (num_Input/j) > 0 )
    {
        num_Post = (num_Input/j) % 10 ;  // выделяю по одному числу

        ( (num_Post % 2) == 0 ) ? n_Even++ : n_Odd++ ;
        
          
        j *= 10;
 
    }
    
    printf( "%" PRId64 " %" PRId64 "\n", n_Even, n_Odd );
     
     return 0;
}
