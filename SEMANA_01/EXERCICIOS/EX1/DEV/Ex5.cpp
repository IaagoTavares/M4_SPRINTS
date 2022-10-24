#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main(void) {
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
