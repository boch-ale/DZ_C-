#include <stdint.h>      //  ввести число , переставить местами числа 4582 --  2854. 
#include <inttypes.h>
#include <stdio.h>

int main()  // 
{                                                                         
	int64_t num_Input, num_Post, num_Revers = 0;   uint64_t  j = 1;

    scanf("%" SCNd64 , &num_Input);                                       
      
    while ( (num_Input/j) > 0 )
    {
        num_Post = (num_Input/j) % 10 ;  // выделяю по одному числу

        num_Revers += num_Post ;
        num_Revers *= 10 ;
          
        j *= 10;
 
    }
    num_Revers /= 10;
    printf( "%" PRId64, num_Revers );
     
     return 0;
}
