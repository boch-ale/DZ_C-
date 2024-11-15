#include <inttypes.h>
#include <stdio.h>   //  ввдодится два числа. Написать алгоритм наибольшего общего делителя(НОД Евклида)

int main()  // 
{  
    uint64_t  a = 0, b = 0, ostatok = 1, my_NOD = 0; 
	scanf("%" SCNu64 " %" SCNu64 , &a, &b) ;
    if (a < b)  { a = a ^ b; b = a ^ b; a = a ^ b; }
    
    do
    {
        ostatok = a % b ;
        a = b ;
        my_NOD = b;
        b = ostatok ;

    } while (ostatok);
  
    printf("%" PRId64  "\n",   my_NOD );

    return 0;
}
