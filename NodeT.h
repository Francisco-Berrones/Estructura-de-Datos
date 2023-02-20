#include <iostream>
using namespace std;
class NodeT{ 
    private:
        int data;
        NodeT *left, *right;
    public:
        NodeT(int d);
        NodeT(int d, NodeT* leftp, NodeT* rightp);
};

NodeT::NodeT(int d){ 
    data = d; 
    left = nullptr; 
    right= nullptr;
}

NodeT::NodeT(int d, NodeT* leftp, NodeT* rightp){
    data = d;
    left = leftp;
    right = rightp;
}