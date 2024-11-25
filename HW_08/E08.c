#include <stdint.h>      //  Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.
#include <inttypes.h>    //    Необходимо изменить считанный массив и напечатать его одним циклом
#include <stdio.h>

# define SIZE_ARR 12

int main() 
{                                                                         
    int64_t   arr_S[SIZE_ARR] = {0} ;               //{4,-5,3,10,-4,-6,8,-10,1,0,5,7};
    uint64_t    arr_razmer3 = SIZE_ARR / 3,  i_k = 0, a = 0 ;        int64_t i_prov = 0 ;

    for(uint64_t i=0; i<SIZE_ARR; i++)  
        scanf(" %" SCNd64 , &arr_S[i] );   //  ввод массива с клавиатуры
    
    for (a = 0; a < SIZE_ARR; a += arr_razmer3)   // цикл по каждой трети массива
    {
        i_k = arr_razmer3 + a;
    
        for(uint64_t i=a; i<(a + arr_razmer3); i++)  // инверсия очередной трети массива
        {  
            i_k--;
            i_prov = i_k - i ;
            if ( i_prov < 0 )
            {
                break;
            }
            else
            {
                arr_S[i] = arr_S[i] ^ arr_S[i_k];
                arr_S[i_k] = arr_S[i] ^ arr_S[i_k];
                arr_S[i] = arr_S[i] ^ arr_S[i_k];
            }
        }  // for i

    }   //  for a
  
    for (uint64_t i = 0; i < SIZE_ARR; i++)
        printf(" %d", arr_S[i] ) ;
    
    return 0;
}
