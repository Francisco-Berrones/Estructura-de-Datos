//Francisco Ariel Berrones Gomez
//#625824

#include "iostream"
#include "math.h"
#include "array"
using namespace std;

int ImparIterativo(int imparnum[]){ //Funcion para calcular el impar
    int resultado = 0;
    for(int i =0; i<=10; i++){
        if(imparnum[i]%2 !=0){
            resultado += imparnum[i];
        }
        
    }
    return resultado;
}

//Main
int main(){
    int imparnum[] = {1,2,3,4,5,6,7,8,9,10}; //Declaro mi arreglo
    cout << "De los numeros seleccionados la suma de los impares es: " << ImparIterativo(imparnum); //Llamo a mi funcion
    return 0;
}