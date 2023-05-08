// -- Trabalho de AED2 - Arvore Binaria sem balanceamento --
// Aluno : Samuel Correa Lucas Pereira

#include <time.h>
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <chrono>

#include"arvoreBinaria.h"
#include"item.h"
#include"no.h"

int main (int argc, char* argv[]) {

    ArvoreBinaria arv1;
    Item* reg = new Item(10000);

    std :: cout << "-- Arvore ordenada --" << std::endl << std::endl;
    for(int i = 1000; i <= 9000; i = i + 1000){
        reg = new Item(i);
        arv1.insere(reg, arv1.raiz);

        reg = new Item(9100);

        auto inicio = std::chrono::high_resolution_clock::now();
        arv1.pesquisa(reg, arv1.raiz);
        auto resultado = std::chrono::high_resolution_clock::now() - inicio;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

        std :: cout << "i = " << i/1000 << " // tempo = " << microseconds << std::endl;
    }

    std :: cout  << std::endl << std::endl;

    srand((unsigned)time(0)); 
    ArvoreBinaria arv2;
    int randon;

    std :: cout << "-- Arvore aleatória --" << std::endl << std::endl;

    for(int i = 1; i <= 9; i++){

        randon = ((rand()%9)+1)*1000;
        reg = new Item(randon);
        arv2.insere(reg, arv2.raiz);

        reg = new Item(9100);

        auto inicio = std::chrono::high_resolution_clock::now();
        arv2.pesquisa(reg, arv2.raiz);
        auto resultado = std::chrono::high_resolution_clock::now() - inicio;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
        std :: cout << "i = " << i << " // tempo = " << microseconds << std::endl;
    }
    return 0;
}