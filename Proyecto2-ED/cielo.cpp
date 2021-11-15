#include "cielo.h"

Cielo::Cielo(){
    this->hash.resize(1001);
}
Cielo::Cielo(Infierno * _infierno){
    this->infierno=_infierno;
    this->hash.resize(1001);//1-1000, el 0 no se usa
    this->hash[0]=NULL;//El primero no se usa
    for (int i=1;i<1001;i++){
        this->hash[i] = new ArbolCielo();//Crea los arboles para cada bucket del hash, en estos
        //en los arboles del hash se van a meter las personas salvadas por los angeles
    }
}
int Cielo::funcionHash(int ID){
    int rango=0;
    //100x1000=100 000 personas en rangos de 100
    //se le suma 1 porque la primera posicion del hash no se usa
    rango = (ID/100)+1;//tenemos  99 999 (100 000) personas como maximo
    //se hace 100 000 entre 100 posiciones del arreglo para determinar el indice
    //para insertar
    return rango;
}
void Cielo::mostrarCielo(){
    //Mandar a hacer el .txt
    for(int i=1;i<1001;i++){
          this->hash[i]->escribirEnArchivoInorden(this->hash[i]->raiz,this->archivoCielo,i);
      }
}
