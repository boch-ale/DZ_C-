#include <stdint.h>      //  ввести последовательность чисел, окончанием ввода является ноль.  
#include <inttypes.h>    //  Подсчитать количество чётных чисел, ноль не входит
#include <stdio.h>

const char SPACE = ' ' ;
const char MY_NULL = '0' ;

int main()  // определение чисел будет производиться по пробелам. 
            //  Если предыдущий символ тоже пробел, то подсчёт приостанавливается пока не будет введен символ отличный от пробела
{                                                                      
    char simbol, char_Prev = SPACE;  uint64_t i = 0, num_Val =0;

    while ( 1 )     //  цикл идёт пока введенный символ не ноль, а предыдущий символ не пробел,  т.к ноль может быть в составе числа
    {                                               //   
        simbol = getchar();
        if ( (simbol == MY_NULL) && (char_Prev == SPACE) )  { break; }   // условие выхода из цикла, ноль в конце
                                                                   
        if ( (simbol == SPACE) && (num_Val > 0) ) 
        {
            i+=( (num_Val % 2) > 0 ) ? 0 : 1 ;  // проверка на чётность собранного числа
            num_Val = 0 ;
        }
        else  //собираем число
        {
            num_Val = num_Val*10 + simbol-MY_NULL ;
        }
        char_Prev = simbol;
    }

    printf("%" PRId64 "\n", i);
            
    return 0;
}
