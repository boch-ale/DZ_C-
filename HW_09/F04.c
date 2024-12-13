#include <stdint.h>      // Написать только одну функцию. Всю программу отправлять не надо. Вывести в порядке возрастания цифры, входящие в строку.
#include <stdio.h>       // Цифра - количество. Функция должно строго соответствовать прототипу:   
#include <inttypes.h>    // void print_digit(char s[])
#include <string.h>

# define INT_SIZE_ARR 10

//--------------------------------------------------------------------------
int64_t char_to_Digit(char sml)    // Функция переводит символьное значение цифры от 0 до9 в числовое
{
    int64_t rez = (sml >= '0' && sml <= '9') ? (sml-'0') :  -1 ;
    return   rez ;
}
//--------------------------------------------------------------------------
void print_Int_array(uint64_t size_arr, int64_t *arr_S)
{  
    uint64_t  i ;

    for ( i = 0 ; i < size_arr; i++) 
        if( !(*(arr_S + i) == 0) )          
            printf("%d %d\n", i, *(arr_S + i) );              //  печать готового массива
    //printf("\n");    
}
//--------------------------------------------------------------------------
void num_Double(uint64_t int_size_arr, int64_t *arr_S, uint64_t char_size_arr, char *arr_char)
{
    uint64_t i = 0, chsa = char_size_arr;  //printf("vxod num_Double =  %s\n", arr_char);
    int64_t j ;
    while ( i < chsa )
    {
        j = char_to_Digit(*(arr_char+i)) ;      
        if (j >= 0 )
            *(arr_S + j ) += 1 ;  

        //printf("%c i = %d  j = %d size = %d\n", *(arr_char + i), i, j, chsa ); 
        i++ ;
    }
}
//--------------------------------------------------------------------------
uint64_t str_Len(char *arr_Char)    //длина передаваемого массива символов
{
    uint64_t len=0;
    while (*arr_Char++) len++;
    return len ;
}
//--------------------------------------------------------------------------
void print_digit(char *arr_Char)    // функция заданная условием задачи
{
    uint64_t   int_size_arr = INT_SIZE_ARR ;
    int64_t   arr_S[INT_SIZE_ARR] = {0};         //  элементы массива соответствуют цифрам от 0 до 9 и содержат значения счётчиков каждого числа
    uint64_t   char_size_arr = 0; 

    char_size_arr = str_Len(arr_Char);        

    num_Double(int_size_arr, arr_S, char_size_arr, arr_Char);  
    print_Int_array(int_size_arr, arr_S) ;  

}
//--------------------------------------------------------------------------
/*
int64_t main()               
{    
          
//    int64_t    r ;     

    char arr_Char[CHAR_SIZE_ARR] ;                                             //uint64_t  n_Input = 10000000000000000000000001;
    
    init_arr_Char(char_size_arr, arr_Char);

    r = scanf("%s", arr_Char);

    print_digit("Y65 Hel6lo123 W8456rd16 616180");
    
    //num_Double(int_size_arr, arr_S, char_size_arr, arr_Char);  
    //print_Int_array(int_size_arr, arr_S) ;  

    return 0;
}
*/ 