//David Treviño Camarillo #624996
//Francisco Ariel Berrones Gomez #625824
//Luis Guillermo Roman Escalera #624618

#include <iostream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <sys/stat.h>
using namespace std;
#include "Animales.h"

int main(){
    fstream archivo;
    struct stat buff;
    int actual=stat("Data.txt", &buff);
    if(actual==0){
        archivo.open("Data.txt",ios::in);
        leer(inicia, archivo);
        archivo.close();
        cout<<"Iniciando...\n";
        system("CLS");
        pregunta(inicia, NULL);
        archivo.open("Data.txt",ios::out);
        escribir(inicia, archivo);
        archivo.close();
    }
    else{
        cout<<"No se pudo abrir el archivo\n";
    }
    return 0;
}