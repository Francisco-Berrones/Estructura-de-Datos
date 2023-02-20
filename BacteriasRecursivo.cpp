#include "iostream"
#include "math.h"
using namespace std;

int dias; int inicializacionbact = 1; int pantalla = 0;

void BacteriasRecursivo(){
    inicializacionbact = ceil((inicializacionbact + (inicializacionbact*3.78) - (inicializacionbact*2.34)));

}

void Recursividad(){
    if(dias==0){ 
        cout << "El total de bacterias que se han generado dentro de " << pantalla << " dias, es de: " << inicializacionbact << endl;
    }else { 
        BacteriasRecursivo(); 
        pantalla=pantalla+1; 
        cout << "El total de bacterias que se han generado dentro de " << pantalla << " dias, es de: " << inicializacionbact << endl;
        dias=dias-1; 
        Recursividad();

    }
}

int main(){
    cout << "------Programa que calcula el indice del crecimiento de una bacteria de forma recursiva------"<< endl;
    cout << "------Digite por favor el numero de dias que desea calcular------: ";
    cin >> dias;
    Recursividad();
    
    return 0;
}

