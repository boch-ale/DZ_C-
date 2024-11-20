#include <stdint.h>      //  Сколько зёрен на клетке шахмaтной доски. Начинается с 1 и затем удваивается 
#include <inttypes.h>    //  Фактически задача сводится к поиску значения основания 2 в степени N-1
#include <stdio.h>

uint64_t My_Dgr(uint64_t n)
{
    uint64_t dgr = 1;
    for (uint64_t i = 1; (i <=n-1); i++)
    {
        dgr *= 2; 
    }
    
    return dgr;
}


int main() 
{                                                                         
    uint64_t num_N, dgr;

    scanf("%" SCNu64 , &num_N);

    printf("%" PRIu64 , My_Dgr(num_N ) );
    
    return 0;
}
