#include<stdio.h>
#include<stdlib.h>

main()
{
      float base1, base2, altura, at;
      printf("Digite a base menor \n");
      scanf("%f",&base1);
      printf("Digite a base maior \n");
      scanf("%f",&base2);
      printf("Digite a altura \n");
      scanf("%f",&altura);
      
      at=((base1+base2)*altura)/2;
      printf("A area e %f \n",at);
      
      system("pause");
      }
