#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include "item.h"
#include "no.h"

class ArvoreBinaria {
    public:
        ArvoreBinaria();
        virtual ~ArvoreBinaria();
        No *insere(Item *reg, No* p);
        Item *pesquisa(Item* reg, No* p);
        No* raiz;
    //private:
        //void deleteNo(No* p);
};

#endif
