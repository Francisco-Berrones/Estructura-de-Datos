//David Treviño Camarillo #624996
//Francisco Ariel Berrones Gomez #625824
//Luis Guillermo Roman Escalera #624618
class NodeAnimal{
    public:
        string txt;
        NodeAnimal* izq;
        NodeAnimal* der;
};

NodeAnimal *nN, *raiz, *inicia;
void pregunta(NodeAnimal* root, NodeAnimal* prev);
void leer(NodeAnimal*& root, fstream& file);
void update(NodeAnimal* fin, NodeAnimal*& prefin);
void ultimaPregunta(NodeAnimal* root, NodeAnimal* prev);

void pregunta(NodeAnimal* root, NodeAnimal* prev){
    string resp;
    if(root->izq!=NULL && root->der!=NULL){
        cout<<root->txt<<endl;
        cin>>resp;
        if(resp=="si" || resp=="SI" || resp=="Si"){
            pregunta(root->izq, root);
        }
        else if(resp=="no" || resp=="NO" || resp=="No"){
            pregunta(root->der, root);
        }
        else{
            cout<<"Opcion invalida\n";
            pregunta(root, prev);
        }
    }
    else{
        ultimaPregunta(root, prev);
    }
}
void leer(NodeAnimal*& root, fstream& file){
    string str;
    if(!file.eof()){
        getline(file, str);
        cin.clear();
    }
    else{
        return;
    }
    if(str!="#"){
        root=new NodeAnimal;
        root->txt=str;
        leer(root->izq, file);
        leer(root->der, file);
    }
    else{
        root=NULL;
    }
}
void escribir(NodeAnimal*& root, fstream& file){
    if(root==NULL){
        file<<"#"<<endl;
    }
    else{
        file<<root->txt<<endl;
        escribir(root->izq, file);
        escribir(root->der, file);
    }
}
void update(NodeAnimal* fin, NodeAnimal*& prefin){
    string ans, preg;
    cout<<"Vaya, me he equivocado :(\n";
    cout<<"Cual es el animal?\n";
    cin.ignore();
    getline(cin, ans);
    cout<<"Cual es una pregunta devuelva a tu animal para si, y devuelva "<<fin->txt<<" para no\n";
    getline(cin, preg);
    NodeAnimal *nResp, *nPreg;
    nResp = new NodeAnimal;
    nResp->txt = ans;
    nResp->izq = NULL;
    nResp->der = NULL;
    nPreg = new NodeAnimal;
    nPreg->txt = preg;
    nPreg->izq = nResp;
    nPreg->der = fin;
    if(prefin->izq==fin){
        prefin->izq=nPreg;
    }
    else if(prefin->der==fin){
        prefin->der=nPreg;
    }
    fstream archivo;
    archivo.open("Data.txt", ios::out);
    escribir(inicia, archivo);
    cout<<"Modificado con exito\n";
    string resp;
    cout<<"Quieres volver a jugar?\n";
    cin>>resp;
    if(resp=="si" || resp=="SI" || resp=="Si"){
        cout<<"Reiniciando...\n";
        system("CLS");
        pregunta(inicia, NULL);
    }
    else if(resp=="no" || resp=="NO" || resp=="No"){
        cout<<"Gracias por jugar\n";
    }
    system("pause");
}
void ultimaPregunta(NodeAnimal* root, NodeAnimal* prev){
    string resp;
    cout<<"Tu animal es "<<root->txt<<"?\n";
    cin>>resp;
    if(resp=="si" || resp=="SI" || resp=="Si"){
        cout<<"Bien! He adivinado\n";
        cout<<"Gracias por jugar\n";
        cout<<"Quieres jugar otra vez?\n";
        cin>>resp;
        if(resp=="si" || resp=="SI" || resp=="Si"){
            cout<<"Reiniciando...\n";
            system("CLS");
            pregunta(inicia, prev);
        }
        else if(resp=="no" || resp=="NO" || resp=="No"){
            cout<<"Gracias por jugar\n";
        }
    }
    else if(resp=="no" || resp=="NO" || resp=="No"){
        update(root, prev);
    }
    else{
        cout<<"Opcion INvalida\n";
        ultimaPregunta(root, prev);
    }
}