#include "cielo.h"

Cielo::Cielo(){
    this->hash.resize(1001);
}
Cielo::Cielo(Infierno * _infierno){
    this->infierno=_infierno;
    this->hash.resize(1001);//1-1000, el 0 no se usa
    this->hash[0]=NULL;//El primero no se usa
    for (int i=1;i<1001;i++){
        this->hash[i] = new ArbolCielo();//Crea los arboles para cada index del hash, en estos
        //en los arboles del hash se van a meter las personas salvadas
    }
}
