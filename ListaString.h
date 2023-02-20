#include <ostream>
using namespace std;
#include "NodeString.h"

//David Treviño Camarillo #624996
//Francisco Ariel Berrones Gomez #625824
//Luis Guillermo Roman Escalera #624618

class ListaString{
    private:
        NodeString *head;
        int size;
    public:
        ListaString();
        void addLast(string data);
        void addFirst(string data);
        bool deleteData(string data);
        bool deleteAt(int ix);
        string getData(int ix);
        int findData(string data);
        void updateAt(int ix, string newData);
        void updateData(string val, string newData);
        int getSize(){return size;};
        bool isEmpty(){return size==0;};
        void printList();
        ~ListaString();
};

ListaString::ListaString(){
    cout<<"Lista Creada\n";
    head=nullptr;
    size=0;
}
void ListaString::addLast(string data){
    //Esta vacia?
    if(isEmpty()){
        head=new NodeString(data);
    }
    else{
        NodeString* aux=head;
        while(aux->next!=nullptr){
            aux=aux->next;
        }
        aux->next=new NodeString(data);
    }
    size++;
}
void ListaString::addFirst(string data){
    if(size==0){
        head=new NodeString(data);
    }
    else{
        NodeString* aux=new NodeString(data);
        aux->next=head;
        head=aux;
    }
    size++;
}
bool ListaString::deleteData(string data){
    bool exito=false;
    if (size>0){
        NodeString* aux = head;
        NodeString* aux2 = aux; // apuntador que va un nodo atrás
        int index=1;
        while (aux->dato!= data && index<size){
            aux2 = aux;
            aux = aux->next;
            index++;
        }
        if (aux->dato==data){
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
bool ListaString::deleteAt(int ix){
    bool exito=false;
    if(size>0){
        NodeString* aux = head;
        NodeString* aux2 = aux; // apuntador que va un nodo atrás
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
string ListaString::getData(int ix){
    NodeString* aux = head;
    NodeString* aux2 = aux; // apuntador que va un nodo atrás
    int index=1;
    if(ix>size){
        throw out_of_range("El indice es mayor al que existe");
    }
    while (index!=ix && index<size){
        aux2 = aux;
        aux = aux->next;
        index++;
    }
    return aux->dato;
}
int ListaString::findData(string data){
    NodeString* aux = head;
    NodeString* aux2 = aux; // apuntador que va un nodo atrás
    int index=1;
    if(index>size){
        throw out_of_range("El indice es mayor al que existe");
    }
    while (aux->dato!= data && index<size){
        aux2 = aux;
        aux = aux->next;
        index++;
    }
    return index;
}
void ListaString::updateAt(int ix, string newData){
    if(ix>size){
        throw out_of_range("No se pudo");
    }
    if (size>0){
        NodeString* aux = head;
        NodeString* aux2 = aux; // apuntador que va un nodo atrás
        int index=1;
        while (index!=ix && index<size){
            aux2 = aux;
            aux = aux->next;
            index++;
        }
        aux->dato=newData;
    }
}
void ListaString::updateData(string val, string newData){
    if (size>0){
        NodeString* aux = head;
        NodeString* aux2 = aux; // apuntador que va un nodo atrás
        int index=1;
        while ( aux->dato!= val && index<size){
            aux2 = aux;
            aux = aux->next;
            index++;
        }
        aux->dato=newData;
    }
}
void ListaString::printList(){
    if(size>0){
        NodeString* aux=head;
        while(aux->next!=nullptr){
            cout<<aux->dato<<"\n";
            aux=aux->next;
        }
        cout<<aux->dato;
    }
    else{
        cout<<"Lista Vacia\n";
    }
}
ListaString::~ListaString(){}

//Damos nuestra palabra de haber realizado esta actividad academica