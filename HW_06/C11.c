#include <stdint.h>      //   Найти наибольший общий делитетель для двух введённых чисел --- НОД
#include <inttypes.h>    // 
#include <stdio.h>       //  

uint64_t nod(uint64_t a, uint64_t b)
{
    uint64_t ostatok, my_nod = 0;
    do
    {
        ostatok = a % b ;
        a = b ;
        my_nod = b;
        b = ostatok ;

    } while (ostatok);
    
    return my_nod;
}


int main() 
{                                                                         
    uint64_t  a = 0, b = 0 ; 

	scanf("%" SCNu64 " %" SCNu64 , &a, &b) ;

    if (a < b)        //  Передача чисел в функцию должна производится по убыванию
    { 
        a = a ^ b; 
        b = a ^ b; 
        a = a ^ b; 
    }

    printf("%" PRIu64 , nod(a,b) );
    
    return 0;
}
 