#include <stdint.h>      //  составить рекурсивную функцию , которая будет печатать от числа N в обратном порядке через пробел   от N до 1 
#include <inttypes.h>    //  веедено 5      результат 5 4 3 2 1
#include <stdio.h>

void rec_Print_Naeborot(uint64_t   n)
{
    printf(" %" PRIu64, n  );

    if (n > 1)
    {
        rec_Print_Naeborot( n-1 );
    }
}


int main() 
{                                                                         
    int64_t num_Input;

    scanf("%" SCNd64, &num_Input);

    rec_Print_Naeborot(num_Input) ;
    
    return 0;
}
