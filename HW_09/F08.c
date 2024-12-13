// В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)в произвольном порядке, но одно из чисел пропущено 
// (остальные встречаются ровно по одному разу). N не превосходит 1000. Последовательность заканчивается числом 0. Определить пропущенное число
// 

#include <stdint.h>      // 
#include <stdio.h>       //  
#include <inttypes.h>    //
#include <string.h>

#define SIZE_ARR 999

void i_to_j_in_arr(int *arr_S, uint64_t i, uint64_t j)  // перемена местами двух элементов массива
{
    *(arr_S+j) = *(arr_S+j) ^ *(arr_S+i) ;
    *(arr_S+i) = *(arr_S+j) ^ *(arr_S+i) ;
    *(arr_S+j) = *(arr_S+j) ^ *(arr_S+i) ;
}

void sort_array(int size_arr, int *arr_S)       //  перестановка цифр массива по убыванию
{
    uint64_t i, j;

    for ( i = 0; i < size_arr-1; i++)             
        for ( j = i+1; j < size_arr; j++)
            if( *(arr_S +i) < *(arr_S+j) )
                i_to_j_in_arr(arr_S, i, j);
}

int finf_Excluded(int size_arr, int *arr_S)       //  поиск пропущенного числа
{
    int i=0, j = 0 ;

    i = *arr_S ;
    j = 1 ;
    while ( *(arr_S+j) )
    {
       i-- ;
       if ( !(*(arr_S+j) == i) ) break;
       j++;
    }
    
    return i ;
}


int main()               
{  
    int   size_arr = SIZE_ARR ;
    int   arr_Source[SIZE_ARR] = {0} ; //41, 40, 39, 38, 37, 36, 34, 33, 32, 31, 50, 49, 48, 47, 46, 45, 44, 43, 42, 30} ;  
                                     // {2, 3, 1, 4, 7, 6, 9, 8, 10, 0
    int n_Input = 1, i = 0 ;

    while ( n_Input )
    {
        scanf("%d" , &n_Input) ;
        *(arr_Source+i) = n_Input ;
        i++ ;
    }
    
    sort_array(size_arr, arr_Source); 
    printf("\n"); 
    printf("%d", finf_Excluded( size_arr, arr_Source)) ;

    return 0;
}
