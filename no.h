#ifndef NO_H
#define NO_H

#include "item.h"

class No {
    public:
        No(Item *item) 
            : m_reg(item) {
                esq = NULL;
                dir = NULL;
        }
        virtual ~No() {
            //delete m_reg;
            //delete esq;
            //delete dir;
        }
        Item* getItem() {return m_reg;}
        No* getEsq() {return esq;}
        No* getDir() {return dir;}
        void setEsq (No* no) {this->esq = no;}
        void setDir (No* no) {this->dir = no;}
    private:
        Item *m_reg;
        No *esq, *dir;
};

#endif
