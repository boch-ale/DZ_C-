
#include <stdio.h>

int main()  // Ввести пять целых чисел, вывести сумму наибольшего и наименьшего
{    

	int A = 0; int B = 0;	int arr_B[4];	

    scanf("%d%d%d%d%d", &A, &arr_B[0], &arr_B[1], &arr_B[2], &arr_B[3]);  // Введите пять целых чисел через пробел

    B = A;
    
    for(int i=0; i<4; i++) {
		
        A=(A<arr_B[i]) ? arr_B[i] : A;
        B=(B>arr_B[i]) ? arr_B[i] : B;
       // if (A<arr_B[i]) { A = arr_B[i]; } // поиск наибольшего числа
       // if (B>arr_B[i]) { B = arr_B[i]; } // поиск нименьшего числа
    }


    printf("%d\n", A+B );

	return 0;
}
