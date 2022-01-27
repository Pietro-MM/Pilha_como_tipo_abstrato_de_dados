/*
    NOME: PIETRO MINGHINI MORALLES
    RA: 792238
    DISCIPLINA: Algoritmos e Estruturas de Dados 1
    EXERCICIO: F2 - TAD Pilha: implementação, teste e aplicação.
    DESCRIÇÃO: ARQUIVO PARA TESTAR O TAD_PILHA
*/

#include <stdbool.h>

#define MAX 3 //Definimos o tamanho máximo da nossa pilha

typedef struct {
    int topo;
    int elementos[MAX];
}Pilha;

//Função para criar nossa pilha.
void Cria(Pilha *P);

//Função que checa se a pilha está vazia;
bool Vazia(Pilha *P);

//Função que checa se a pilha está cheia;
bool Cheia(Pilha *P);

//Função para empilhar um novo número na pilha;
void Empilha(Pilha *P, int x, bool *result);

//Função para desempilhar um número da pilha;
void Desempilha(Pilha *P, int *x, bool *result);