#include <stdio.h>
#include "arquivo.h"
 
void produtoEstoqueImprime(produtoEstoque produto){
    printf("Identificador :%d, Nome: %s, Descricao: %s, Preco, %.2f\n",produto.id,produto.nome,produto.descricao,produto.preco);
}

int produtoEstoqueBusca(FILE* arq, int indice){

    long int posicaoOriginal = ftell(arq);
    long int deslocamento;
    produtoEstoque aux;

    deslocamento = ftell(arq);
    while (fread(&aux, sizeof(produtoEstoque), 1, arq) != 0){
        if (aux.id == indice){
            fseek(arq,posicaoOriginal,SEEK_SET);
            return deslocamento;
        }
        deslocamento = ftell(arq);
    }
    fseek(arq, posicaoOriginal, SEEK_SET);
    return -1;
}

int produtoEstoqueMaiorQue(FILE *arq, int preco){
    long int posicaoOriginal = ftell(arq);
    int resultado = 0;
    produtoEstoque aux;

    while (fread(&aux, sizeof(produtoEstoque), 1, arq) != 0){
        if(aux.preco > preco)
            resultado++;
    }
    fseek(arq, posicaoOriginal, SEEK_SET);
    return resultado;
}