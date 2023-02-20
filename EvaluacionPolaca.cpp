#include <iostream>
using namespace std;
#include "StackDouble.h"
#include <math.h>
#include <string.h>

//David Treviño Camarillo #624996
//Luis Guillermo Roman Escalera #624618
//Francisco Ariel Berrones Gomez #625824


bool esOperando(char s){
    if(s>='0' && s<='9'){
        return true;
    }
    else{
        return false;
    }
}
double evalua(char s, double a, double b){
    double resultado=0;
    switch (s)
    {
    case '+':
        resultado=a+b;
        break;
    case '-':
        resultado=a-b;
        break;
    case '*':
        resultado=a*b;
        break;
    case '/':
        resultado=a/b;
        break;
    case '^':
        resultado=pow(a,b);
        break;
    default:
        break;
    }
    return resultado;
}

int main(){
    char expresion[100];
    cout<<"Cual es la expresion postfija? SIN ESPACIOS\n";
    cin>>expresion;
    char elemento;
    int i=0;
    int total=strlen(expresion);
    StackDouble pila(30);
    double op1, op2;
    while(i<total){
        elemento=expresion[i];
        i++;
        if(esOperando(elemento)){
            pila.push(elemento-'0');
        }
        else{
            op2=pila.pop();
            op1=pila.pop();
            pila.push(evalua(elemento, op1, op2));
        }
    }
    cout<<"\nResultado: "<<pila.pop();
    return 0;
}

//"Doy mi palabra de que hemos realizado esta actividad con integridad academica"