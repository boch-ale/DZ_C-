
#include <stdint.h>      //  На входе два целых не отрицательных натуральных числа. Получить среднее арифметическое исп функцию   
#include <inttypes.h>    //  
#include <stdio.h>

uint64_t My_Middle(uint64_t a, uint64_t b)
{
    return (a + b)/2 ;
}


int main() 
{                                                                         
    uint64_t num_N, num_P;

    scanf("%" SCNd64 " %" SCNd64, &num_N, &num_P);
    
    printf("%" PRId64 , My_Middle(num_N, num_P) );
    
    return 0;
}
