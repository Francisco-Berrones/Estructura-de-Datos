#include "iostream"
using namespace std;
#include "vector"
#include "act.h"

int main(){
Lista<double> listaDoubles;
Lista<int> listaEnteros;
Lista<string> listaString;
int i;
for (i = 62; i < 68; i++)
listaDoubles.agrega(i/10.0);
for (i = 0; i < 5; i++)
listaEnteros.agrega(i);
if (listaEnteros.agrega(3)) {
cout << "se pudo agregar el 3 " << endl;
}
else {
cout << "no se pudo agregar el 3 " << endl;
}

cout<<"Los elementos de la lista de enteros son:"<<endl;
for (int i = 0; i < listaEnteros.getSize(); i++)
cout<<listaEnteros.getElem(i)<<endl;
cout<<"Los elementos de la lista de doubles son:"<<endl;
for (int i = 0; i < listaDoubles.getSize(); i++)
cout<<listaDoubles.getElem(i)<<endl;

try {
listaString.agrega("Hola");
listaString.agrega("soy");
listaString.agrega("Lola");
for (int i = 0; i < listaString.getSize(); i++)
cout<<listaString.getElem(i)<<endl;
} catch(out_of_range& e) {
cout << e.what() << endl;
}

return 0;

}