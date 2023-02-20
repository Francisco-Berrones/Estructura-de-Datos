//David Treviño Camarillo #624996
//Francisco Ariel Berrones Gomez #625824
//Luis Guillermo Roman Escalera #624618

#include <iostream>
#include <stdexcept>
using namespace std;


class NodeStacks{
    friend class Stacks;
    private:
        NodeStacks *next;
        NodeStacks *prev;
        int data;
};

class Stacks{
    private:

        //Atributos
        NodeStacks *top;
        int size, tam, TamMax;

    public:
        
        //Metodos
        Stacks(int max = 100);           //Constructor
        bool isEmpty();
        void pop();         //Borra el ultimo valor agregado al stack
        void push();        //Agrega un nodo al stack
        void Top();         //Despliega el valor que esta primero en el stack
        int getSize();      //Obtiene el tamanio del stack
        void clear();       //Botta todos los valores dentro del stack
        void print();       //Imprime el stack completo
        ~Stacks();          //Destructor

};


//Derivacion de Metodos
Stacks::Stacks(int max){
    cout << "Fila creada \n";
    top = new NodeStacks;
    top = nullptr;
    int size = 0;
    tam = 0;
    TamMax=max;
}

bool Stacks::isEmpty(){
    return(tam==0);
}

void Stacks::pop(){
    if(!isEmpty()){
        
    }
}

void Stacks::push(){}

void Stacks::Top(){
    if(!isEmpty()){
        //return 
    }
    else{
        throw out_of_range("No hay datos en la pila");
    }
}

int Stacks::getSize(){
    return tam;
}

void Stacks::clear(){
    while(!isEmpty()){
        pop();                                                //Mientras no este vacia la fila llama a la funcion deQueue
    }
}

void Stacks::print(){
    if(tam>0){

    }else{
        cout << "Lista vacia \n";
    }
}

Stacks::~Stacks(){
    delete top;
}