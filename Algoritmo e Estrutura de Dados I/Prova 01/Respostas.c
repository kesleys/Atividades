#include <stdio.h>

float* ordenar(float vetor[], int tamanho) {
    
	float temp;

	for (int i = 0; i < tamanho - 1; i++) {
		for (int j = 0; j < tamanho - i - 1; j++) {
			if (vetor[j] > vetor[j + 1]) {
				// Troca os elementos
				temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}

	return vetor;
}

int main() {

	int lotes;
	printf("Entre com o numero de lotes produzidos: ");
	scanf("%d", &lotes);

	float valorLotes[lotes][5];//forno, PC, DR, RT, gdePureza
	int forno = 0, pc = 1, dr = 2, rt = 3;

	printf("\nEntre com uma linha para cada lote produzido com os dados separados por um espaco em branco e na seguinte ordem: numero do forno, percentual de carbono (PC), dureza Rockwell (DR) e resistencia a tracao (RT)");

	for (int i = 0; i < lotes; i++) {

		printf("\nLote %d: ", i + 1);
		scanf("%f %f %f %f", &valorLotes[i][forno], &valorLotes[i][pc], &valorLotes[i][dr], &valorLotes[i][rt]);

	}

	printf("\nGrau de pureza dos lotes produzidos");
	int grauPureza[lotes];
	int testesAtendidos[3];

	for (int i = 0; i < lotes; i++) { // imprime o grau de pureza de cada lote

		if (valorLotes[i][pc] < 7.0) { // ve se atende ao teste 1
			testesAtendidos[0] = 1;
		} else {
			testesAtendidos[0] = 0;
		}

		if (valorLotes[i][dr] > 50.0) { // ve se atende ao teste 2
			testesAtendidos[1] = 1;
		} else {
			testesAtendidos[1] = 0;
		}

		if (valorLotes[i][rt] > 80000.0) { // ve se atende ao teste 3
			testesAtendidos[2] = 1;
		} else {
			testesAtendidos[2] = 0;
		}


		if (testesAtendidos[0] > 0 && testesAtendidos[1] > 0 && testesAtendidos[2] > 0) {
			grauPureza[i] = 10; // 1, 2 e 3
		}
		if (testesAtendidos[0] > 0 && testesAtendidos[1] > 0 && testesAtendidos[2] == 0) {
			grauPureza[i] = 9; // 1 e 2
		}
		if (testesAtendidos[0] > 0 && testesAtendidos[1] == 0 && testesAtendidos[2] > 0) {
			grauPureza[i] = 8; // 1 e 3
		}
		if (testesAtendidos[0] == 0 && testesAtendidos[1] > 0 && testesAtendidos[2] > 0) {
			grauPureza[i] = 7; // 2 e 3
		}
		if (testesAtendidos[0] > 0 && testesAtendidos[1] == 0 && testesAtendidos[2] == 0) {
			grauPureza[i] = 6; // somente 1
		}
		if (testesAtendidos[0] == 0 && testesAtendidos[1] > 0 && testesAtendidos[2] == 0) {
			grauPureza[i] = 5; // somente 2
		}
		if (testesAtendidos[0] == 0 && testesAtendidos[1] == 0 && testesAtendidos[2] > 0) {
			grauPureza[i] = 4; // somente 3
		}
		if (testesAtendidos[0] == 0 && testesAtendidos[1] == 0 && testesAtendidos[2] == 0) {
			grauPureza[i] = 0; // nenhum
		}


		printf("\nLote %d: %d", i + 1, grauPureza[i]);
		valorLotes[i][4] = grauPureza[i];
	}

	printf("\nEstatisticas");

	for (int i = 0; i < 5; i++) {

		int contador = 0; // para contar quantos lotes no forno
		float somatorio = 0; // para somar os graus de pureza

		for (int j = 0; j < lotes; j++) {
			if (valorLotes[j][0] == i + 1) {
				contador++;
				somatorio = somatorio + grauPureza[j];
			}
		}

		if (contador != 0) {
			printf("\nForno %d: %d lote(s) com grau medio de pureza de %.1f", i + 1, contador, somatorio/contador);
		} else {
			printf("\nForno %d: 0 lote(s)", i + 1);
		}
	}

	int maiorpureza = 0;
	int menorpureza = 10;

	for (int i = 0; i < lotes; i++) {

		if (grauPureza[i] > maiorpureza) {
			maiorpureza = grauPureza[i];
		}
	}

	for(int i = 0; i < lotes; i++) {
		if (grauPureza[i] < menorpureza) {
			menorpureza = grauPureza[i];
		}
	}

	float fornosMais[lotes];
	float fornosMenos[lotes];
	float vetor1[lotes];
	float vetor2[lotes];

	printf("\nFornos que produziram lote(s) com maior grau de pureza (grau %d):", maiorpureza);

	int tamanhoMais = 0;

	for (int km = 0; km < lotes; km++) {

		int verificador = 0;

		if (valorLotes[km][4] == maiorpureza) {

			if (km > 0) {
				for(int i =0; i < lotes; i++) {
					if (valorLotes[km][forno] == fornosMais[i]) {
						verificador++;
					}
				}
			}

			if (verificador == 0) {
				fornosMais[km] = valorLotes[km][0];
				vetor1[tamanhoMais] = valorLotes[km][0];
				tamanhoMais++;
			}
		}
	}

	ordenar(vetor1, tamanhoMais);

	for(int i =0; i < tamanhoMais; i++) {
		printf(" %.0f", vetor1[i]);
	}

	printf("\nFornos que produziram lote(s) com menor grau de pureza (grau %d):", menorpureza);

	int tamanhoMenos = 0;

	for (int km = 0; km < lotes; km++) {

		int verificador = 0;

		if (valorLotes[km][4] == menorpureza) {

			if (km > 0) {
				for(int i =0; i < km; i++) {
					if (valorLotes[km][forno] == fornosMenos[i]) {
						verificador++;
					}
				}
			}
			if (verificador == 0) {
				fornosMenos[km] = valorLotes[km][0];
				vetor2[tamanhoMenos] = valorLotes[km][0];
				tamanhoMenos++;
			}
		}
	}

	ordenar(vetor2, tamanhoMenos);

	for(int i =0; i < tamanhoMenos; i++) {
		printf(" %.0f", vetor2[i]);
	}
}