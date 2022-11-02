#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>


using namespace std;

vector <int> distancias;
int maior[2] = {0, 0};
bool continuar;

// 1 - Faça uma função que recebe uma certa medida e ajusta ela percentualmente entre dois 
//valores mínimo e máximo e retorna esse valor
float convercaoSensor(float valor, float max, float min) {
	float percentual = (valor - min) / (max - min) * 100;
	if (percentual > 100) {
		return 100;
	} else if (percentual < 0) {
		return 0;
	} else {
		return percentual;
	}
}


// 2 - Faça uma função que simule a leitura de um sensor lendo o
// valor do teclado ao final a função retorna este valor
int verificaSensor() {
	float valor;
	std::cin >> valor;
	return valor;
}


// 3 - Faça uma função que armazena uma medida inteira qualquer
// em um vetor fornecido. Note que como C não possui vetores
// nativos da linguagem, lembre-se que você precisa passar o
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em
// uma área de memória fora do vetor
int inputaMedida(int *valores, int tamanho, int ultimaPosicao, int valor) {
	int ultimaPosition = ultimaPosicao++;

	if(ultimaPosition < tamanho) {
		valores[ultimaPosition] = valor;
	} else {
		printf( "A posição fornecida está acima do tamanho do vetor." );
	}

	return ultimaPosition;
}


// 4 - Faça uma função que recebe um vetor com 4 posições que contém
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a
// segunda é esta maior distância.
void direction() {
    int maiorDistancia = 0;
    int maiorValor = distancias[0];


    for (int i = 1; i < 4; i++) {
        if (distancias[i] > maiorValor) {
            maiorValor = distancias[i];
            maiorDistancia = i;
        }
    }

    maior[0] = maiorDistancia;

    maior[1] = maiorValor;
}




// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e
// retorna verdadeiro ou falso
void perguntaContinue() {
    string decisao ;
    int resultado;

    string yes = "sim";
    string no = "nao";

    cout << "Deseja continuar? (sim/nao)"<<endl;
    cin >> decisao;

    resultado = decisao == yes; // false

    if (resultado == 1)
    {
        cout << "True"; 
    }
    else if (resultado == 0)
    {
        cout << "False";
    }
}


// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas
void movimentacao() {
    cout << endl << "O robo se movimentou para ";

    if (maior[0] == 0) {
        distancias[0] -= 1;
        distancias[1] += 1;

        cout << "a direita" << endl;
    }
    else if (maior[0] == 1) {
        distancias[1] -= 1;
        distancias[0] += 1;

        cout << "a esquerda" << endl;
    }
    else if (maior[0] == 2) {
        distancias[2] -= 1;
        distancias[3] += 1;

        cout << "frente" << endl;
    }
    else if (maior[0] == 3) {
        distancias[3] -= 1;
        distancias[2] += 1;

        cout << "tras" << endl;
    }
}





int main() {
    const string lados[4] = {"Direita", "Esquerda", "Frente", "Tras"};
    inputaMedida();
    continuar = true;
    cout << "As distancias sao:" << endl << endl;
    for (int i=0; i < 4; i++) {
        cout << lados[i] << ": " << distancias[i] << endl;
    }
    while (continuar == true) {
        direction();
        movimentacao();
        cout << "As distancias sao:" << endl << endl;
        for (int i=0; i < 4; i++) {
            cout << lados[i] << ": " << distancias[i] << endl;
        }
        perguntaContinue();
    }
    return 0;
}