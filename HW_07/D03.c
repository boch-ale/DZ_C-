#include <stdint.h>      //  составить рекурсивную функцию , которая будет печатать число в обратном порядке через пробел   от N до 1 
#include <inttypes.h>    //  
#include <stdio.h>

void rec_Print(uint64_t   n)
{
    printf(" %" PRIu64, n % 10 );

    if (n/10 > 0)
    {
        rec_Print( (n)/10 );
    }
}


int main() 
{                                                                         
    int64_t num_Input;

    scanf("%" SCNd64, &num_Input);

    rec_Print(num_Input) ;
    
    return 0;
}
