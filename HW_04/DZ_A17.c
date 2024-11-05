
#include <stdio.h>

int main()  // Ввести число от 1 до 12, вывести время года
{    

	int A = 0;	

    scanf("%d", &A );  // Введите номер месяца

    ((A>0 && A<3) || (A>11 && A<13)) ? printf("winter") : A;
    (A>2 && A<6) ? printf("spring") : A;
    (A>5 && A<9) ? printf("summer") : A;
    (A>8 && A<12) ? printf("autumn") : A;

   // if ((A>0 && A<3) || (A>11 && A<13)) {printf("winter");}
   // else if (A>2 && A<6) {printf("spring");}
   // else if (A>5 && A<9) {printf("summer");}
   // else if (A>8 && A<12) {printf("autumn");}

	return 0;
}
