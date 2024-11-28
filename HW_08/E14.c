#include <stdint.h>      //  Считать массив из 10 элементов и выделить в другой массив все числа, которые встречаются более одного раза.
#include <stdio.h>       //  В результирующем массиве эти числа не должны повторяться. 
#include <inttypes.h>    //  

# define SIZE_ARR 10

void find_Dublication(int64_t *arr_S, char *arr_C )                    // Для контрольного массива исп. три литерала
{                                                                      // начальный - f
    uint64_t  i, j ;                                                   // первый повтор - t
                                                                       // дубль - d -метится и выбывает из дальнейшего поиска
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
}  // find_Dublication


void print_cho_Nashel(int64_t *arr_S, char *arr_C )
{
    for (uint64_t i = 0; i < SIZE_ARR; i++)
        ( *(arr_C + i ) == 't')  ? printf(" %d", *(arr_S + i ) ) : 0 ;
}


int64_t main()               
{                                // 4 1 2 1 11 2 34 8 9 10                                         
    int64_t   arr_S[SIZE_ARR] = { 4, 1, 2, 1, 11, 2, 34, 8, 9, 10};         
    char   arr_C[] = {'f','f','f','f','f','f','f','f','f','f'} ; 

    for(uint64_t i=0; i<SIZE_ARR; i++)    //  считывание массива
        scanf(" %" SCNd64 , &arr_S[i] );
 
    find_Dublication(arr_S, arr_C );

    //for (int64_t i = 0; i < SIZE_ARR; i++)   printf("%c ", *(arr_C + i)) ;
    
    print_cho_Nashel(arr_S, arr_C);
            
    return 0;
}
