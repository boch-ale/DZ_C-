#include <stdint.h>   // Написать только одну функцию, которая находит максимальный элемент в массиве. Всю программу загружать не надо.
#include <stdio.h>    //  Прототип функции: int find_max_array(int size, int a[])
#include <inttypes.h> //
#include <string.h>

//--------------------------------------------------------------------------
int find_max_array(int size, int *arr_s) // функция заданная условием задачи
{
    int n_max = *arr_s;

    for (int i = 1; i < size; i++)
        n_max = (n_max < *(arr_s + i)) ? (*(arr_s + i)) : n_max;

    // printf("%d", n_max);
    return n_max;
}
//--------------------------------------------------------------------------
/*
int64_t main()
{
    int arr_S[100]={773, 307, 371, 548, 531, 765, 402,  27, 573, 591, 217, 859, 662, 493, 173, 174, 125, 591, 324, 231, 130, 394, 573,   2, 190,
                     65, 570, 258, 343,   3, 586,  14, 785, 296, 140, 726, 598, 262, 807, 794, 510, 465,  66, 895, 182, 218, 302,  34, 205, 399,
                    252, 687, 660, 952, 737,  32, 310, 680,  36, 139, 346, 139, 489, 217, 767, 544, 158, 774, 883, 154, 802, 136, 842, 769,   3,
                    569, 377, 867, 423, 224, 176, 118, 660, 513, 734,  45, 978, 983, 749, 909, 601, 270, 147, 433, 737, 789, 304, 815, 503,  111};
    int size_arr = 100 ;

    find_max_array(size_arr, arr_S);

    return 0;
}
*/