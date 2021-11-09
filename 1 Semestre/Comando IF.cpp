#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int num;
	printf ("Digite um numero: ");
	scanf ("%d",&num);
	if (num>=100)
      	{
      		printf ("\n\nVoce acertou!\n");
      		printf ("O numero e maior ou igual a 100.\n");
      	}
	else 
      	{
      		printf ("\n\nVoce errou!\n");
      		printf ("O numero e menor que 100.\n");
      	}
   	system("pause");   	
	return(0);


}
