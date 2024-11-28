#include <stdint.h>      //  Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, 
#include <stdio.h>       //  и вывести их на экран.
#include <inttypes.h>    //  

# define SIZE_ARR 10

void find_Dublication(int64_t *arr_S )                                 // Для контрольного массива исп. три литерала
{                                                                      // начальный - f
    uint64_t  i, j ;                                                   // первый повтор - t
    char   arr_C[] = {'f','f','f','f','f','f','f','f','f','f'} ;       // дубль - d -метится и выбывает из дальнейшего поиска

    for ( i = 0; i < SIZE_ARR-1; i++)
        if(*(arr_C + i) == 'f' )
        {
            for ( j = i+1; j < SIZE_ARR; j++)
                if ( *(arr_S + i) == *(arr_S + j)  )
                {
                    *(arr_C + i) = 't' ;
                    *(arr_C + j) = 'd' ;
                }  // if
        } // if

       for (uint64_t i = 0; i < SIZE_ARR; i++)
           if ( *(arr_C + i ) == 'f') 
               printf("%d ", *(arr_S + i ) ) ; 

}  // find_Dublication


int64_t main()               
{                                // 4 1 2 1 11 2 34 8 9 10                                         
    int64_t   arr_S[SIZE_ARR] = { 4, 1, 2, 1, 11, 2, 34, 8, 9, 11};         
    
    for(uint64_t i=0; i<SIZE_ARR; i++)    //  считывание массива
        scanf(" %" SCNd64 , &arr_S[i] );
 
    find_Dublication(arr_S );

    return 0;
}
