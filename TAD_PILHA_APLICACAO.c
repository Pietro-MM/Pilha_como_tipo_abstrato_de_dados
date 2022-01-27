/*
    NOME: PIETRO MINGHINI MORALLES
    RA: 792238
    DISCIPLINA: Algoritmos e Estruturas de Dados 1
    EXERCICIO: F2 - TAD Pilha: implementação, teste e aplicação.
    DESCRIÇÃO: Algoritmo criado para testar os conhecimentos adquiridos em TAD e Pilhas, de modo a implementar um TAD de
    pilha.
*/

#include <stdio.h>
#include "TAD_Pilha.h"

void retornaValorTopo(Pilha *P, int *x, bool *result);
void retornaNumElem(Pilha *P, int *x, bool *result);
void imprimePilha(Pilha *P);

int main(){
    Pilha pilha1;
    int op = 15, valor;//A variavel valor é utilizada para armezenar diferentes dados, dependendo da opção selecionada
    bool resultado;

    while(op != 0){
        printf("---------- MENU ----------\n"
               "Digite 1 para Criar a Pilha\n"
               "Digite 2 para verificar se a Pilha esta vazia\n"
               "Digite 3 para verificar se a Pilha esta cheia\n"
               "Digite 4 para empilhar um elemento na Pilha\n"
               "Digite 5 para desempilhar um elemento da Pilha\n"
               "Digite 6 para obter o valor do topo da pilha\n"
               "Digite 7 para obter a quantidade de elementos na pilha\n"
               "Digite 8 para imprimir a pilha.\n"
               "Digite 0 para encerrar o programa\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                Cria(&pilha1);
                break;
            case 2:
                if(Vazia(&pilha1)){
                    printf("Pilha vazia.\n");
                }
                else{
                    printf("A pilha nao esta vazia.\n");
                }
                break;
            case 3:
                if(Cheia(&pilha1)){
                    printf("Pilha cheia.\n");
                }
                else{
                    printf("A pilha nao esta cheia.\n");
                }
                break;
            case 4:
                printf("Digite o valor do elemento a ser inserido: ");
                scanf("%d", &valor);
                Empilha(&pilha1, valor, &resultado);
                if(resultado){
                    printf("O valor %d foi inserido na pilha.\n", valor);
                }
                else{
                    printf("O valor %d nao foi inserido na pilha pois ela esta cheia.\n", valor);
                }
                break;
            case 5:
                Desempilha(&pilha1, &valor, &resultado);
                if(resultado){
                    printf("O valor %d foi removido da pilha.\n", valor);
                }
                else{
                    printf("A pilha esta vazia.\n");
                }
                break;
            case 6:
                retornaValorTopo(&pilha1, &valor, &resultado);
                if(resultado){
                    printf("O valor do topo eh %d.\n", valor);
                }
                else{
                    printf("A pilha esta vazia.\n");
                }
                break;
            case 7:
                retornaNumElem(&pilha1, &valor, &resultado);
                if(resultado){
                    printf("O numero de elmentos da pilha eh %d.\n", valor);
                }
                else{
                    printf("A pilha esta vazia.\n");
                }
                break;
            case 8:
                if(Vazia(&pilha1)){
                    printf("Pilha vazia.\n");
                }
                else {
                    imprimePilha(&pilha1);
                }
                break;
            default:
                printf("Encerrando o programa\n");
                break;
        }
    }

    return 0;
}

void retornaValorTopo(Pilha *P, int *x, bool *result){
    if(Vazia(P)){
        *result = false;
    }
    else{
        *x = P->elementos[P->topo];
        *result = true;
    }
}

void retornaNumElem(Pilha *P, int *x, bool *result){
    if(Vazia(P)){
        *result = false;
    }
    else{
        *x = P->topo + 1;
        *result = true;
    }
}

void imprimePilha(Pilha *P){
    Pilha aux;
    int valor;
    bool resultado;

    Cria(&aux);
    //Desempilho a pilha atual em uma auxiliar, para poder obter todos os valores da pilha.
    while(Vazia(P) == false){
        Desempilha(P, &valor, &resultado);
        if(resultado){
            Empilha(&aux, valor, &resultado);
        }
    }
    //Desempilho a pilha auxiliar e armazeno os valores na pilha principal na ordem correta.
    while(Vazia(&aux) == false){
        Desempilha(&aux, &valor, &resultado);
        if(resultado){
            printf("%d ", valor);
            Empilha(P, valor, &resultado);
        }
    }
    printf("<----Topo da Pilha\n");
}