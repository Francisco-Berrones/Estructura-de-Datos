#include <iostream>
#include "NodeT.h"

class BST{
    private:
        NodeT *root;
    public:
        int children(NodeT *aux);
        BST() {root = nullptr;}; //Constructor
        void insert(NodeT data); //Insertar
        int Remove(int data);
        bool search(int data);

};


int BST::Remove(int data){
    NodeT *aux = root;
    if(data == aux->data){ //Caso del dato en la root
        switch (children(aux)){ 
            case 0:
                root = nullptr;
                delete aux;
                break;

            case 1:
                if(aux->left !=nullptr){
                    root = aux->left;
                }else {
                    root = aux->right;
                }
                delete aux;
                break;
            
            case 2:
                NodeT *aux2 = aux->left;
                while (aux2->right != nullptr){
                    aux = aux2;
                    aux2= aux->right;
                }
        }
    } 

}

int BST::children(NodeT *aux){
    if(aux->left == nullptr && aux-right == nullptr){
        return 0;
    }else{
        if(aux->left != nullptr && aux->right == nullptr){
            return 2;
        }else{
            return 1;
        }
    }
}


bool BST::search(int data){
    NodeT *aux = root;
    while(aux!=nullptr){
        if(aux->data == d){
            return true;
        }
        else if(aux->data > d){
            aux = aux->left;
        }
        else{
            aux = aux->right;
        }
    }
    return false;

}

void BST::insert(int d){
    if(!search(d)){
        NodeT *aux=root, *auxPrev = root;
        while(aux !=nullptr){
            auxPrev = aux;
            if(d < aux->data){
                aux = aux->left;
            }
            else{
                aux = aux->right;

            }
        }
        if(d < auxPrev->data){
            auxPrev->left = new NodeTT(d);
        }else{
            auxPrev->right = new NodeTT(d);
        }
    }
}