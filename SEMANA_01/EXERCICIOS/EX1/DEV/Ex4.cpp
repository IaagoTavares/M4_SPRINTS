#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
 
int main(void) {

  //Insira os valores
  int vetor [4] = {9,2,3,5};
  //Repita os valores
  int vetorSegundo [4] = {9,2,3,5};

  int i;
  
  void ordemCrescente(int vetor[4], int n);

  ordemCrescente(vetor, 4);

  int maior = vetor[3];

  if (maior == vetorSegundo[0])
    {
        cout << "Direita\n";  // executed
    }
    else if (maior == vetorSegundo[1])
    {
        cout << "Esquerda\n";
    }
    else if (maior == vetorSegundo[2])
      {
          cout << "Frente\n";
      }
    else if (maior == vetorSegundo[3])
        {
            cout << "Tras\n";
        }
    
}


void ordemCrescente(int vetor[], int n) {
  int i, j, temporaria;

  for (i = 0; i < n; ++i) {
    for(j = i + 1; j < n; ++j){
      if(vetor[i] > vetor[j]){
        temporaria = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temporaria;
        
      }
    }
  }
  
}