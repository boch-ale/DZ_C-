//   До

#include <stdio.h>

int main()  // Ввести пять целых чисел, вывести наибольшее
{    

	int A = 0;	int arr_B[4];	

    scanf("%d%d%d%d%d", &A, &arr_B[0], &arr_B[1], &arr_B[2], &arr_B[3]);  //  Введите пять целых чисел через пробел

    for(int i=0; i<4; i++) {
        A=(A<arr_B[i]) ? arr_B[i] : A;
       //if (A<arr_B[i]) { A = arr_B[i]; } 
    }  // for


    printf("%d\n", A );

	return 0;
}
