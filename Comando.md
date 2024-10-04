# Avaliação do Grau de Pureza do Aço

Uma indústria siderúrgica produz aço em seus 5 fornos. Cada lote de aço produzido é avaliado para determinar o seu grau de pureza, classificado de acordo com três critérios:

- Percentual de conteúdo de carbono
- Dureza na escala Rockwell
- Resistência à tração

São realizados três testes com o aço produzido para saber se ele atende às seguintes condições:

**Teste 1:** Percentual de conteúdo de carbono abaixo de 7%
**Teste 2:** Dureza Rockwell maior do que 50
**Teste 3:** Resistência à tração maior do que 80,000 psi

De acordo com o resultado destes testes, é atribuído o grau de pureza do aço produzido seguindo as seguintes regras:

| Testes Atendidos | Grau Definido para o Aço Produzido |
|------------------|-------------------------------------|
| 1, 2 e 3         | 10                                  |
| 1 e 2            | 9                                   |
| 1 e 3            | 8                                   |
| 2 e 3            | 7                                   |
| Somente 1        | 6                                   |
| Somente 2        | 5                                   |
| Somente 3        | 4                                   |
| Nenhum           | 0                                   |

## Programa em C

Elabore um programa em C que receba inicialmente a quantidade de lotes de aço produzidos e depois receba para cada lote:

- O número do forno em que ele foi produzido
- O percentual de conteúdo do carbono (PC) medido para o lote
- A dureza Rockwell (DR) medido para o lote
- A resistência à tração (RT) medida para um lote de aço produzido

Após receber todos os dados dos lotes de aço produzidos, o programa deve exibir:

1. O grau de pureza de cada lote
2. Estatísticas, incluindo:
   - Quantidade de lotes produzidos por forno
   - Grau médio de pureza do aço nos lotes produzidos em cada forno
   - O(s) forno(s) que produziram lotes com maior grau de pureza
   - O(s) forno(s) que produziram lotes com menor grau de pureza.

Por causa da limitação do tempo para elaboração do programa, considere que as entradas vão ser sempre válidas, ou seja, não precisa fazer a validação das mesmas.

## Exemplo de Formatação

### Entrada e Saída


Entre com o número de lotes produzidos: `4`

Entre com uma linha para cada lote produzido com os dados separados por um espaço em branco e na seguinte ordem: Número do forno, Percentual de carbono (PC), Dureza Rockwell (DR), Resistência à tração (RT)

Lote 1: `2 5.1 70 90000`
Lote 2: `4 7.5 40 70000`
Lote 3: `2 7.5 30 70000`
Lote 4: `1 7.5 70 70000`

## Grau de Pureza dos Lotes Produzidos
Lote 1: `10`
Lote 2: `0`
Lote 3: `0`
Lote 4: `5`

## Estatísticas

**Forno 1:** `1 lote(s)` com grau médio de pureza de `5.0`
**Forno 2:** `2 lote(s)` com grau médio de pureza de `5.0`
**Forno 3:** `0 lote(s)`
**Forno 4:** `1 lote(s)` com grau médio de pureza de `0.0`
**Forno 5:** `0 lote(s)`



**Fornos que produziram lote(s) com maior grau de pureza (grau 10):** `2`
**Fornos que produziram lote(s) com menor grau de pureza (grau 0):** `2, 4`
```