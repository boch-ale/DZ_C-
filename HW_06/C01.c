#include <stdint.h>      //  Вывести модуль числа применив функцию  
#include <inttypes.h>    //  
#include <stdio.h>

int64_t My_ABS(int64_t   a)
{
    return a *= (a<0) ? -1 : 1 ;
}


int main() 
{                                                                         
    int64_t num_Input;

    scanf("%" SCNd64, &num_Input);

    printf("%" PRId64, My_ABS(num_Input) );
    
    return 0;
}
