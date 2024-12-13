#include <stdint.h>      // Написать только одну функцию, которая ставит в начало массива все четные элементы, а в конец – все нечетные. 
#include <stdio.h>       // Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:.  
#include <inttypes.h>    // void sort_even_odd(int n, int a[])
#include <string.h>

# define SIZE_ARR 5  //20

void print_Int_array(int size_arr, int *arr_S)
{  
    int i = 0 ;

    for ( i = 0 ; i < size_arr; i++)          
        printf("%d ", *(arr_S + i) );              //  печать готового массива
    printf("\n");    
}

void i_to_j_in_arr(int *arr_S, int i, int j)  // перемена местами двух элементов массива
{
    *(arr_S+j) = *(arr_S+j) ^ *(arr_S+i) ;
    *(arr_S+i) = *(arr_S+j) ^ *(arr_S+i) ;
    *(arr_S+j) = *(arr_S+j) ^ *(arr_S+i) ;
}

void sort_array(int size_arr, int *arr_S)       //  перестановка цифр массива по возрастанию
{
    int i, j;

    for ( i = 0; i < size_arr-1; i++)             
        for ( j = i+1; j < size_arr; j++)
            if( *(arr_S +i) > *(arr_S+j) )
                i_to_j_in_arr(arr_S, i, j);
}

void sort_array_degress(int size_arr, int *arr_S)       //  перестановка цифр массива по убыванию
{
    int i, j;

    for ( i = 0; i < size_arr-1; i++)             
        for ( j = i+1; j < size_arr; j++)
            if( *(arr_S +i) < *(arr_S+j) )
                i_to_j_in_arr(arr_S, i, j);
}
//----------------------------------------------------------------------
int find_Even(int size_arr, int *arr_S, int i )       //  счётчик - поиск ближайшего чётного числа
{   
    int j = i;
    while ( j < size_arr )
    {
        if( (*(arr_S+j) % 2) == 0)   break;          // if чётное число нашлось, фиксируется его положение в массиве 
        j++ ;                                        // и  вовращается для дальнейшего перемещения по массиву чётного числа
    }                                                // if j добежал до конца массива и не встретил ни одного чётного,
    return (j == size_arr) ? i : j ;                 // возвращается стартовое значение, с какого начался поиск 
}
//----------------------------------------------------------------------

void sort_even_odd(int size_arr, int *arr_S)       //  перестановка цифр массива сначала чётные, потом нечётные с сохранением субординации
{
    int i, j;                                      // пробовал сделать рекурсивно - не понравилось(костыли)  

    for ( i = 0; i < size_arr-1; i++)
    {
        if ( !(*(arr_S+i) % 2 == 0 ) )            //  если число нечётное, то начинаю искать ближайшее чётное, чтоб поменяться со сдвигом
        {
            j = find_Even(size_arr, arr_S, i);    //  счётчик - поиск ближайшего чётного числа

            while ( i<j )
            {                                                          
                i_to_j_in_arr(arr_S, j, j-1);     // чётное движется по массиву со смещением остальных элементов
                j-- ;
            }  //while
        }
    }  //  for i

}
//----------------------------------------------------------------------

/*
int64_t main()               
{    
    int   size_arr = SIZE_ARR ;       //  20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1    {1,0,1,0,1}; 
    int   arr_Source[SIZE_ARR] =  {1,0,1,0,1};  //{ 20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5 };       

    sort_even_odd(size_arr, arr_Source);  
    print_Int_array(size_arr, arr_Source) ;  

    return 0;
}
*/