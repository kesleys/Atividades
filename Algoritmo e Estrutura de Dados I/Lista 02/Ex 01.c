#include <stdio.h>

int main(){
    
    float valorSaldo;
    int valorSaque;
    
//------------------------------------------------------------------------------------------------//
    // Para receber o Saldo
    printf("Entre com o saldo da conta a ser sacada (em reais): ");
    scanf("%f", &valorSaldo);
    printf("\n"); // Pula Linha
    
    
    
    
//------------------------------------------------------------------------------------------------//
    // Para receber o valor do saque
    do { // Recebe o valor do saque até ser válido
        
        printf("Entre com o valor do saque (em reais): ");
        scanf("%d", &valorSaque);
        printf("\n"); // Pula Linha
        
        if(valorSaque > valorSaldo){
            printf("Saldo insuficiente para valor desejado");
            printf("\n"); // Pula Linha
            printf("\n"); // Pula Linha
        }
        
        if(valorSaque <= 0 ){
            printf("Valor do saque invalido");
            printf("\n"); // Pula Linha
            printf("\n"); // Pula Linha
        }
        
        if(valorSaque == 1 || valorSaque == 3){
            printf("Valor do saque incompativel com notas disponiveis");
            printf("\n"); // Pula Linha
            printf("\n"); // Pula Linha
        }
        
    } while(valorSaque > valorSaldo || valorSaque <= 0 || valorSaque == 1 || valorSaque == 3);
    
    printf("\nRESULTADOS\n");


//------------------------------------------------------------------------------------------------//
    // Para imprimir o saldo restante após o saque
    printf("Valor atualizado do saldo (em reais): %.2f", valorSaldo - valorSaque);
    printf("\n"); // Pula Linha
    printf("\n"); // Pula Linha
    
    
    
    
//------------------------------------------------------------------------------------------------//
    // Associar uma posição de um elemento do array a uma cédula
    int nota2 = 0, nota5 = 1, nota10 = 2, nota20 = 3, nota50 = 4, nota100 = 5;
    int saque = valorSaque;
    
    
    
//------------------------------------------------------------------------------------------------//
    //Para dinheiro menos trocado
    printf("Opcao de saque 1 (menor quantidade possivel de cedulas):");
    printf("\n"); // Pula Linha
    
    int notas[6] = {0, 0, 0, 0, 0, 0};
    
    if(valorSaque%5 == 1){
        notas[nota2]++;
        valorSaque = valorSaque - 2;
    }
    if(valorSaque%5 == 3){
        notas[nota2] = notas[nota2] + 2;
        valorSaque = valorSaque - 4; 
    }
    
    while(valorSaque != 0){
        
        if(valorSaque >= 100){// Vê a uantidade de notas de 100;
            
            notas[nota100]++;
            valorSaque = valorSaque - 100;
            
        }else{//Passa pra 50 se n tiver mais de 100;
            
            if(valorSaque >= 50){// Vê a uantidade de notas de 50;
                
                notas[nota50]++;
                valorSaque = valorSaque - 50;
            
            }else{//Passa pra 20 se n tiver mais de 50;
            
                if(valorSaque >= 20){// Vê a uantidade de notas de 20;
                
                    notas[nota20]++;
                    valorSaque = valorSaque - 20;
            
                }else{//Passa pra 10 se n tiver mais de 20;
            
                    if(valorSaque >= 10){
                
                        notas[nota10]++;
                        valorSaque = valorSaque - 10;
            
                    }else{//Passa pra 5 se n tiver mais de 10;
            
                        if(valorSaque >= 5){
                
                            notas[nota5]++;
                            valorSaque = valorSaque - 5;
            
                        }else{//Passa pra 2 se n tiver mais de 5;
            
                            if(valorSaque >= 2){
                
                                notas[nota2]++;
                                valorSaque = valorSaque - 2;
            
                            }
                        }
                    }
                }
            }
        }
        
    }
    
//imprime esses valores

    if(notas[5] > 0){
        printf("Cedulas de 100 reais: %d", notas[5]);
    }//notas de 100
    printf("\n"); // Pula Linha
    
    if(notas[4] > 0){
        printf("Cedulas de 50 reais: %d", notas[4]);
    }//notas de 50
    printf("\n"); // Pula Linha
        
    if(notas[3] > 0){
        printf("Cedulas de 20 reais: %d", notas[3]);
    }//notas de 20
    printf("\n"); // Pula Linha
        
    if(notas[2] > 0){
        printf("Cedulas de 10 reais: %d", notas[2]);
    }//notas de 10
    printf("\n"); // Pula Linha
    
    if(notas[1] > 0){
        printf("Cedulas de 5 reais: %d", notas[1]);
    }//notas de 5
    printf("\n"); // Pula Linha
    
    if(notas[0] > 0){
        printf("Cedulas de 2 reais: %d", notas[0]);
    }//notas de 2
    printf("\n"); // Pula Linha
    
//------------------------------------------------------------------------------------------------//







//------------------------------------------------------------------------------------------------//
    // Para dinheiro mais trocado
    printf("Opcao de saque 2 (maior quantidade possivel de cedulas):");
    printf("\n"); // Pula Linha

    int nota[6] = {0, 0, 0, 0, 0, 0};
    
    if(saque%2 == 0){
        nota[nota2] = saque/2;
    }else{
        saque = saque - 5;
        nota[nota5]++;
        nota[nota2] 
        = saque/2;
    }
    
    printf("Cedulas de 2 reais: %d", nota[0]);
    printf("\n"); // Pula Linha
    
    if(nota[1] > 0){
        printf("Cedulas de 5 reais: %d", nota[1]);
    }
}