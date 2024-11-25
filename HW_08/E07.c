#include <stdint.h>      //  ввести 10 элементов массива и выполнить инверсию отдельно для 1-ой и 2-ой половин массива.
#include <inttypes.h>    //    Необходимо изменить считанный массив и напечатать его одним циклом
#include <stdio.h>

# define SIZE_ARR 10

int main() 
{                                                                         
    int64_t   arr_S[SIZE_ARR] = {0}, arr_razmer05 = SIZE_ARR / 2;          uint64_t  i_k = 0 ;

    for(uint64_t i=0; i<SIZE_ARR; i++)  
        scanf(" %" SCNd64 , &arr_S[i] );   //  ввод массива с клавиатуры

    i_k = arr_razmer05 ;
    
    for(uint64_t i=0; i<arr_razmer05; i++)  // инверсия первой половины массива
    {  
        i_k--;
        if (i == i_k)
        {
            break;
        }
        else
        {
            arr_S[i] = arr_S[i] ^ arr_S[i_k];
            arr_S[i_k] = arr_S[i] ^ arr_S[i_k];
            arr_S[i] = arr_S[i] ^ arr_S[i_k];
        }
    }  // for

    i_k = SIZE_ARR ;
    for(uint64_t i=arr_razmer05; i<SIZE_ARR; i++)  // инверсия 2 половины массива
    {  
        i_k--;
        if (i == i_k)
        {
            break;
        }
        else
        {
            arr_S[i] = arr_S[i] ^ arr_S[i_k];
            arr_S[i_k] = arr_S[i] ^ arr_S[i_k];
            arr_S[i] = arr_S[i] ^ arr_S[i_k];
        }
    }  // for

    for (uint64_t i = 0; i < SIZE_ARR; i++)
        printf(" %d", arr_S[i] ) ;
    
    return 0;
}
