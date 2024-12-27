#include <stdint.h>   // В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.
#include <stdio.h>    // Строка из английских букв и пробелов. Не более 100 символов. В конце могут быть незначащие переносы строк.
#include <inttypes.h> // Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней
#include <string.h>   // Входные данные в файле       input.txt    aab    Результат работы в файле output.txt  aab, aab, aab 3

#define SIZE_CHAR_ARR 100

int64_t fileOutput_str_3(int64_t size_str, char *str)
{
    uint64_t count = 3; // количество повторений строки
                        //  char *f_out = "output.txt";
    FILE *fo;

    fo = fopen("output.txt", "w");
    if (!(fo == NULL))
    {
        for (uint64_t i = 0; i < count; i++)
        {
            for (uint64_t j = 0; j < size_str; j++)
            {
                fprintf(fo, "%c", *(str + j));
            }

            if (i < (count - 1))
            {
                fprintf(fo, ", ");
            }
        }
        fprintf(fo, " %d", size_str);

        fclose(fo);
    }
    else
    {
        return 1;
    }

    return 0;
}

uint64_t str_Input(char *str)
{
    char c;
    // char f_inp = "input.txt";
    uint64_t mng_char = 0;
    FILE *fi;

    fi = fopen("input.txt", "r");
    if (!(fi == NULL))
    {
        c = fgetc(fi);
        if (!(c == EOF))
        {
            *(str + mng_char) = c;
            mng_char++;
        }

        while (1)
        {
            c = fgetc(fi);
            if (c == EOF)
            {
                break;
            }
            else
            {
                if (!(c == '\n'))
                {
                    *(str + mng_char) = c;
                    mng_char++;
                }
            }
        }
        fclose(fi);
    }
    else
        printf("Can`t open file input.txt\n");

    return mng_char;
}

int64_t main(int argc, char *argv[])
{
    char str_file_input[SIZE_CHAR_ARR];
    uint64_t size_str = str_Input(str_file_input);

    if (fileOutput_str_3(size_str, str_file_input))
        printf("Can`t write to file output.txt");

    return 0;
}
/*


*/
