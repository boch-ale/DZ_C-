// Написать только одну функцию, которая сортирует массив по возрастанию. Необходимо реализовать только одну функцию, 
// всю программу составлять не надо. Строго согласно прототипу. Имя функции и все аргументы должны быть: void sort_array(int size, int a[]).
// Всю программу загружать не надо, только одну эту функцию. Можно просто закомментировать текст всей программы, кроме данной функции.

#include <stdint.h>      // Написать только одну функцию, которая сортирует массив по возрастанию.
#include <stdio.h>       //  
#include <inttypes.h>    //
#include <string.h>

# define SIZE_ARR 20

void print_Int_array(int size_arr, int *arr_S)
{  
    uint64_t i = 0 ;

    for ( i = 0 ; i < size_arr; i++)          
        printf("%d ", *(arr_S + i) );              //  печать готового массива
}

void i_to_j_in_arr(int *arr_S, uint64_t i, uint64_t j)  // перемена местами двух элементов массива
{
    *(arr_S+j) = *(arr_S+j) ^ *(arr_S+i) ;
    *(arr_S+i) = *(arr_S+j) ^ *(arr_S+i) ;
    *(arr_S+j) = *(arr_S+j) ^ *(arr_S+i) ;
}

void sort_array(int size_arr, int *arr_S)       //  перестановка цифр массива по возрастанию
{
    uint64_t i, j;

    for ( i = 0; i < size_arr-1; i++)             
        for ( j = i+1; j < size_arr; j++)
            if( *(arr_S +i) > *(arr_S+j) )
                i_to_j_in_arr(arr_S, i, j);
}


/*
int64_t main()               
{    
    int   size_arr = SIZE_ARR ;
    int   arr_Source[SIZE_ARR] =  { 20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5 };       

    sort_array(size_arr, arr_Source);  
    print_Int_array(size_arr, arr_Source) ;  

    return 0;
}
*/