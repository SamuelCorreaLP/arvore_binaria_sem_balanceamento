// -- Trabalho de AED2 - Arvore Binaria sem balanceamento --
// Aluno : Samuel Correa Lucas Pereira

#include <iostream>
#include <cstdlib>
#include "arvoreBinaria.h"

ArvoreBinaria::ArvoreBinaria() {
    raiz = NULL;
}
ArvoreBinaria::~ArvoreBinaria() {
    //deleteNo(raiz);
}

//void ArvoreBinaria::deleteNo(No* p) {
    /*if(p->getEsq() != NULL) {
        deleteNo(p->getEsq());
    } 
    if(p->getDir() != NULL) {
        deleteNo(p->getDir());
    }
    delete p;*/
//}

No* ArvoreBinaria::insere(Item *reg, No *p) {
    if(raiz == NULL) {                        //se p estiver vazia, o item vai para p
        No *novoNo = new No(reg);
        raiz = novoNo;
        return novoNo;
    } else { 
        switch (p->getItem()->compara(reg)) { //compara retorna -1 se a chave de reg for menor que a chave de p, 0 se for igual e 1 se for maior
        case -1:                              //caso que reg menor que p, andamos pelo galho esquerdo
            if(p->getEsq() == NULL) {      //se o galho esquerdo estiver vazio, reg é colocado no galho esquerdo
                No *novoNo = new No(reg);
                p->setEsq(novoNo);
                return novoNo;
            } else {                          //se o galho esquerdo estiver preenchido, a funcão avança recursivamente para o proximo nó
                insere(reg, p->getEsq());
            }
            break;
        case 0:                               //se reg for igual a p, se faz nada, pois não pode ter 2 elementos iguais na arvore
            std::cout << "Erro: Registro ja existente" << std::endl;
            return raiz;
            break;
        case 1:                               //caso que reg é maior que p, andamos pelo galho direito
            if(p->getDir() == NULL) {      //se o galho direito estiver vazio, reg é colocado no galho esquerdo
                No *novoNo = new No(reg);
                p->setDir(novoNo);
                return novoNo;
            } else {                          //se o galho direito estiver preenchido, a funcão avança recursivamente para o proximo nó
                insere(reg, p->getDir());
            }
            break;
        }
    }
    return raiz;
}

Item* ArvoreBinaria::pesquisa(Item *reg, No *p) {
    std::cout << "inicio comparação" << std::endl;
    switch (p->getItem()->compara(reg)) {
    case -1:                                  //reg é menor que p, logo a pesquisa tem que avançar para esquerda
        if(p->getEsq() == NULL) {          //Nesse caso reg não existe na arvore
            std::cout << "Erro: Falha na pesquisa" << std::endl;
            return NULL;
        } else {                              //função avança recursivamente para esquerda
            pesquisa(reg, p->getEsq());
        }
        break;
    case 0:                                   //reg é igual a p, a pesquisa foi um sucesso e retorna o item do nó p
        std::cout << "Pesquisa com sucesso" << std::endl;
        return p->getItem();
        break;
    case 1:                                   //reg é maior que p, logo a pesquisa tem que avançar para direita
        if(p->getDir() == NULL) {             //Nesse caso reg não existe na arvore
            std::cout << "Erro: Falha na pesquisa" << std::endl;
            return NULL;
        } else {                              //função avança recursivamente para direita
            pesquisa(reg, p->getDir());
        }
        break;
    }
    return raiz->getItem();
}