#include <iostream>
using namespace std;
#include "Node.h"

class Lista{
    private:
        Node *head;
        int size;
    public:
        Lista();
        void addLast(int data);
        void addFirst(int data);
        bool deleteData(int data);
        bool deleteAt(int ix);
        int getData(int ix);
        int findData(int data);
        int updateData(int val);
        int getSize(){return size;};
        bool isEmpty(){return size==0;};
        void printList();
        ~Lista();
};

Lista::Lista(){
    cout<<"Lista Creada\n";
    head=nullptr;
    size=0;
}
void Lista::addLast(int data){
    //Esta vacia?
    if(isEmpty()){
        head=new Node(data);
    }
    else{
        Node* aux=head;
        while(aux->next!=nullptr){
            aux=aux->next;
        }
        aux->next=new Node(data);
    }
    size++;
}
void Lista::addFirst(int data){
    if(size==0){
        head=new Node(data);
    }
    else{
        Node* aux=new Node(data);
        aux->next=head;
        head=aux;
    }
    size++;
}
bool Lista::deleteData(int data){
    bool exito=false;
    if (size>0){
        Node* aux = head;
        Node* aux2 = aux; // apuntador que va un nodo atrás
        int index=0;
        while (aux->data!= data && index<size){
            aux2 = aux;
            aux = aux->next;
            index++;
        }
        if (aux->data==data){
            if (aux==head) head = aux->next; // si es el primer elemento de la lista
            aux2->next = aux->next;
            delete aux;
            size--;
            exito = true;
        } else exito = false;
    }
    else exito = false;
    return exito;
}
bool Lista::deleteAt(int ix){
    bool exito=false;
    if(size>0){
        Node* aux = head;
        Node* aux2 = aux; // apuntador que va un nodo atrás
        int index=1;
        while (index!=ix && index<size){
            aux2 = aux;
            aux = aux->next;
            index++;
        }
        if (index==ix){
            if (aux==head) head = aux->next; // si es el primer elemento de la lista
            aux2->next = aux->next;
            delete aux;
            size--;
            exito = true;
        } else exito = false;
    }
    else exito = false;
    return exito;
}
int Lista::getData(int ix){
    Node* aux = head;
    Node* aux2 = aux; // apuntador que va un nodo atrás
    int index=1;
    if(ix>size){
        throw out_of_range("El indice es mayor al que existe");
    }
    while (index!=ix && index<size){
        aux2 = aux;
        aux = aux->next;
        index++;
    }
    return aux->data;
}
int Lista::findData(int data){
    Node* aux = head;
    Node* aux2 = aux; // apuntador que va un nodo atrás
    int index=1;
    if(index>size){
        throw out_of_range("El indice es mayor al que existe");
    }
    while (aux->data!= data && index<size){
        aux2 = aux;
        aux = aux->next;
        index++;
    }
    return index;
}
void Lista::printList(){
    if(size>0){
        Node* aux=head;
        while(aux->next!=nullptr){
            cout<<aux->data<<"\n";
            aux=aux->next;
        }
        cout<<aux->data;
    }
    else{
        cout<<"Lista Vacia\n";
    }
}

int Lista::updateData(int val){
    bool find = false;
    Node* aux;
    aux = head;

    for(int i = 0; i < size; i++){
        if(aux -> data == val){
            cout << "El numero " << val << " esta en la posicion de " << i << endl;
            cout << "Ingresa el nuevo valor que deseas en la posicion " << endl;
            cin >> aux->data;
            cout << "Valor cambiado";
            find = true;
        }
        aux = aux->next;
    }
    if(find==false){
        cout << "Elemento no existente en la lista " << endl;
    }

}
Lista::~Lista(){}