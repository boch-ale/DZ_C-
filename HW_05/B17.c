
#include <stdint.h>      //  ввести число ,  найти сумму произведение его цифр, если совпадают, вывести на экран начиная с 10 до введенного числа
#include <inttypes.h>
#include <stdio.h>

int main()  // 
{  
	int64_t num_Input, sum = 0, mlt = 1;   uint64_t i = 0, j = 1, k;
    scanf("%" SCNd64 , &num_Input);
  
    for (i=10; i<=num_Input; i++)  // цикл от 10 до введенного числа
    {  
        while ( (i/j) > 0 )  // в этом цикле происходит разбор числа на отдельные цифры, поиск суммы и произведения всех чисел
        {
            k = (i/j) % 10 ;
            sum += k ;
            mlt *= k;
            
            j *= 10;
        } // while  

        (sum == mlt)  ? printf(" %" PRId64, i ) : 0 ;

        j = 1 ;
        sum = 0;
        mlt = 1;
        
    }  //  for

    return 0;
}
