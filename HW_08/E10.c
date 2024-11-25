#include <stdint.h>      //  Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.
#include <inttypes.h>    //    Необходимо изменить считанный массив и напечатать его одним циклом
#include <stdio.h>

# define SIZE_ARR 12    // размер вводимого массива
# define SDVIG_R   4    // на сколько элементов сдвиг вправо

int main() 
{                                                                         
    int64_t   arr_S[SIZE_ARR] = {0} ;       //{4,-5,3,10,-4,-6,8,-10,1,0,5,7};
    uint64_t    j = 0,  i_k = 0, a = 0 ;   

    for(uint64_t i=0; i<SIZE_ARR; i++)  
        scanf(" %" SCNd64 , &arr_S[i] );   //  ввод массива с клавиатуры
    
    for (a = 0; a < SDVIG_R; a++ )   // цикл по количеству сдвигаемых элементов
    {
        j = SIZE_ARR - 1 ;
        for(uint64_t i=j; i >= 1; i--)  // цикл сдвига поэлементно справа налево
        {  
            i_k = i - 1;
            
            arr_S[i] = arr_S[i] ^ arr_S[i_k];
            arr_S[i_k] = arr_S[i] ^ arr_S[i_k];
            arr_S[i] = arr_S[i] ^ arr_S[i_k];
            
        }  // for i

    }   //  for a
  
    for (uint64_t i = 0; i < SIZE_ARR; i++)
        printf(" %d", arr_S[i] ) ;
    
    return 0;
}
