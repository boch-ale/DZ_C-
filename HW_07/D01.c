#include <stdint.h>      //  составить рекурсивную функцию , которая будет печатать от 1 до n 
#include <inttypes.h>    //  
#include <stdio.h>

void rec_Print(uint64_t   n)
{
    if (n > 1)
        rec_Print(n-1);
    printf(" %" PRIu64, n);
}


int main() 
{                                                                         
    int64_t num_Input;

    scanf("%" SCNd64, &num_Input);

    rec_Print(num_Input) ;
    
    return 0;
}
