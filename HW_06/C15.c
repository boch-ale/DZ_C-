#include <stdint.h>      //  Ввести число, убедиться что цифры в нем расположены по возрастанию    YES NO
#include <inttypes.h>    //  N>=0     2>= P >=9
#include <stdio.h>       //  

uint64_t my_Progress(uint64_t num_Input)
{
    uint64_t num_Post = 10, j = 1, i = 1, k = 10;

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
  
    return i;
}

uint64_t main() 
{                                                                         
    uint64_t num_Input ;

    scanf("%" SCNu64 , &num_Input);  

    ( my_Progress(num_Input) > 0 ) ? printf("YES") : printf("NO");
   
    return 0;
}


                                     
      
    
    
    