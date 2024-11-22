#include <stdint.h>      //  составить рекурсивную функцию , которая будет переводить число из десятичной в двоичную систему
#include <inttypes.h>    //  
#include <stdio.h>

void rec_Print(uint64_t   n)
{
    if (n/10 > 0)
    {
        rec_Print( (n)/10 );
    }
    printf(" %" PRIu64, n % 10 );
}


int main() 
{                                                                         
    int64_t num_Input;

    scanf("%" SCNd64, &num_Input);

    rec_Print(num_Input) ;
    
    return 0;
}
