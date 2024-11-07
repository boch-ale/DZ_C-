
#include <stdio.h>

int main()  // Ввести три целых числa, если ввод по возрастанию - вывести YES   иначе  NO
{    

    int A = 0; int B = 0; int C = 0;	

    scanf("%d%d%d", &A, &B, &C );  // Введите три цельных числа через пробел
    
    (A<B && A<C && B<C) ? printf("YES\n") : printf("NO\n");

    return 0;
}
