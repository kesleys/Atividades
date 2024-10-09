#include <stdio.h>

float matriz[10][31];
float totaldia[31];
int vetorVdia[31];

int main() {

	int mes, qVendedores, diasMes;
	int notasfiscais[100];
	int posicao = 0;

	do {    // Recebe o mes

		printf("Entre com o mes em que as vendas foram realizadas: ");
		scanf("%d", &mes);

		if(mes < 1 || mes > 12) {
			printf("\nMes deve ser maior ou igual a 1 e menor ou igual a 12\n");
		}

	} while(mes < 1 || mes > 12);

	switch(mes) {

	case 4:
	case 6:
	case 9:
	case 11:
		diasMes = 30;
		break;

	case 2:
		diasMes = 28;
		break;

	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		diasMes = 31;
		break;

	}



	do {    // Recebe o a quantidade de vendedores

		printf("\nEntre com o numero de vendedores que trabalharam no mes: ");
		scanf("%d", &qVendedores);

		if(qVendedores < 1) {
			printf("\nNumero de vendedores deve ser maior do que zero\n");
		}

	} while(qVendedores < 1);

	printf("\nEntre com as vendas. Para cada venda realizada no mes informar o numero da nota fiscal que a identifica, o codigo do vendedor responsavel, o dia do mes em que foi feita e o valor da venda em reais. Quando desejar finalizar a entrada de dados digite o numero zero para a nota fiscal.");

	int notafiscal, vendedor, dia, looping = 0;
	float valorvenda;
	int quantVendas = 0;

	while(looping == 0) {

		int verificador = 0;
		int contador = 0;


		printf("\nVenda: ");
		scanf("%d",  &notafiscal);
		if(notafiscal == 0) {
			break;
		}
		for(int i = 0; i < posicao + 1; i++) {

			if (notasfiscais[i] == notafiscal) {
				verificador++;
			}
		}


		scanf("%d %d %f", &vendedor, &dia, &valorvenda);

		if (verificador > 0) {
			printf("\nNota fiscal repetida");
		}
		if (vendedor < 1 || vendedor > qVendedores || vendedor > 10) {
			printf("\nCodigo do vendedor invalido");
			contador++;
		}
		if (dia < 1 || dia > diasMes) {
			printf("\nDia da venda invalido");
			contador++;
		}
		if (valorvenda <= 0) {
			printf("\nValor da venda invalida");
			contador++;
		}
		if (contador > 0 || verificador > 0) {
			printf("\nInforme novamente os dados da venda");
			continue;
		} else {
			notasfiscais[posicao] = notafiscal;
			posicao++;
		}


		quantVendas++;
		matriz [vendedor - 1][dia - 1] = matriz [vendedor - 1][dia - 1] + valorvenda;
		vetorVdia[dia - 1]++;

	}

	printf("\nRESUMO DE VENDAS POR VENDEDOR");

	float totalComissoes = 0;

	for (int i = 0; i < qVendedores; i++) {
		float mediaDia = 0;
		printf("\nVendedor %d", i + 1);

		for (int j = 0; j < diasMes; j++) {

			if (matriz[i][j] > 0) {
				printf("\ndia %d: %.2f reais", j + 1, matriz[i][j]);
				mediaDia = mediaDia + matriz[i][j];
			}
		}

		printf("\nvalor medio vendido por dia: %.2f reais", mediaDia/diasMes);

		if (mediaDia <= 2000) {
			printf("\nvalor da comissao (%d%): %.2f reais", 5, (mediaDia/100.0)*5.0);
			totalComissoes = totalComissoes + (mediaDia/100.0)*5.0;
		} else if(mediaDia < 5000) {
			printf("\nvalor da comissao (%d%): %.2f reais", 7, (mediaDia/100.0)*7.0);
			totalComissoes = totalComissoes + (mediaDia/100.0)*7.0;
		} else if(mediaDia >= 5000) {
			printf("\nvalor da comissao (%d%): %.2f reais", 10, (mediaDia/100.0)*10.0);
			totalComissoes = totalComissoes + (mediaDia/100.0)*10.0;
		}
	}

	printf("\nRESUMO DE VENDAS POR DIA");

	float totalMes = 0;

	for(int i = 0; i < diasMes; i++) {
		for (int j = 0; j < qVendedores; j++) {
			if (matriz[j][i] > 0) {
				totaldia[i] = totaldia[i] + matriz[j][i];
			}
		}

		totalMes = totalMes + totaldia[i];

		if (totaldia[i] > 0) {
			printf("\nDia %d: %d venda(s) com valor total de %.2f reais", i+1, vetorVdia[i], totaldia[i]);
		}
	}

	printf("\nRESUMO DE VENDAS NO MES");
	printf("\nquantidade de vendas: %d", quantVendas);
	printf("\nvalor total vendido: %.2f reais", totalMes);
	printf("\nvalor total de comissoes pagas: %.2f reais", totalComissoes);

}