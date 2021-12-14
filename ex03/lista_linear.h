#include "aluno.h"

#define MAX 16

typedef struct Lista {
	Aluno dado[MAX];
	int tam;
} Lista;

void newLista(Lista *l);

void inserir(Lista *l, Aluno a);

Aluno remover(Lista *l, int matricula);

void printLista(Lista *l);

void ordenar(Lista *l);

void converterParaVetor(Lista *l, Aluno *v);

