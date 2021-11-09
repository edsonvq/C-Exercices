#include <stdio.h>

#include <stdlib.h>



char *infixaParaPosfixa (char inf[]);



int main2(void){
    char inf[] = "(a+b-(c*a))";
	//char inf[] = "(9+2*4)";

	char *p = infixaParaPosfixa(inf);

	printf("%s\n", p);

	return 0;
}



char *infixaParaPosfixa (char inf[]) {

	char *posf;
	char *pi; int t; // pilha
	int n, i, j;

	n = strlen (inf);

	posf = malloc (n * sizeof (char));
	pi = malloc (n * sizeof (char));

	t = 0;

	pi[t++] = inf[0]; // empilha '('

	for (j = 0, i = 1; inf[i] != '\0'; ++i) {

		// a pilha está armazenada em pi[0..t-1]

		switch (inf[i]) {
			char x;

            case '(':
                pi[t++] = inf[i]; // empilha
                break;

            case ')':

                while ((x = pi[--t]) != '(') // desempilha
                    posf[j++] = x;
                break;
			case '+':

			case '-':
				while ((x = pi[t-1]) != '(') {
					posf[j++] = x;
					--t; // desempilha
				}
				pi[t++] = inf[i]; // empilha
				break;

			case '*':

			case '/':
				while ((x = pi[t-1]) != '(' && x != '+' && x != '-') {

					  posf[j++] = x;

					  --t;

				}
				pi[t++] = inf[i];
				break;
			default:
				posf[j++] = inf[i];
		}
	}

	free (pi);

	posf[j] = '\0';
	return posf;

}
