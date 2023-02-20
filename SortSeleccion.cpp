#include <iostream>
using namespace std;

//Francisco Ariel Berrones Gomez
//Implementacion de Sort de Seleccion

int main(){
    int Sort[6]; //Arreglo
    int i,j; //Ciclos
    int apoyo; //Variable de apoyo
    int nummin; //Ayuda a almacenar el numero minimo para realizar el sort
	
	//Se le pide al usuario digitar los numero aleatorios
	cout << "Digite 6 numeros aleatorios porfavor:D " << endl; 
	//Ciclo for para que se vayan almacenando en cada espacio del arreglo
	for(int n=0; n<6; n++){
		cin >> Sort[n];
	}
	
	//Ciclo para hacer el sort de los numeros
    for(i=0; i<6;i++){
    	//Declaramos que el primer numero siempre sera el menor
        nummin = i;
        //EL segundo ciclo for comienza apartir del segundo numero del array
        for(j=i+1;j<6;j++){
            if(Sort[j] < Sort[nummin]){
                nummin = j;
            }
        }
        apoyo = Sort[i];
        Sort[i] = Sort[nummin];
        Sort[nummin] = apoyo;
    }
	
	//Despliega en pantalla el orden de numeros
    cout << "Tu Arreglo de Numeros Ordenados: " ;
    for(i=0;i<6;i++){
        cout<<Sort[i]<<" ";
    }
    return 0;
}
