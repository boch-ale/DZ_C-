#include <stdint.h>      //  Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N
#include <stdio.h>       //  
#include <inttypes.h>    //  

uint64_t n_Size_arr(int64_t n)      //    определение размерности исп. массива
{  
    uint64_t i = 0, j = 1 ;
    while ((n / j) > 0 )
    {
        j *= 10 ;
        i++ ;
    }  
    return i ;
}

void i_to_j_in_arr(int64_t   *arr_S, uint64_t i, uint64_t j)  // перемена местами двух элементов массива
{
    arr_S[j] = arr_S[j] ^ arr_S[i] ;
    arr_S[i] = arr_S[j] ^ arr_S[i] ;
    arr_S[j] = arr_S[j] ^ arr_S[i] ;
}

void arr_Sborka(uint64_t size_arr, int64_t n_Input)
{  
    int64_t  arr_S[size_arr];
    uint64_t i = 0, j = 1 ;

    i = size_arr - 1 ; 
    while ((n_Input / j) > 0 )                      //  сборка массива из отдельных чисел
    {
        *(arr_S + i) = (n_Input / j) % 10 ;
        j *= 10 ;
        i-- ;
    }

    for ( i = 0; i < size_arr-1; i++)              //  перестановка цифр массива по убыванию
        for ( j = i+1; j < size_arr; j++)
            if( *(arr_S +i) < *(arr_S+j) )
                i_to_j_in_arr(arr_S, i, j);

    for ( i = 0 ; i < size_arr; i++)          
        printf("%d", *(arr_S + i) );              //  печать готового массива
}

int64_t main()               
{    
    uint64_t  j = 1, i = 0, size_arr ;
    int64_t n_Input = 1;

    scanf("%" SCNd64 , &n_Input);

    size_arr = n_Size_arr(n_Input);

    arr_Sborka(size_arr, n_Input);    

    return 0;
}
