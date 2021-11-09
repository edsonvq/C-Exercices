#include<stdio.h>
#include<stdlib.h>

main()
{
      float numeroa, numerob, numeroc,media;
      printf("Digite o primeiro numero \n");
      scanf("%f",&numeroa);
      printf("Digite o segundo numero \n");
      scanf("%f",&numerob);
      printf("Digite o terceiro numero \n");
      scanf("%f",&numeroc);

      
      media=(numeroa+numerob+numeroc)/3;
      printf("A media e %f \n",media);
      
      system("pause");
      }
