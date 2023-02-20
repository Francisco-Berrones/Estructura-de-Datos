#include <iostream>
using namespace std;
#include "ListaString.h"

//David Treviño Camarillo #624996
//Francisco Ariel Berrones Gomez #625824
//Luis Guillermo Roman Escalera #624618

int main(){
    ListaString soldados;
    string nombre, inicia;
    int x, n;
    cout<<"Cuantos soldados son?\n";
    cin>>x;
    for(int i=0;i<x;i++){
        cout<<"Cual es el nombre del soldado "<<i+1<<" \n";
        cin>>nombre;
        soldados.addLast(nombre);
    }
    cout<<"Lista de soldados:\n";
    cout<<"-------------------------\n";
    soldados.printList();
    cout<<"\n-------------------------\n";
    cout<<"Quien inicia?\n";
    cin>>inicia;
    int ix=soldados.findData(inicia);
    cout<<"Cada cuanto se eliminan?\n";
    cin>>n;
    cout<<"Inicia el soldado en la posicion: "<<soldados.findData(inicia)<<"\nSe eliminan cada "<<n<<" posiciones\n";
    if(ix>=soldados.getSize()){
        ix-=soldados.getSize();
    }
    while (soldados.getSize()>1){
        cout<<"Eliminado: "<<soldados.getData(ix+n-1)<<"\n";
        if(soldados.deleteAt(ix+n-1)){
            cout<<"Soldado Eliminado\n";
        }
        else{
            cout<<"Soldado no eliminado\n";
        }
        ix=ix+n-1;
        if(ix>=soldados.getSize()){
            ix=ix-soldados.getSize();
        }
    }
    cout<<"Sobrevive:\n";
    soldados.printList();
    return 0;
}

//Damos nuestra palabra de haber realizado esta actividad academica