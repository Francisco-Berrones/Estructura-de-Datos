class NodoArbol{
    friend class BST;
    private:
        int data;
        NodoArbol *izq, *der, *prev;
};

class BST{
    private:
        NodoArbol *raiz=NULL;
    public:
        NodoArbol *crearNodo(int d, NodoArbol *p){
            NodoArbol *newNode= new NodoArbol();
            newNode->data=d;
            newNode->der=NULL;
            newNode->izq=NULL;
            newNode->prev=p;
            return newNode;
        }
        bool existe(NodoArbol *a, int d){
            if(a==NULL){
                return false;
            }
            else if(a->data==d){
                return true;
            }
            else if(d<a->data){
                return existe(a->izq, d);
            }
            else{
                return existe(a->der, d);
            }
        }
        void insert(NodoArbol *&a, int d, NodoArbol *p){
            if(!existe(a, d)){
                if(a==NULL){
                    NodoArbol *newNode=crearNodo(d, p);
                    a=newNode;
                }
                else{
                    int valRaiz=a->data;
                    if(d<valRaiz){
                        insert(a->izq, d, a);
                    }
                    else{
                        insert(a->der, d, a);
                    }
                }
            }
            else{
                cout<<"No se pueden repetir datos\n";
            }
        }
        void mostrarArbol(NodoArbol *a, int j){
            if(a==NULL){
                return;
            }
            else{
                mostrarArbol(a->der, j+1);
                for(int i=0;i<j;i++){
                    cout<<"   ";
                }
                cout<<a->data<<"\n";
                mostrarArbol(a->izq, j+1);
            }
        }
        void preOrden(NodoArbol *a){
            if(a==NULL){
                return;
            }
            else{
                cout<<a->data<<" - ";
                preOrden(a->izq);
                preOrden(a->der);
            }
        }
        void inOrden(NodoArbol *a){
            if(a==NULL){
                return;
            }
            else{
                inOrden(a->izq);
                cout<<a->data<<" - ";
                inOrden(a->der);
            }
        }
        void postOrden(NodoArbol *a){
            if(a==NULL){
                return;
            }
            else{
                postOrden(a->izq);
                postOrden(a->der);
                cout<<a->data<<" - ";
            }
        }
        int niveles(NodoArbol *a){
            if(a!=NULL){
                int left=niveles(a->izq)+1;
                int right=niveles(a->der)+1;
                if(left>right){
                    return left;
                }
                else{
                    return right;
                }
            }
        }
        void levelXlevel(NodoArbol *a, int ni){
            if(a==NULL){
                return;
            }
            else{
                if(ni==0){
                    cout<<a->data<<" ";
                }
                else{
                    levelXlevel(a->izq, ni-1);
                    levelXlevel(a->der, ni-1);
                }
            }
        }
        void visit(){
            int op;
            cout<<"\tEliga una opcion\n";
            cout<<"1) PreOrden\n2) InOrden\n3) PostOrden\n4) Level x Level\n5) Volver\n";
            cin>>op;
            switch (op){
            case 1:
                preOrden(raiz);
                cout<<"\n";
                system("pause");
                break;
            case 2:
                inOrden(raiz);
                cout<<"\n";
                system("pause");
                break;
            case 3:
                postOrden(raiz);
                cout<<"\n";
                system("pause");
                break;
            case 4:
                for(int i=0;i<niveles(raiz);i++){
                    cout<<"Nivel: "<<i<<"\n";
                    levelXlevel(raiz, i);
                    cout<<"\n";
                }
                system("pause");
                break;
            case 5:
                menu();
                break;
            default:
                cout<<"Opcion Invalida\n";
                break;
            }
        }
        NodoArbol *minimo(NodoArbol *a){
            if(a==NULL){
                return NULL;
            }
            if(a->izq){
                return minimo(a->izq);
            }
            else{
                return a;
            }
        }
        void reemplazar(NodoArbol *a, NodoArbol *nn){
            if(a->prev){
                if(a->data==a->prev->izq->data){
                    a->prev->izq=nn;
                }
                else if(a->data==a->prev->der->data){
                    a->prev->der=nn;
                }
            }
            if(nn){
                nn->prev=a->prev;
            }
        }
        void destruir(NodoArbol *a){
            a->izq=NULL;
            a->der=NULL;
            delete a;
        }
        void removeNode(NodoArbol *a){
            if(a->izq && a->der){
                NodoArbol *menor=minimo(a->der);
                a->data=menor->data;
                removeNode(menor);
            }
            else if(a->izq){
                reemplazar(a, a->izq);
                destruir(a);
            }
            else if(a->der){
                reemplazar(a, a->der);
                destruir(a);
            }
            else{
                reemplazar(a, NULL);
                destruir(a);
            }
        }
        void remove(NodoArbol *a, int d){
            if(a==NULL){
                return;
            }
            else if(d<a->data){
                remove(a->izq, d);
            }
            else if(d>a->data){
                remove(a->der, d);
            }
            else{
                removeNode(a);
            }
        }
        int hasta(NodoArbol *a, int d, int& h){
            if(a==NULL){
                return -1;
            }
            int hizq=hasta(a->izq, d, h);
            int hder=hasta(a->der, d, h);
            int ans=max(hizq, hder)+1;
            if(a->data==d){
                h=ans;
            }
            return ans;
        }
        int height(NodoArbol *a, int d){
            int h=-1;
            int max=hasta(a, d, h);
            return h;
        }
        int whatLevelAmI(NodoArbol *a, int d){
            if(a==NULL){
                return -1;
            }
            int dist=-1;
            if((a->data==d) || (dist=whatLevelAmI(a->izq, d)) >=0 || (dist=whatLevelAmI(a->der, d)) >=0){
                return dist+1;
            }
            return dist;
        }
        bool ancestors(NodoArbol *a, int d){
            if(a==NULL){
                return false;
            }
            if(a->data==d){
                return true;
            }
            bool l=ancestors(a->izq, d);
            bool r=false;
            if(!l){
                r=ancestors(a->der, d);
            }
            if(l||r){
                cout<<a->data<<" ";
            }
            return l||r;
        }
        void menu(){
            int dato, opcion, contador=0;
            do{
                cout<<"\tMENU\n";
                cout<<"1) Insertar un Nodo\n2) Mostrar Arbol\n3) Visita\n4) Eliminar un nodo\n5) Altura\n6) Nivel\n7) Ancestros\n8) Salir\n";
                cout<<"Opcion: ";
                cin>>opcion;
                switch (opcion){
                case 1:
                    cout<<"Cual es el dato?\n";
                    cin>>dato;
                    insert(raiz, dato, NULL);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    mostrarArbol(raiz, contador);
                    cout<<"\n";
                    system("pause");
                    break;
                case 3:
                    visit();
                    break;
                case 4:
                    cout<<"Que dato quiere eliminar?\n";
                    cin>>dato;
                    remove(raiz, dato);
                    cout<<"\n";
                    system("pause");
                    break;
                case 5:
                    cout<<"Que dato busca?\n";
                    cin>>dato;
                    cout<<"Altura: "<<height(raiz, dato);
                    cout<<"\n";
                    system("pause");
                    break;
                case 6:
                    cout<<"Que dato busca?\n";
                    cin>>dato;
                    cout<<"Nivel: "<<whatLevelAmI(raiz, dato);
                    cout<<"\n";
                    system("pause");
                    break;
                case 7:
                    cout<<"Que dato busca?\n";
                    cin>>dato;
                    cout<<"Ancestros: ";
                    ancestors(raiz, dato);
                    cout<<"\n";
                    system("pause");
                    break;
                default:
                    cout<<"Opcion Invalida\n";
                    break;
                }
                system("cls");
            }while(opcion!=8);
        }
};