#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#

int verificarNombre(int cant, string puertos[100], string pue){
    for(int index=0;index<=cant;index++){   //Busca en el arreglo nombres de puertos iguales al dado
        if(pue==puertos[index]){
            return index;   //Regresa la localizacion en el arreglo si lo encuentra
        }
    }
    //Si no lo encuentra se pide otra vez, y se vuelve a realizar la verificacion
    cout<<"No se identifico el nombre, intente de nuevo: ";
    cin>>pue;
    return verificarNombre(cant,puertos,pue);
}

int main(){

    system("cls");

    ifstream Entrada;   //Se crea variable para tomar actores de un txt
    Entrada.open("red_puertos.txt");
    string frase[100];   //Variable ara guardar frase
    int i=0;
    while(!Entrada.eof()){  
        getline(Entrada, frase[i]);
        i++;    
    }
    int cantpath=stoi(frase[0]);
    int cantpuertos=stoi(frase[cantpath+1]);
    Entrada.close();

    // Se crean las variables con arreglos del tamaño del numero de puertos
    // Se crea el known, costo y path, asi como la matriz de caminos
    bool known[cantpuertos];
    int cost[cantpuertos] = {INF};
    int path[cantpuertos];
    int adjMat[cantpuertos][cantpuertos];

    //Se crea variable para guardar los puertos por nombre e index
    string puerto[cantpuertos];
    i=0;
    cout << "----------------------------PUERTOS------------------------------\n";
    while(i<cantpuertos){
        puerto[i]=frase[i+cantpath+2];  // Se guardan tomando de referencia los caminos y los dos numeros
        cout<<puerto[i]<<endl;
        i++;
    }

    // Se dan los valores iniciales a todos los puertos
    // Costo es infinito, path es -1, known es false, y la matriz es infinita para cada camino
    for(i = 0; i<cantpuertos; i++){
        cost[i] = INF;
        path[i] = -1;
        known[i] = false;
        for(int j = 0; j<cantpuertos; j++){
            adjMat[i][j] = INF;
        }
    }

    // Se dan los valores a los caminos que se conocen
    int j=0,k=0;
    i=0;
    string palabra[2];
    while(i<cantpath){
        j=i+1;  //Localizador de frases
        k=0;    //Contador de palabras
        while(frase[j]!=""){ 
            int l=frase[j].find(" ");  
            palabra[k]=frase[j].substr(0,l);
            frase[j].erase(0,l+1);
            if(l==-1){
                frase[j].erase(0,30);
            }
            k++;    
        }
        //La primer y segunda palabra son puertos, mientras que la tercera es el costo
        //Para cada conjunto de puertos existente se crea una matriz con el costo dado
        adjMat[verificarNombre(cantpuertos, puerto, palabra[0])][verificarNombre(cantpuertos, puerto, palabra[1])]=stoi(palabra[2]);
        //Se crea tambien una matriz con los puertos volteados, para poder hacer procesos con diferentes nodos de inicio
        adjMat[verificarNombre(cantpuertos, puerto, palabra[1])][verificarNombre(cantpuertos, puerto, palabra[0])]=stoi(palabra[2]);
        i++;
    }
    // El comienzo es desde el nodo dado
    string nomStart;
    cout << "-----------------------------------------------------------------\n";
    cout<<"Indique el nombre del puerto por el cual desea iniciar: ";
    cin >> nomStart;
    // Verificar que el nombre exista y regresar el index
    int start = verificarNombre(cantpuertos, puerto, nomStart);
    //El costo del nodo inicial se cambia a 0, porque ya se conoce
    cost[start] = 0;
    int vActual = start;
    int verdaderos = 0;
    int menor = INF;
    int idxMenor;

    // Se hace un ciclo por cada puerto
    do
    {
        known[vActual] = true; // El nodo actual se vuelve true
        verdaderos++;
        menor = INF;
        // Se busca si existe un nodo pegado al camino actual que no se haya vuelto true para cada puerto
        for(int col = 0; col < cantpuertos; col++){
            if(adjMat[vActual][col] != INF && known[col] == false){
                // Si el costo que tiene el puerto es mayor al de la suma de el camino actual y el camino del actual al puerto
                // El costo cambia al de la suma y el path cambia al actual 
                if(cost[col] > cost[vActual] + adjMat[vActual][col]){
                    cost[col] = cost[vActual] + adjMat[vActual][col];
                    path[col] = vActual;
                }  
            }
        }
        //cout<<cost[7];
        // Se busca el menor camino con known = false
        for(int i = 0; i < cantpuertos; i++){
            if(menor > cost[i] && known[i] == false){
                menor=cost[i];
                idxMenor = i;
            }
        }
        // El nodo actual es el de menor camino con known =false 
        vActual = idxMenor;

    } while (verdaderos < cantpuertos);

    int sig = INF;
    // PAra el puerto
    //sig = i;
    string nomPlleg;
    cout<<"Puerto llegada: ";
    cin>>nomPlleg;
    cout << "----------------------------COSTO------------------------------\n";
    int plleg = verificarNombre(cantpuertos, puerto, nomPlleg);
    sig=plleg;
    
        // Mientras el camino no sea el final, es decir =-1
    while(path[sig] != -1){
            // Se va recorriendo por el path de cada puerto
        cout << puerto[sig] << "<-";
        sig = path[sig];
    }
        // Se despliega el costo
    cout << puerto[start] << "\t   Costo: " << cost[plleg] << endl;
    cout << "-----------------------------------------------------------------\n";

    return 0;
}