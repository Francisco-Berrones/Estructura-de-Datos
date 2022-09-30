#include <iostream>
#include <fstream>
using namespace std;

#include "Calificacion.h"

int main(){

    Calificacion cal[20];
    ifstream entrada;
    string nombre;
    double act, ex, proy;
    entrada.open("calificaciones.txt");
    while (entrada >> nombre >> act >> ex >> proy){
            cout << nombre << endl;
            cout << " Act " << act << endl;
            cout << " Ex " << ex << endl;
            cout << " Proy " << proy << endl;
    }
    return 0;
}