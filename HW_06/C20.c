#include <stdint.h>      //  дана последовательность круглых скобок , заканчивается точкой(.) Определить правильность расстановки скобок, вывести YES, NO  
#include <inttypes.h>    //  
#include <stdio.h>

int main()  // подсчитаю количество правых и левых скобок, потом сравню
            //  
{                                                                         
    char simbol, first_S;  uint64_t r_S=0, l_S=0, i=0;

    do
    {
        simbol = getchar();
        
        if ( (i==0) && ((simbol==')') || (simbol=='(')) )// проверка первой введенной скобки. Это не должна быть правая скобка
        {
            first_S = simbol;
            i = 1;
        }
        r_S += (simbol=='(') ? 1 : 0;
        l_S += (simbol==')') ? 1 : 0;
                        
    } while ( !(simbol == '.') );
    
    ((r_S == l_S) && !(first_S == ')') ) ? printf("YES") : printf("NO");
    
    return 0;
}
