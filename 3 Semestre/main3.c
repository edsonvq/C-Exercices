char * infixaParaPosfixa(char * inf) {

  char * posf; /* expressao polonesa */
  int n = strlen(inf);
  int i; /* percorre infixa */
  int j; /* percorre posfixa */
  char * s; /* pilha */
  int t; /* topo da pilha */

  /*aloca area para expressao polonesa*/
  posf = mallocSafe((n + 1) * sizeof(char));
  /* O '+1'eh para o '\0'*/

  /* stackInit(n): inicializa a pilha */
  s = mallocSafe(n * sizeof(char));
  t = 0;


  /* examina cada item da infixa */
  for (i = j = 0; i < n; i++) {
    switch (inf[i]) {
		char x; /* item do topo da pilha */

		case '(':
		  /* stackPush(inf[i]) */
		  s[t++] = inf[i];
		  break;

		case ')':
		  /* x = stackPop() */
		  while ((x = s[--t]) != '(')
			posf[j++] = x;
		  break;
		case '+':
		case '-':
		  /* !stackEmpty()
		  && (stackTop()) != '('
		  */
		  while (t != 0 &&
			(x = s[t - 1]) != '(')
			posf[j++] = s[--t];
		  /* stackPush(inf[i]) */
		  s[t++] = inf[i];
		  break;

		case '*':
		case '/':
		  /* !stackEmpty() &&
		  prec(stackTop()) >= prec(inf[i])
		  */
		  while (t != 0 &&
			(x = s[t - 1]) != '(' &&
			x != '+' && x != '-')
			posf[j++] = s[--t];
		  /* stackPush(inf[i]) */
		  s[t++] = inf[i];
		  break;

		default:
		  if (inf[i] != ' ')
			posf[j++] = inf[i];
    } /* fim switch */
  } /* fim for (i=j=0...) */


  /* desempilha todos os operandos que
  restaram */
  /* !stackEmpty() */

  while (t != 0)
    posf[j++] = s[--t]; /* stackPop() */
  posf[j] = '\0'; /* fim expr polonesa */

  /* stackFree() */
  free(s);
  return posf;

} /* fim funcao */

int main()
{
     char inf[] = "((5+3)*2/(4-6))";
	//char inf[] = "(9+2*4)";

	char *p = infixaParaPosfixa(inf);

	printf("%s\n", p);
    return 0;
}
