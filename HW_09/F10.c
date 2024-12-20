#include <stdint.h>   //  Дана строка состоящая из маленьких латинских букв 'a'..'z'. В конце строки точка.
#include <stdio.h>    // Необходимо заменить повторяющиеся буквы на <буква><количество повторений>
#include <inttypes.h> // aaaabbbbc
#include <string.h>   // a4b4c1

int64_t main()
{
    char sim = ' ', sim_previce = ' ';
    uint64_t i = 1;

    while (!(sim_previce >= 'a' && sim_previce <= 'z'))
        sim_previce = getchar(); //  printf("%c\n", sim_previce);

    do
    {
        sim = getchar();
        if ((sim >= 'a' && sim <= 'z') && (sim == sim_previce))
        {
            i++;
        }
        else
        {
            if (sim_previce >= 'a' && sim_previce <= 'z')
            {
                putchar(sim_previce);
                printf("%d", i);
                i = 1;
                sim_previce = sim;
            }
        }

    } while (!(sim == '.'));

    return 0;
}
