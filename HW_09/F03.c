#include <stdint.h>   // Написать функцию и программу демонстрирующую работу данной функции. Вывести в порядке возрастания цифры,
#include <stdio.h>    // входящие в десятичную запись натурального числа N, не более 1000 цифр. Цифра пробел сколько раз данная цифра
#include <inttypes.h> // встречается в числе.         Счётчик одинаковых цифр
#include <string.h>

#define INT_SIZE_ARR 10
#define CHAR_SIZE_ARR 999

//--------------------------------------------------------------------------
int64_t char_to_Digit(char sml) // Функция переводит символьное значение цифры от 0 до9 в числовое
{
    int64_t rez = (sml >= '0' && sml <= '9') ? (sml - '0') : -1;
    return rez;
}
//--------------------------------------------------------------------------
void print_Int_array(uint64_t size_arr, int64_t *arr_S)
{
    uint64_t i;

    for (i = 0; i < size_arr; i++)
        if (!(*(arr_S + i) == 0))
            printf("%d %d\n", i, *(arr_S + i)); //  печать готового массива
    // printf("\n");
}
//--------------------------------------------------------------------------
void num_Double(uint64_t int_size_arr, int64_t *arr_S, int64_t char_size_arr, char *arr_char)
{
    uint64_t i = 0;

    while (!(*(arr_char + i) == 'f') && (i < char_size_arr))
    {
        *(arr_S + char_to_Digit(*(arr_char + i))) += 1;
        i++;
    }
}
//--------------------------------------------------------------------------

void init_arr_Char(uint64_t char_size_arr, char *arr_Char) // инициализация массива символов
{
    for (uint64_t i = 0; i < char_size_arr; i++)
    {
        *(arr_Char + i) = 'f';
    }
}
//--------------------------------------------------------------------------

int64_t main()
{
    uint64_t int_size_arr = INT_SIZE_ARR;
    uint64_t char_size_arr = CHAR_SIZE_ARR;
    int64_t r;

    int64_t arr_S[INT_SIZE_ARR] = {0}; //  элементы массива соответствуют цифрам от 0 до 9 и содержат значения счётчиков каждого числа
    char arr_Char[CHAR_SIZE_ARR];      // uint64_t  n_Input = 10000000000000000000000001;

    init_arr_Char(char_size_arr, arr_Char);

    r = scanf("%[0-9]", arr_Char);

    num_Double(int_size_arr, arr_S, char_size_arr, arr_Char);
    print_Int_array(int_size_arr, arr_S);

    return 0;
}
