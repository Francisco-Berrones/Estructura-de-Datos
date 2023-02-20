//David Treviño Camarillo #624996
//Francisco Ariel Berrones Gomez #625824
//Luis Guillermo Roman Escalera #624618

#include <iostream>
using namespace std;


class NodeQueue{
    friend class Queue;
    private:
        NodeQueue *next;
        NodeQueue *prev;
        int data;
};

class Queue{
    private:
        NodeQueue *head;
        NodeQueue *tail;
        int tam, tamMax;
    public:
        Queue(int max=100);                                       //Tamaño predeterminado de 100 valores
        int getSize();                                            
        bool isEmpty();
        int deQueue();
        void enQueue(int dato);
        int front();
        int back();
        void clear();
        void printQueue();
        ~Queue();
};
Queue::Queue(int max){                                            //Enviamos el tamaño maximo como parametro, sino será 100
    cout << "Fila Creada\n";
    head=new NodeQueue;                                           //Head y Tail siempre tendran valores nulos, nos sirven unicamente de guias
    tail=new NodeQueue;
    head->next=tail;                                              //Al momento de crear la fila el apuntador next de head será tail
    tail->prev=head;                                              //Al momento de crear la fila el apuntador previo de tail será head
    head->prev=nullptr;                                           //Los apuntaodres previo y next de head y tail respectivamente serán siempre nulos
    tail->next=nullptr;
    tam=0;
    tamMax=max;
}
int Queue::getSize(){                                             //Devuelve el tamaño actual de la fila, no el tamaño maximo
    return tam;
}
bool Queue::isEmpty(){                                            //Indica si la fila esta vacia o no
    return(tam==0);
}
int Queue::deQueue(){
    int x;                                                        //Para guardar el dato del nodo que borramos
    if(!isEmpty()){                                               //Verificar si la fila esta vacia
        NodeQueue *aux=head->next->next;                          //Apntador al segundo valor de la fila (El siguiente del siguiente de head)
        x=head->next->data;
        delete head->next;                                        //Borra el primer valor
        head->next=aux;                                           //Actualizamos el apuntador next de head hacia nuestro nodo auxiliar
        aux->prev=head;                                           //Actualizamos el apuntador previo de nuestro nodo auxiliar hacia head
        tam--;                                                    //Reducimos el tamaño
        return x;                                                 //Develve el valor eliminado
    }
    else{
        throw out_of_range("No hay datos en la fila");            //Si la fila esta vacia
    }
}
void Queue::enQueue(int dato){                                    //El dato que vamos a agregar se pasa como parametro
    if(tam<tamMax){                                               //Solo se realiza si el tamaño actual es menor al tamaño maximo
        NodeQueue *aux=new NodeQueue;                             //Creamos un nodo nuevo que vamos a agregar
        aux->data=dato;                                           //El dato del nuevo nodo sera el dato enviado por parametro
        aux->next=tail;                                           //El apuntador next del nuevo nodo será tail, y el previo será el previo de tail
        aux->prev=tail->prev;
        tail->prev->next=aux;                                     //El apuntador next del antiguo previo de tail ahora sera el nuevo nodo
        tail->prev=aux;                                           //El apuntador previo de tail será el nuevo nodo
        tam++;                                                    //Aumenta el tamaño
    }
    else{
        throw out_of_range("No se pueden agregar mas datos");     //Si el tamaño actual es mayor o igual, no se puede agregar
    }
}
int Queue::front(){                                               //Devuelve el primer valor de la fila
    if(!isEmpty()){ 
        return head->next->data;                                  //Si no esta vacia, devuelve el dato almacenado en el apuntador next de head, es decir, el primero
    }   
    else{
        throw out_of_range("No hay datos en la fila");            //Si esta vacia no lo devuelve
    }
}
int Queue::back(){                                                //Devuelve el ultimo valor de la fila
    if(!isEmpty()){
        return tail->prev->data;                                  //Si no esta vacia, devuelve el valor almacenado en el apuntador previo de tail, es decir, el ultimo
        }
    else{
        throw out_of_range("No hay datos en la fila");            //Si esta vacia no lo devuelve
    }
}
void Queue::clear(){                                              //Borra todos los datos de la fila
    while(!isEmpty()){
        deQueue();                                                //Mientras no este vacia la fila llama a la funcion deQueue
    }
}
void Queue::printQueue(){                                         //Muestra todos los datos de la fila, sin head ni tail pues son nulos
    if(tam>0){
        NodeQueue* aux=head->next;
        cout << "Lista: ";
        while(aux->next->next!=nullptr){
            cout<<aux->data<<" ";
            aux=aux->next;
        }
        cout<<aux->data;
    }
    else{
        cout<<"Lista Vacia\n";
    }
}
Queue::~Queue(){                                                  //Destructor
    delete head;
    delete tail;
}

