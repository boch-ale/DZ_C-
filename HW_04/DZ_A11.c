
#include <stdio.h>

int main()  // Ввести пять целых чисел, вывести сумму наибольшего и наименьшего
{    

    int A = 0; int B = 0; int C = 0;	int arr_B[4];	

    scanf("%d%d%d%d%d", &A, &arr_B[0], &arr_B[1], &arr_B[2], &arr_B[3]);  // Введите пять целых чисел через пробел

    B = A; C = A;

    for(int i=0; i<4; i++) {
		
        C=(C<arr_B[i]) ? arr_B[i] : C;  // поиск наибольшего числа
        B=(B>arr_B[i]) ? arr_B[i] : B;  // поиск нименьшего числа

    }   //  for


    printf("%d\n", C+B );

    return 0;
}
