#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_flexivel.h"

void newCelula(Celula *c, Aluno a)
{
	c->dado = a;
	c->prox = NULL;
}

void newLista(Lista *l)
{
	Celula *tmp = malloc(sizeof(Celula));
	tmp->prox = NULL;

	l->primeiro = l->ultimo = tmp;
	l->tam = 0;
}

void inserir(Lista *l, Aluno a)
{
	Celula *tmp = malloc(sizeof(Celula));
	newCelula(tmp, a);

	l->ultimo->prox = tmp;
	l->ultimo = tmp;

	tmp = NULL;
	l->tam++;
}

Aluno remover(Lista *l, int codigo)
{
	Celula *tmp = l->primeiro->prox;
	Aluno res = {0, '\0', 0};
	int flagEncontrou = 0, pos = 0;

	while(tmp != NULL) {
		if (tmp->dado.matricula == codigo) {
			flagEncontrou = 1;
			break;
		}
		pos++;
		tmp = tmp->prox;
	}

	if (flagEncontrou == 0)
		printf("NOME NAO ENCONTRADO\n");
	else {
		Celula *i = l->primeiro->prox;
		for (int j = 0; j < pos - 1; j++, i = i->prox);
		
		res = i->prox->dado;
		i->prox = i->prox->prox;	
		i = NULL;
		l->tam--;
		
		return res;
	}
}

void printLista(Lista *l)
{
	Celula *tmp;

	tmp = l->primeiro->prox;
	while(tmp != NULL) {
		printAluno(tmp->dado);
		tmp = tmp->prox;
	}
	printf("\n");
}

void ordenar(Lista *l)
{
	int i = 0, j, lSize = l->tam;
	Aluno *v = malloc(l->tam*sizeof(Aluno)), tmp2;
	Celula *tmp = l->primeiro->prox;
	
	while (tmp != NULL) {
		v[i] = tmp->dado;
		i++;
		tmp = tmp->prox;
	}

	for (i = lSize-1; i > 0; i--) 
		for (j = 0; j < i; j++) 
			if (v[j].matricula > v[j + 1].matricula) {
				tmp2 = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp2;
			}

	newLista(l);
	for (i = 0; i < lSize; i++)
		inserir(l, v[i]);

	free(v);
}

void converterParaVetor(Lista *l, Aluno *v)
{
	int i = 0;
	Celula *tmp;

	tmp = l->primeiro->prox;
	while(tmp != NULL) {
		v[i] = tmp->dado;
		i++;
		tmp = tmp->prox;
	}
}
