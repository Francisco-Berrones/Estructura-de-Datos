//Francisco Ariel Berrones Gomez 625824
//Ricardo Arath Sanchez Aguirre

#include <iostream>
using namespace std;
    int num[100];
    int i,j,n; // Variables para ciclos for.

    int aux; // Variable de apoyo.

    int minimo, nummin; // Variable para almacenar el numero minimo del arreglo.

    int opt; // Variable para la opcion que ingrese el usuario en el uso del menu.


void Menu(){
        cout << "-----------------------------------------------------------------" << endl;
        cout << "--------BIENVENIDO, ESCOGA UNA DE LAS SIGUIENTE OPCIONES---------" << endl;
        cout << "--------1. DIGITE ARREGLO DE NUMEROS-----------------------------" << endl;
        cout << "--------2. ARREGLO POR SELECCION---------------------------------" << endl;
        cout << "--------3. ARREGLO POR INSERCION---------------------------------" << endl;
        cout << "--------4. SALIR-------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------------" << endl;
}

void Arreglo(){
    int num[100], n;


    cout << "Digite el tamanio de tu arreglo: " << endl;
    cin >> n;

    for(int i=0; i<n; i++){
        cout << "Digite el numero: " ;
        cin >> num[i];
    }

    //Despliega en pantalla el orden de numeros
    cout << "Tu Arreglo de Numeros: " ;
    for(int i=0;i<n;i++){
        cout<<num[i]<<" ";
    }
}

void Insercion(){
    int i, key, j;
	for (i = 1; i < n; i++) // Ciclo for para 
	{
		key = num[i];
		j = i - 1;

		while (j >= 0 && num[j] > key) // Ciclo while para cambiar los numeros de posicion.
		{
			num[j + 1] = num[j];
			j = j - 1;
		}
		num[j + 1] = key;
	}
    
    cout << "Numeros ordenados: "; // Mensaje para mostrar los numeros.

    for (i = 0; i < n; i++) // Ciclo for para imprimir los numeros ordenados.
    {
	cout << num[i] << " ";
    }
}

void Seleccion(int num[100]){

    for(i=0; i<n;i++){
    //Declaramos que el primer numero siempre sera el menor
    nummin = i;
    //EL segundo ciclo for comienza apartir del segundo numero del array
    for(j=i+1;j<n;j++){
        if(num[j] < num[nummin]){
            nummin = j;
        }
    }
    aux = num[i];
    num[i] = num[nummin];
    num[nummin] = aux;
    }

    cout << "Numeros Ordenados: " ; // Se imprimen los numeros ordenados por medio de un ciclo for.
    for(i=0;i<n;i++){
        cout << num[i] << " ";
    }
}



int main(){

    int num[100]; //Arreglo
    int i,j,n; // Variables para ciclos for.
    int aux; // Variable de apoyo.
    int minimo; // Variable para almacenar el numero minimo del arreglo.
    int op, op2;
    do{
        cout << endl;
        Menu();
        cout << "SELECCIONA UNA OPCION: " << endl;
        cin >> op;

        if(op>4 && op<0){
            cout << "OPCION INVALIDA, DIGITE UN NUMERO CORRECTO " << endl;
            cin>> op;
        }

        switch(op){
        case 1:
            cout << "\x1B[2J\x1B[H";    //limpia pantalla
            Arreglo();

            

        break;

        case 2:
        
            Seleccion(num);
            
        break;

        case 3:
            Insercion();
            
        break;

        case 4:
            op=4;
            exit(1);
        break;

        }

    }while (op2 != 4);
        system ("pause");
    
    
    return 0;
}