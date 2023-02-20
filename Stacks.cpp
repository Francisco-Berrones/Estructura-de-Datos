#include <iostream>
using namespace std;
#include "Stacks.h"



int main(){
    Stacks Pilas;
    cout << "-------------------PILAS-----------------------";
    Pilas.isEmpty();
    /*Pilas.enQueue(5);
    Pilas.enQueue(10);
    Pilas.enQueue(20);
    Pilas.enQueue(25);
    Pilas.enQueue(30);
    Pilas.printQueue();*/
    cout << "\n";
    cout << "Tamanio de la lista es de " << Pilas.getSize();
    cout << "\n";
    cout << "----------------------------------------------" << endl;
    //cout << "-------------------QUEUE-----------------------" << endl;
    cout << "Utilizando deQueue " << "se elimina el numero: " << Pilas.deQueue() << endl;
    //Pilas.printQueue();
    cout << "\n";
    cout << "El nuevo tamanio del Queue es de: " << Pilas.getSize();
    cout << "\n";
    cout << "----------------------------------------------" << endl;
    cout << "Utilizando el metodo front " << "el numero que esta primero es: " << Pilas.front();
    cout << "\n";
    cout << "Utilizando el metodo back " << "el numero que esta al ultimo es: " << Pilas.back();
    cout << "\n";
    cout << "----------------------------------------------" << endl;
    cout << "Usando el metodo clear, el nuevo tamanio de la lista es: ";
    Pilas.clear();
    //cout << Pilas.getSize();
    cout << "\n";
    cout << "----------------------------------------------" << endl;



    return 0;
}