#include "cielo.h"

Cielo::Cielo(){
    this->hash.resize(1001);
    this->angeles=new ArbolTriario();
}
Cielo::Cielo(Infierno * _infierno){
    this->infierno=_infierno;
    this->hash.resize(1001);//1-1000, el 0 no se usa
    this->angeles=new ArbolTriario();
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
    return rango;//devuelve la posicion del arreglo donde se tiene que insertar
}
void Cielo::mostrarCielo(){//Hacer el txt del cielo
    //Mandar a hacer el .txt
    for(int i=1;i<1001;i++){
            //Esta funcion esta en arbolcielo
          this->hash[i]->escribirEnArchivoInorden(this->hash[i]->raiz,this->archivoCielo,i);
      }
}
bool Cielo::esHoja(Angel *node){
    return (node->left==NULL&&node->mid==NULL&&node->right==NULL);
}
void Cielo::salvacion(){
    hacerArreglo();
    this->angeles->crearNivel();
    this->angeles->root=salvacion(this->angeles->root);

}
void Cielo::escribirEnArchivo(Persona *persona){
    QDateTime actual = QDateTime::currentDateTime();

    QFile file(this->archivoCielo);
    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream w(&file);

        w << actual.date().toString("yyyy-MM-dd")<<" "<<actual.time().toString("hh:mm:ss") << "\t Humano "<<
             QString::number(persona->ID) <<". "<<persona->nombre<<" "<<persona->apellido<<", de "<<persona->pais<<". Salvado(a) el "<<
             actual.date().toString("yyyy-MM-dd")<<" por "<<QString::number(persona->sumaTotalPecados())<<
             " pecados vs "<<QString::number(persona->sumaTotalBuenasAcciones())<<" buenas acciones, por el ángel "<<
             persona->angel->nombre<<" ("<<QString::number(persona->angel->id)<<"), Generación: "<<QString::number(persona->angel->generacion)<<".\n";
        file.close();
    }
}
Angel * Cielo::salvacion(Angel * root){
    if (esHoja(root)){
        for (Persona * i : this->p){
            if (i!=NULL){
                if (i->estado==-1){
                    if (i->diferenciaPecadosBuenasAcciones()>0){
                        this->hash[funcionHash(i->ID)]->insert(i);//mete al hash y su AVL
                        i->estado=1; //cambia estado
                        root->persona=i; //persona al angel
                        i->angel=root; //angel a persona
                        escribirEnArchivo(i);//escribe en archivo
                    }
                }
            }
        }
    }else{
        root->left=salvacion(root->left);
        root->mid=salvacion(root->mid);
        root->right=salvacion(root->right);
    }
    return root;
}
void Cielo::hacerArreglo(){
    Nodo * tmp = this->infierno->humanosMundo->primerNodo;
    this->p.resize(this->infierno->humanosMundo->largo);
    int i=0;
    while (tmp!=NULL){
        this->p[i]=tmp->persona;
        i++;
        tmp=tmp->siguiente;;
    }
}
QVector <long long> Cielo::CantidadPecadosCielo(){
    //Contar pecados en todo el cielo
    QVector<long long> pecados;
    pecados.resize(7);
    QVector<int> pecadosTmp;
    pecadosTmp.resize(7);
    for (int i=1;i<this->hash.size();i++){
        pecadosTmp[0]=0;
        pecadosTmp[1]=0;
        pecadosTmp[2]=0;
        pecadosTmp[3]=0;
        pecadosTmp[4]=0;
        pecadosTmp[5]=0;
        pecadosTmp[6]=0;
        if (hash[i]->raiz!=NULL){
            pecadosTmp=this->hash[i]->pecadosCielo(this->hash[i]->raiz,pecadosTmp);
            pecados[0]+=pecadosTmp[0];
            pecados[1]+=pecadosTmp[1];
            pecados[2]+=pecadosTmp[2];
            pecados[3]+=pecadosTmp[3];
            pecados[4]+=pecadosTmp[4];
            pecados[5]+=pecadosTmp[5];
            pecados[6]+=pecadosTmp[6];
        }
    }
    return pecados;
}
QVector <long long> Cielo::CantidadBACielo(){
    //Contar ba en todo el cielo
    QVector<long long> ba;
    ba.resize(7);
    QVector<int> baTmp;
    baTmp.resize(7);

    for (int i=1;i<this->hash.size();i++){
        baTmp[0]=0;
        baTmp[1]=0;
        baTmp[2]=0;
        baTmp[3]=0;
        baTmp[4]=0;
        baTmp[5]=0;
        baTmp[6]=0;

        if (hash[i]->raiz!=NULL){
            baTmp = this->hash[i]->baCielo(this->hash[i]->raiz,baTmp);
            ba[0]+=baTmp[0];
            ba[1]+=baTmp[1];
            ba[2]+=baTmp[2];
            ba[3]+=baTmp[3];
            ba[4]+=baTmp[4];
            ba[5]+=baTmp[5];
            ba[6]+=baTmp[6];
        }
    }
    return ba;
}

