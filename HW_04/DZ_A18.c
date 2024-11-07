
#include <stdio.h>

int main()  // Ввести два целых числa, сравнить. Если первое больше второго вывести - Above, меньше - Less, равно - Equal
{    
    int A = 0; int B = 0;	

    scanf("%d%d", &A, &B);  // Введите два цельных числа через пробел
        
    if (A<B) { printf("Less\n");  } 
    else { (A>B) ? printf("Above\n") : printf("Equal\n"); }

    return 0;
}
