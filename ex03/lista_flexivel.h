#include "aluno.h" 

typedef struct Celula {
	Aluno dado;
	struct Celula *prox;
} Celula;

typedef struct Lista {
	Celula *primeiro;
	Celula *ultimo;
	int tam;
} Lista;

void newLista(Lista *l);

void inserir(Lista *l, Aluno a);

Aluno remover(Lista *l, int matricula);

void printLista(Lista *l);

void ordenar(Lista *l);

void converterParaVetor(Lista *l, Aluno *v);

