#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
 
int main(void) {
  //int x; 

  //cout << "Type a number: "; // Type a number and press enter
  //cin >> x; // Get user input from the keyboard

  
  int vetor [10] = {9,2,3,5,1,7,8,4,6,0};
  int i;
  void ordemCrescente(int vetor[10], int n);

  ordemCrescente(vetor, 10);

  for (i = 0; i < 10; ++i) {
    printf("%i ", vetor[i]);
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