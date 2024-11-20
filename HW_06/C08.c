#include <stdint.h>      //  Дан текст из английских букв и цифр, окончанием ввода является точка (.)  
#include <inttypes.h>    //  перевести все буквы в большие
#include <stdio.h>

int main()  // 
{                                                                         
    char simbol;  

    do
    {
        simbol = getchar();

        if (simbol == '.')   break; 
        
        ((simbol>='a') && (simbol<='z')) ? putchar('A' + (simbol - 'a') ) :  putchar(simbol);
                
    } while ( !(simbol == '.') );
    
    return 0;
}
