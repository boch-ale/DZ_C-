#include <stdint.h>      //  составить рекурсивную функцию , которая будет печатать строку в обратном порядке  
#include <inttypes.h>    //  
#include <stdio.h>

void rec_Print_String_Naeborot(char  n )
{
    n = getchar();
    if ( !(n == '.') )
    {
        rec_Print_String_Naeborot( n ) ;
        putchar( n );
    }
}


int main() 
{                                                                         
    int64_t num_Input;

    rec_Print_String_Naeborot( ' ' ) ;
    
    return 0;
}
