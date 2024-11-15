#include <stdint.h>      //  Дан текст из английских букв и цифр, окончанием ввода является точка (.)  
#include <inttypes.h>    //  перевести все буквы в маленькие
#include <stdio.h>

int main()  // подсчёт цифр будет производиться по пробелам. 
            //  Если предыдущий символ тоже пробел, то подсчёт приостанавливается пока не будет введен символ отличный от пробела
{                                                                         
    char simbol;  

    do
    {
        simbol = getchar();
        if ( (simbol==' ') || ((simbol>='a') && (simbol<='z')) )     putchar(simbol);
        if ( (simbol>='A') && (simbol<='Z') )                        putchar('a' + (simbol - 'A'));
                
    } while ( !(simbol == '.') );
    
    return 0;
}
