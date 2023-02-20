#include "iostream"
using namespace std;
#include "math.h" 

int dias; int inicializacionbact = 1; int pantalla = 0;

void BacteriasIterativo(){
    inicializacionbact = ceil((inicializacionbact + (inicializacionbact*3.78) - (inicializacionbact*2.34)));
}

int main(){
    cout << "------Programa que calcula el indice del crecimiento de una bacteria de forma iterativa------"<< endl;
    cout << "------Digite por favor el numero de dias que desea calcular: ";
    cin >> dias;

    while(dias!=0){

        BacteriasIterativo();
        pantalla=pantalla+1; 
        cout << "El total de bacterias que se han generado dentro de " << pantalla << " dias, es de: " << inicializacionbact << endl;
        dias=dias-1; 
    }



    return 0;
}
