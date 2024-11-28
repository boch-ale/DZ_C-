#include <stdint.h>      // Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, 
#include <stdio.h>       //   во второй - только отрицательные. Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов. 
#include <inttypes.h>    //  

# define SIZE_ARR 10

void negativ_and_Positiv(int64_t *arr_S, int64_t *arr_N, int64_t *arr_P )                    
{                                                                      
    uint64_t  i ;                                                   
                                                                       
    for ( i = 0; i < SIZE_ARR; i++)
    {
        *(arr_N + i ) = (*(arr_S + i) < 0) ? *(arr_S + i) : 0 ;
        *(arr_P + i ) = (*(arr_S + i) > 0) ? *(arr_S + i) : 0 ;
    }    
        
}  // find_Dublication


void print_Positiv_N(int64_t *arr_S )
{
    for (uint64_t i = 0; i < SIZE_ARR; i++)
    {    
        ( *(arr_S + i ) > 0)  ? printf("%d ", *(arr_S + i ) ) : 0 ;
        ( *(arr_S + i ) < 0)  ? printf("%d ", *(arr_S + i ) ) : 0 ;
    }
}


int64_t main()               
{                                // 4 1 2 1 11 2 34 8 9 10                                         
    int64_t   arr_S[SIZE_ARR] = { 4, 1, -2, 1, -11, 2, -34, 8, 9, 10};         
    int64_t   arr_N[SIZE_ARR] = {0} ;
    int64_t   arr_P[SIZE_ARR] = {0} ;   

    for(uint64_t i=0; i<SIZE_ARR; i++)    //  считывание массива
        scanf(" %" SCNd64 , &arr_S[i] );
 
    negativ_and_Positiv(arr_S, arr_N, arr_P );

    print_Positiv_N(arr_P );
    print_Positiv_N(arr_N );

    return 0;
}
