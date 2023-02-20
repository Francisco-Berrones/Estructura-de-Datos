class Node{
friend class Lista;
public:
 Node(int e){
   data = e;
   next = nullptr;
 }
private:
  int data;
  Node *next;
};