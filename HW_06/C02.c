#include <stdint.h>      //  На входе два числа N < ABS(1000), P>=0 . Возвести N в степень P . Сделать через функцию  
#include <inttypes.h>    //  
#include <stdio.h>

int64_t My_Dgr(int64_t a, int64_t b)
{
    int64_t dgr = 1;
    for (uint64_t i = 1; i <= b; i++)
    {
        dgr *= a; 
    }
    
    return dgr;
}


int main() 
{                                                                         
    int64_t num_N, num_P, dgr;

    scanf("%" SCNd64 " %" SCNd64, &num_N, &num_P);

    dgr = (num_P<=0) ? 1 : My_Dgr(num_N, num_P) ;
    
    printf("%" PRId64 , dgr );
    
    return 0;
}
