#include <stdint.h>      //  Дан текст из английских букв и цифр, окончанием ввода является точка (.)  
#include <inttypes.h>    //  подсчитать сумму цифр в тексте. Оформить как функцию
#include <stdio.h>

uint64_t sum_Shtat_1_9(void)
{
    char simbol; uint64_t sum = 0; 

    do
    {
        simbol = getchar();

        sum += ((simbol>='0') && (simbol<='9')) ? (simbol - '0') :  0 ;
                
    } while ( !(simbol == '.') );
    
    return sum;
}

uint64_t main()  // 
{                                                                         
    printf("%" PRIu64, sum_Shtat_1_9() );
    return 0;
}
