#include "TAD_Pilha.h"

//Função para criar nossa pilha.
void Cria(Pilha *P){
    P->topo = -1;
};

//Função que checa se a pilha está vazia;
bool Vazia(Pilha *P){
    if(P->topo == -1){
        return true;
    }
    else{
        return false;
    }
};

//Função que checa se a pilha está cheia;
bool Cheia(Pilha *P){
    if(P->topo == MAX - 1){
        return true;
    }
    else{
        return false;
    }
};

//Função para empilhar um novo número na pilha;
void Empilha(Pilha *P, int x, bool *result){
    //Pilha esta cheia -> Não posso empilhar mais
    if(Cheia(P)){
        *result = false;
    }
    else{
        P->topo += 1;
        P->elementos[P->topo] = x;
        *result = true;
    }
};

//Função para desempilhar um número da pilha;
void Desempilha(Pilha *P, int *x, bool *result){
    if(Vazia(P)){
        *result = false;
    }
    else{
        *x = P->elementos[P->topo];
        P->topo -= 1;
        *result = true;
    }
};//
// Created by moral on 27/01/2022.
//

