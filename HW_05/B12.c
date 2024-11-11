#include <stdint.h>      //  ввести число , найти в нем наименьшее и наибольшее и вывести через пробел
#include <inttypes.h>
#include <stdio.h>

int main()  // 
{                                                                         
	int64_t num_Input, num_Post;   uint64_t i = 1, j = 1, n_Min = 10, n_Max = 0;

    scanf("%" SCNd64 , &num_Input);                                       
      
    while ( (num_Input/j) > 0 )
    {
        num_Post = (num_Input/j) % 10 ;  // выделяю по одному числу

        n_Min = (n_Min > num_Post) ? num_Post : n_Min ;
        n_Max = (n_Max < num_Post) ? num_Post : n_Max ;
          
        j *= 10;
 
    }
    
    printf( "%" PRId64 " %" PRId64 "\n", n_Min, n_Max );
     
     return 0;
}
