/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>

#define TAM_BUFFER 60 //aumentei , ficou pequeno para o test 2
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];
char senha[]="SENHASECRETA";

char decifrar(char entrada, char senha) {
  char saida, a, b;
   if (entrada>='A' && entrada<='Z') {
    a = entrada - 'A';
    b = senha - 'A';
    saida = 'A'+( a - b + 26)% 26;
	return saida;
   } else return entrada;
}
int main() {
  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);
  int i_senha=0;
	for (int i=0;(i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n');i++){
		buffer_saida[i]=decifrar(buffer_entrada[i], senha[i_senha]);
		i_senha++;
		if (senha[i_senha]=='\0') i_senha=0;
	}


  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}
