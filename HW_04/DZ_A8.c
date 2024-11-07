
#include <stdio.h>

int main()  // Ввести три целых числа, вывести наибольшее
{    
    int A = 0;	int B = 0;	 int C = 0; 
	
// Введите через пробел последовательно три числа
    scanf("%d%d%d", &A, &B, &C );
	
    A=(A<B) ? B : A;
    A=(A<C) ? C : A;

    printf("%d\n", A );

    return 0;
}
