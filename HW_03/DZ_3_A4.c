//   Домашнее задание №2 к лекции 3 Типы данных С 

#include <stdio.h>

int main()  // Ввести с клавиатуры три целых числа, затем распечатать сумму и произведение их значений в формате 10+20+30=60 и 10*20*30=6000
{
    int A = 0;	int B = 0;	int C = 0; 

    scanf("%d%d%d", &A, &B, &C);   // Введите через пробел последовательно три числа
		
    printf("%d+%d+%d=%d\n", A, B, C, A+B+C );
    printf("%d*%d*%d=%d\n", A, B, C, A*B*C );

    return 0;
}