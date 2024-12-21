#include <stdint.h>   // шахматная доска. Определить по букве и цифре цвет клетки
#include <stdio.h>    //
#include <inttypes.h> //
#include <string.h>   //

//---------------------------------------------------------------------------------------
int my_Even(int num) // проверка на чётность
{
    return num % 2;
}

//--------------------------------------------------------------------------------
int main()
{
    char c;
    int kl1 = 0; // 0 - соотствует белому цвету первой клетки, 1- черному цвету первой клетки
    int cifr = 0;
    int s_inp = 2;
    int rez = 0;

    for (int i = 0; i < s_inp; i++)
    {
        c = getchar();
        if (c == 'a' || c == 'A' || c == 'c' || c == 'C' || c == 'e' || c == 'E' || c == 'g' || c == 'G')
            kl1 = 1;
    }
    cifr = (c >= '0' && c <= '9') ? (c - '0') : 0;

    if ((kl1 && my_Even(cifr)) || (kl1 == 0 && my_Even(cifr) == 0))
        printf("BLACK");
    else
        printf("WHITE");

    return 0;
}
