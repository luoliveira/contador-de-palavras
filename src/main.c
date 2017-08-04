/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int main() {

  char c = 0, ant = 0, ant2 = 0;
  int cont = 0;

  do {
    ant2 = ant;
    ant = c;
    scanf("%c", &c);
    /* Conta a palavra a partir do primeiro separador (espaco ou pontuacao) */
    if (c == ' ' || c == '.' || c == ',' || c == '!' || c == '-' || c == ';') {
	if (ant != ' ' && ant != '.' && ant != ',' && ant != '!' && ant != '-' && ant != ';') cont++;
    }
    /* Trata para que um float nao seja contado 2 vezes */
    if (c >= '0' && c <= '9' && (ant == '.' || ant == ',') && ant2 >= '0' && ant2 <= '9') cont--;
	    
  } while (c != '\n');

  /* Conta a ultima palavra antes do \n, caso nao tenha sido contada antes */
  if (ant >= 'A' && ant <= 'z') cont++;

  printf("%d\n", cont);
  return 0;
}
