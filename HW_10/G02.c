#include <stdint.h>   // Считать число N из файла input.txt. Сформировать строку из N символов. N четное число, не превосходящее 26.
#include <stdio.h>    //  На четных позициях должны находится четные цифры в порядке возрастания, кроме 0,
#include <inttypes.h> //  на нечетных позициях - заглавные буквы в порядке следования в английском алфавите.
#include <string.h>   //  Результат записать в файл output.txt   10-->A2B4C6D8E2   16-->A2B4C6D8E2F4G6H8

uint64_t create_Str(FILE *fo, uint64_t size_str)
{
    uint64_t i = 0, j = 0, a = 0;
    uint8_t c = ' ';

    for (i = 1; i <= size_str; i += 2)
    {
        c = 'A' + a++;
        fprintf(fo, "%c", c);

        if (!(size_str == 1))
        {
            if (j == 8)
            {
                j = 2;
            }
            else
            {
                j += 2;
            }
            fprintf(fo, "%d", j);
        }
    }

    return 0;
}

uint64_t my_fileOutput(uint64_t size_str)
{
    FILE *fo; //  char *f_out = "output.txt";

    fo = fopen("output.txt", "w");
    if (!(fo == NULL))
    {
        create_Str(fo, size_str);
        fclose(fo);
    }
    else
    {
        return 1;
    }
    return 0;
}

uint64_t str_Input(void)
{
    uint64_t length_str = 0;
    FILE *fi;

    fi = fopen("input.txt", "r");
    if (!(fi == NULL))
    {
        fscanf(fi, "%d", &length_str);

        fclose(fi);
        return length_str;
    }
    else
        printf("Can`t open file input.txt\n");

    return 0;
}

int64_t main(int argc, char *argv[])
{
    uint64_t size_str = str_Input();

    if ((!size_str) || (size_str > 26))
        return 0;

    if (my_fileOutput(size_str))
        printf("Can`t write to file output.txt");

    return 0;
}
/*


*/
