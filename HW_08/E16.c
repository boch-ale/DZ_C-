#include <stdint.h>      //  Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. 
#include <stdio.h>       //  Гарантируется, что такое число ровно 1. 
#include <inttypes.h>    //  

# define SIZE_ARR 10

int64_t find_Dublication(int64_t *arr_S )                    
{                                                                      
    uint64_t  arr_C[SIZE_ARR] = {0};
    uint64_t  i, j, povtor = 0 ;                                                  
                                                                       
    for ( i = 0; i < SIZE_ARR-1; i++)                                           // поск повторяющихся цифр а массиве arr_S
        for ( j = i+1; j < SIZE_ARR; j++)
            *(arr_C + i) += ( *(arr_S + i) == *(arr_S + j)  ) ? 1 : 0 ;        // счетчик количества повторений данного числа

    j = 0 ;
    povtor = *arr_C ;
    for ( i = 1; i < SIZE_ARR; i++)                                            // поиск наибольшего значения в массиве повторов                            
        if ( *(arr_C+i) > *(arr_C+j) )                                         // и индекс этого иаибольшего 
        {    
            povtor = *(arr_C + i ) ;
            j = i ;
        } 
    return *(arr_S + j) ;  

}  // find_Dublication


int64_t main()               
{                                // 4 1 2 1 11 2 34 8 9 10            4  1  2  1  11  2  34  11  0  11                             
    int64_t   arr_S[SIZE_ARR] = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 3 };    // 1 2 2 3 3 3 4 4 4 3    100, 100, 102, 103, 104, 105, 106, 107, 108, 109

    for(uint64_t i=0; i<SIZE_ARR; i++)    //  считывание массива
        scanf(" %" SCNd64 , &arr_S[i] );

    printf("%d", find_Dublication(arr_S) ) ;

    return 0;
}
