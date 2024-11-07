
#include <stdio.h>

int main()  // Ввести два целых числа, вывести в порядке возрастания
{  
    int A = 0;	int B = 0;	// int C = 0; 
	
    scanf("%d%d", &A, &B );  // Введите через пробел последовательно два числа
	
    //  (A>B) ? printf("%d %d\n", B, A ): printf("%d %d\n", A, B );

    if (A>B)  { A=A^B; B=A^B; A=A^B; };
		
    printf("%d %d\n", A, B );
	
    return 0;
}
