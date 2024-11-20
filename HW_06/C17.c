#include <stdint.h>      //  Ввести число, написать функцию, в которой убедиться что 
#include <inttypes.h>    //  сумма и произведение составляющих чисел равны   YES NO
#include <stdio.h>       //  

uint64_t sum_Mult(uint64_t num_Input)
{
    uint64_t i = num_Input, j = 1, k, sum = 0, mlt = 1;
          
    while ( (i/j) > 0 )  // в этом цикле происходит разбор числа на отдельные цифры, поиск суммы и произведения всех чисел
    {
        k = (i/j) % 10 ;
        sum += k ;
        mlt *= k;
            
        j *= 10;
    } // while  

    return (sum == mlt)  ? 1 : 0 ;
}

uint64_t main() 
{                                                                         
    uint64_t num_Input ;
    scanf("%" SCNu64 , &num_Input);  

    ( sum_Mult(num_Input) > 0 ) ? printf("YES") : printf("NO");
   
    return 0;
}


                                     
      
    
    
    