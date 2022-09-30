#include "iostream"
using namespace std;

class Calificacion{
    public:
        //Metodos
        Calificacion();
        double calculaCalFinal();
        void setNombreAlumno(string _NombreAlumno);
        void setCalificacionAct(double _CalActividades);
        void setCalificacionExamen(double _CalExamen);
        void setCalificacionProyecto(double _CalProyecto);
        string getNombre(){return nombreAlumno; };
        double getCalificacionAct(){return CalActividades; };
        double getCalificacionExamen(){return CalExamen;} ;
        double getCalificacionProyecto(){return CalProyecto; };
        void Imprimir();


    private:
        //Atributos
        string nombreAlumno;
        double CalActividades;
        double CalExamen;
        double CalProyecto;
        double CalFinal;
};

//Derivacion
Calificacion::Calificacion(){
    nombreAlumno = "";
    CalActividades = 0;
    CalExamen = 0;
    CalProyecto = 0;

}

void Calificacion::setNombreAlumno(string _NombreAlumno){
    nombreAlumno = _NombreAlumno;
}   

void Calificacion::setCalificacionAct(double _CalActividades){
    CalActividades = _CalActividades;
}
void Calificacion::setCalificacionExamen(double _CalExamen){
    CalExamen = _CalExamen;
}
void Calificacion::setCalificacionProyecto(double _CalProyecto){
    CalProyecto = _CalProyecto;
}   

double Calificacion::calculaCalFinal(){
    return CalExamen*.30 + CalActividades*.40 + CalProyecto*.30;
}

//Imprimir Calificaciones
void Calificacion::Imprimir(){
  cout << nombreAlumno << " examen " << CalExamen << " actividades " << CalActividades << " proyecto " << CalProyecto << " Calificacion final " << calculaCalFinal() << endl;
}