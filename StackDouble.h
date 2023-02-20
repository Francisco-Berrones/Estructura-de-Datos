class NodeStack{
    friend class StackDouble;
    private:
        NodeStack *next;
        double data;
};

//David Treviño Camarillo #624996
//Luis Guillermo Roman Escalera #624618
//Francisco Ariel Berrones Gomez #625824

class StackDouble{
    private:
        int tamMax, tam;
        NodeStack *head;                                    //Head siempre es nulo, sirve como guia
    public:
        StackDouble(int max=100);                                 //Tamaño maximo predeterminado 100
        int getSize();
        bool isEmpty();
        double top();
        void push(double dato);
        double pop();
        void clear();
        void printStack();
        ~StackDouble();
};
StackDouble::StackDouble(int max){                                      //Pasamos el tamaño maximo como parametro, sino, será 100
    cout<<"Pila Creada\n";
    head=new NodeStack;
    head->next=nullptr;
    tamMax=max;
    tam=0;
}
int StackDouble::getSize(){                                       //Devuelve el tamaño actual de la pila, no el tamaño maximo
    return tam;
}
bool StackDouble::isEmpty(){                                      //Devuelve true si el tamaño actual es 0, false si no
    return(tam==0);
}
double StackDouble::top(){                                           //Devuelve el dato de la primera posición de la pila, almacenada en el next de head
    if(!isEmpty()){                                         //Solo lo devuelve si no esta vacia
        return head->next->data;
    }
    else{
        throw out_of_range("No hay datos en la pila");      //Si esta vacia no puede devolver nada
    }
}
void StackDouble::push(double dato){                                 //Agrega un dato en la primera posicion de la pila, despues de head
    if(tam<tamMax){
        NodeStack *aux=new NodeStack;                       //Crear el nuevo nodo que vamos a agregar
        aux->data=dato;                                     //Guarda el dato que pasamos por parametro
        aux->next=head->next;                               //El apuntador next de nuestro nuevo nodo será el apuntador next de head
        head->next=aux;                                     //Actualizamos el apuntador next de head para que apunte a nuestro nuevo nodo
        tam++;                                              //Aumenta el tamaño
    }
    else{
        throw out_of_range("No se pueden agregar mas datos"); //Si la pila esta llena no lo puede agregar
    }
}
double StackDouble::pop(){                                           //Elimina el nodo de la primera posicion despues de head
    double x;                                                  //Guarda el valor que se borra para luego devolverlo
    if(!isEmpty()){         
        NodeStack *aux=head->next->next;                    //Nodo auxiliar que apunta al nodo de la segunda posición de la pila
        x=head->next->data;                                 
        delete head->next;                                  //Borra el nodo siguiente a head
        head->next=aux;                                     //El apuntador next de head ahora será nuestro nodo auxiliar, que ahora pasa a la prmera posición
        tam--;                                              //Reducimos el tamaño
        return x;
    }
    else{
        throw out_of_range("La pila esta vacia");           //Si la pila esta vacia, no puede quitar nada
    }
}
void StackDouble::clear(){                                        //Elimina todos los datos de la pila
    while(!isEmpty()){
        pop();                                              //Utiliza la funcion pop mientras no esté vacia
    }
    cout<<"Pila Vacia";
}
void StackDouble::printStack(){                                   //Muestra todos los elementos de la pila
    if(tam>0){
        NodeStack* aux=head->next;
        while(aux->next!=nullptr){
            cout<<aux->data<<"\n";
            aux=aux->next;
        }
        cout<<aux->data;
    }
    else{
        cout<<"Pila Vacia\n";
    }
}

StackDouble::~StackDouble(){                                            //Destructor
    delete head;
}

//"Doy mi palabra de que hemos realizado esta actividad con integridad academica"