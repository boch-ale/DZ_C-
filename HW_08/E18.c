#include <stdint.h>      //  В диапазоне натуральных чисел от 2 до N определить, сколько из них кратны любому из чисел в диапазоне от 2 до 9.
#include <stdio.h>       //  
#include <inttypes.h>    //  

# define SIZE_ARR 8      //  элементы массива будут соответствовать цифрам от 2-х до 9-ти

void find_Multy(uint64_t u_N )                    
{                                                                      
    uint64_t  i, j, multy = 0 ;  
    int64_t   arr_S[SIZE_ARR] = {0};
                                                                       
    for ( i = 2; i < 10; i++) 
    {   
        multy = 0 ;                                   // 
        for ( j = i; j <= u_N; j++)
            multy += ( j % i == 0 ) ? 1 : 0 ;        // 

        *(arr_S + i-2) = multy ;
    }

    for ( i = 0; i < SIZE_ARR; i++)  
        printf("%5d  %5d \n", i+2, *(arr_S + i));                                          //                             

}  // find_Dublication


int64_t main()               
{    
    uint64_t u_N ;                                                     
    scanf(" %" SCNd64 , &u_N );

    find_Multy( u_N ) ;

    return 0;
}
