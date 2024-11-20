#include <stdint.h>      //  Дан текст из английских букв и цифр, окончанием ввода является точка (.)  
#include <inttypes.h>    //  подсчитать количество цифр в тексте. Оформить как функцию
#include <stdio.h>

uint64_t shtat_1_9(void)
{
    char simbol; uint64_t i = 0; 

    do
    {
        simbol = getchar();

        i += ((simbol>='0') && (simbol<='9')) ? 1 :  0 ;
                
    } while ( !(simbol == '.') );
    
    return i;
}

uint64_t main()  // 
{                                                                         
    printf("%" PRIu64, shtat_1_9() );
    return 0;
}
