#include <stdint.h>      //  Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1
#include <inttypes.h>    //    Необходимо изменить считанный массив и напечатать его одним циклом
#include <stdio.h>

# define  SIZE_ARR 10

int main() 
{                                                                         
    int64_t   arr_S[SIZE_ARR] = {0} ;        // {4,-5,3,10,-4,-6,8,-10,1,0,5,7};
    uint64_t     i_k = 0, a = 0 ;     

    for(uint64_t i=0; i<SIZE_ARR; i++)  
        scanf(" %" SCNd64 , &arr_S[i] );   //  ввод массива с клавиатуры
    
    a = SIZE_ARR - 1 ;
    
    for(uint64_t i = a; i>=1; i--)  // замена чисел справа налево
    {  
        i_k = i - 1 ;
       
        arr_S[i] = arr_S[i] ^ arr_S[i_k];
        arr_S[i_k] = arr_S[i] ^ arr_S[i_k];
        arr_S[i] = arr_S[i] ^ arr_S[i_k];
        
    }  // for i

    for (uint64_t i = 0; i < SIZE_ARR; i++)
        printf(" %d", arr_S[i] ) ;
    
    return 0;
}
