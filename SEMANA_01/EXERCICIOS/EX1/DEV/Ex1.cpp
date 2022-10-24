#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){ 
    string name, sobrenome;
    float valorMin = 0; //sempre zerar numeros 
    float valorMax = 0;
    float valorInput = 0;

    cout << " Seja bem vindo, meu caro!"<<endl;
    cout << " Digite o valor minimo e máximo: "<<endl;
    cin >> valorMin;
    cin >> valorMax;
    cout << " Digite a medida: "<<endl;
    cin >> valorInput;

    int ajuste = ((valorInput - valorMin)/(valorMax - valorMin))*100 ;
    cout << "O numero ajustado é: " << ajuste << "%" << endl;
}
