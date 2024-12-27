#include <stdint.h>   // В файле input.txt дана строка <= 1000 символов в ней.
#include <stdio.h>    // Показать номера символов, совпадающих с последним символом строки. Результат записать в файл output.txt
#include <inttypes.h> // aabbcdb        строка
#include <string.h>   // 2 3            ответ
/*
#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

uint64_t my_fPos();
uint64_t str_Input();
*/

//-------------------------------------------------------------------------------------
uint64_t my_fPos() // подсчёт количества символов типa char в файле
{
    uint8_t c = ' ';
    uint64_t i = 0;
    FILE *fi;

    fi = fopen("input.txt", "r");
    if (fi == NULL)
    {
        printf("Can`t open file input.txt\n");
        return 0;
    }

    while (1)
    {
        c = fgetc(fi);

        if (c < 255)
        {
            i++;
        }
        else
        {
            break;
        }
    }

    fclose(fi);
    return i;
}

//-------------------------------------------------------------------------------------
uint64_t str_Input()
{
    uint8_t c;
    // char f_inp = "input.txt";
    uint64_t mng_char = 0, i = 0;
    uint64_t position_end_element = 0;

    FILE *fi, *fo;
    /*
        fi = fopen(FILE_INPUT, "r");
        fclose(fi);
        fo = fopen(FILE_OUTPUT, "w");
        fclose(fo);
    */
    position_end_element = my_fPos(); // количество символов типа uint8_t в файле
    if (!position_end_element)
    {
        return 1;
    }
    fo = fopen("output.txt", "w");
    if (fo == NULL)
    {
        return 2; // Can`t write to file output.txt
    }

    fi = fopen("input.txt", "r");
    if (fi == NULL)
    {
        return 1; //  Can`t open file input.txt
    }

    fseek(fi, -1, SEEK_END); // установка позиции указателя на последнее значение в файле input.txt

    // fgetpos(fi, &position_end_element); // индекс последнего значения в файле
    c = fgetc(fi);          // запоминается последнее значение
    fseek(fi, 0, SEEK_SET); // установка позиции указателя на начало файла input.txt

    for (i = 0; i < (position_end_element - 1); i++)
    {
        if (c == fgetc(fi))
        {
            fprintf(fo, "%d ", i);
        }
    }

    fclose(fi);
    fclose(fo);
    return 0;
}

int main(int argc, char *argv[])
{
    uint64_t file_story = str_Input();

    if (file_story == 2)
        printf("Can`t write to file output.txt");
    if (file_story == 1)
        printf("Can`t open file input.txt\n");

    return 0;
}

/*


*/
