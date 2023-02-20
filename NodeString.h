class NodeString{
    friend class ListaString;
    public:
        NodeString(string e){
            dato=e;
            next=nullptr;
        }
    private:
        string dato;
        NodeString *next;
};