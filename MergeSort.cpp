//Francisco Ariel Berrones Gomez #625824
//Ricardo Arath Sanchez Aguirre #583928
#include <iostream>
using namespace std;

int MergeSort[100];
int particion;

//void para realizar el merge sort
//En este se hace toda la evalucion de los numeros, para ir comparando y sacarlos y ordenarlos de mayor a menor
void Merge(int izquierda,int particion, int derecho){
    int i,j,k,m[100],n;
    i = izquierda; j = izquierda; k = particion+1;

        while((i<=particion)&&(k<=derecho)){
            
            if(MergeSort[i]<=MergeSort[k]){

                m[j]=MergeSort[i];
                i++;

            }
            else{

                m[j]=MergeSort[k];
                k++;

            }

            j++;
        }
        if((i>particion)){

            for(n=k;n<=derecho;n++){

                m[j]=MergeSort[n];
                j++;

            }
        }
        else{
            for(n=i;n<=particion;n++){

                m[j] = MergeSort[n];
                j++;

            }
        }
        for(n=izquierda;n<=derecho;n++){
            MergeSort[n]=m[n];
        }
}

//Void para que parte el arreglo a la mitad
void Dividir(int izquierda,int derecho){
    int particion;
    if(izquierda < derecho){
        particion = (izquierda+derecho)/2;
        Dividir(izquierda,particion); Dividir(particion+1,derecho); Merge(izquierda,particion,derecho);
    }
   
}

//Void para desplegar en el main
void Mostrar(){
    int numero, iteracion;

    cout<<"----------------------------------"<<endl;
    cout << "Digite el tamanio del arreglo: "<<endl;
    cin>> numero;
    cout<<"----------------------------------"<<endl;
    cout << "Digite el arreglo de elementos: "<<endl;
    for(iteracion=1;iteracion<=numero;iteracion++){
        cin >> MergeSort[iteracion];
    }
    //Llamamos void de divir
    Dividir(1,numero);
    cout<<"---------------------------"<<endl;
    cout<<"Arreglo ordenado por merge: "<<endl;
    //Despliega el arreglo en orden
    for(iteracion=1;iteracion<=numero;iteracion++){ 
        cout<<MergeSort[iteracion]<<" ";
    }

}

int main(){
    //Funcion para mostrar todo el sistema
    Mostrar();
    return 0;
}

//Damos nuestra palabra de que hemos realizado esta actividad con integridad academica