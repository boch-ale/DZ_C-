
#include <stdio.h>

int main()  // Таблица истинности для упрощённого выражения
{
    int A = 0;	int B = 0;	int C = 0; 
    int arr_A[8] = {0,0,0,0,1,1,1,1}; 
    int arr_B[8] = {0,0,1,1,0,0,1,1};
    int arr_C[8] = {0,1,0,1,0,1,0,1};

    for (int i=0; i<8; i++) {
	    
        A = arr_A[i]; B = arr_B[i]; C = arr_C[i];
		
        printf("%d%d%d%d%d\n", A, B, C,  (!B||A) && (!(A||B)) && (!A||C),  !B&&!A  );

    } //for
    return 0;
}