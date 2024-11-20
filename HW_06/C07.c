#include <stdint.h>      //  Перевести число N из десятичной системы счисления в P-ичную  
#include <inttypes.h>    //  N>=0     2>= P >=9
#include <stdio.h>       //  

uint64_t My_Div(uint64_t n, uint64_t p)
{
    uint64_t rez_div = 1, ostatok = n, j = 1, i = 1, n_rzd;

    for ( n_rzd = 1; ostatok >= p; n_rzd++)  // число разрядов в получаемом числе
                                     ostatok = ostatok/p;
    uint64_t arr_Rez[n_rzd];  // ячейки массива будут содержать остатки от деления. Останется только вытащить содержимое и превратить в единое число
    i = n_rzd - 1;

    while ( n >= p )      // сборка остатков от деления в массив
    {
        ostatok = n % p ;
        n = n/p ; 

        arr_Rez[i] = ostatok;
        i--;
    }
    arr_Rez[0] = n;
    ostatok = 0;

   for ( i = 0; i < n_rzd; i++)           //  сборка результата с учётом разрядности получаемого числа
   {
       for ( j = i+1; j < n_rzd; j++)
       {
            rez_div *= 10;
       }
       ostatok += arr_Rez[i] * rez_div;
       rez_div = 1;
   }
   
   return ostatok;
}


int main() 
{                                                                         
    uint64_t num_N, num_P, dgr;

    scanf("%" SCNu64 " %" SCNu64, &num_N, &num_P);

    dgr = My_Div(num_N, num_P ) ;

    printf("%" PRIu64 , dgr );
    
    return 0;
}
