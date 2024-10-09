/* COMANDO

Escreva um programa, em C, que receba um número natural n na notação decimal e e o converta para sua notação binária. O programa deve utilizar uma “função recursiva” para realizar a conversão. O código produzido será inspecionado pelo professor e se ele constatar que o programa não usou  função recursiva para a solução do problema, então a nota atribuída será zero independentemente dos resultados da conversão estarem corretos ou não.

*/

#include <stdio.h>

int convertBin(int numero) {

	int resto = numero%2;
	int numDividido2 = numero/2;

	if (numero <= 1) {

		printf("%d", numero);

	} else {
		convertBin(numDividido2);
		printf("%d", resto);
	}
}

int main() {

	int numeroN;

	printf("Entre com o numero natural n no formato decimal: ");
	scanf("%d", &numeroN);

	printf("\n\nRepresentacao do numero decimal %d no formato binario: ", numeroN);
	convertBin(numeroN);

}