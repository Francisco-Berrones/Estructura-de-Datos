#include <iostream>
#include <math.h>
#include <array>

using namespace std;
int numerorecursivo = 0;
int resultado = 0;

int ImparRecursivo(int numerorecursivo){
    if(numerorecursivo !=0){
        if(numerorecursivo %2 !=0)
        resultado += numerorecursivo;
    }else {
        cout << "La sumatoria de los numeros seleccionados es: " << resultado;
    }
numerorecursivo--;
ImparRecursivo(numerorecursivo);
}

int main(){
    int arreglo[] = {1,2,3,4,5,6,7,8,9,10};
    int ImparRecursivo(arreglo[9]);
}