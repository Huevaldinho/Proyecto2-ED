#ifndef CIELO_H
#define CIELO_H

#include "Estructuras.h"
class Cielo{
    public:
        QVector<ArbolCielo *> hash;//array de arboles balanceados que tienen personas
        Infierno * infierno;

        Cielo();
        Cielo(Infierno *);
        int funcionHash(int ID);
};

#endif // CIELO_H
