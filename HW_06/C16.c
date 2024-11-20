#include <stdint.h>      //  Ввести число, написать функцию, в которой убедиться что оно простое   YES NO
#include <inttypes.h>    //  простое - делится на 1 и само себя
#include <stdio.h>       //  

uint64_t my_Prst(uint64_t num_Input)
{
    uint64_t i = 0, j = 1;
    
    j = num_Input;
    j = (num_Input == 2) ? 1 : j ;
    j = (num_Input == 1) ? 0 : j ;

    for (i=2; i<j; i++)
    {
        if ( (num_Input % i) == 0)
        {
            j = 0;
            break;
        }
    }
    return j;
}

uint64_t main() 
{                                                                         
    uint64_t num_Input ;
    scanf("%" SCNu64 , &num_Input);  

    ( my_Prst(num_Input) > 0 ) ? printf("YES") : printf("NO");
   
    return 0;
}


                                     
      
    
    
    