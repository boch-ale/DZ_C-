#include <stdint.h>      //  ввести натуральное число , определить простое оно или нет. вывести "YES", иначе "NO"
#include <inttypes.h>    //  простым является число которое делится на "1" и на само себя
#include <stdio.h>

int main()  // 
{  
	int64_t num_Input;   uint64_t i = 0, j = 1;
    scanf("%" SCNd64 , &num_Input);

    j = num_Input;
    j = (num_Input == 2) ? 1 : j ;
    j = (num_Input == 1) ? 0 : j ;

    for (i=2; i<j; i++)
    {
        if ( (num_Input % i) == 0)
        {
            j = 0;
            break;
        }
    }

    (j == 0) ? printf("NO") : printf("YES");

    return 0;
}
