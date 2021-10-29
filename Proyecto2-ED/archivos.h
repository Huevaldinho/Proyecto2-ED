#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "Estructuras.h"

class Archivos{
    public:
        int contadorNombres;
        int contadorApellidos;
        int contadorProfesiones;
        int contadorCreencias;
        int contadorPaises;


        Archivos();
        void lecturaApellidos(QString *);
        void lecturaNombres(QString *);
        void lecturaPaises(QString *);
        void lecturaProfesiones(QString *);
        void lecturaCreencias(QString *);

};

#endif // ARCHIVOS_H
