#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_linear.h"

void newLista(Lista *l)
{
	l->tam = 0;
}

void inserir(Lista *l, Aluno a)
{
	if (l->tam >= MAX)
		printf("LISTA CHEIA\n");
	else {
		l->dado[l->tam] = a;
		l->tam++;
	}
}

Aluno remover(Lista *l, int matricula)
{
	Aluno res = {0, '\0', 0};
	int pos = -1;

	for (int i = 0; i < l->tam; i++) {
		if (l->dado[i].matricula == matricula) {
			pos = i;
			break;
		}
	}

	if (pos == -1) {
		printf("\nNOME NAO ENCONTRADO\n\n");
		return res;
	}
	
	res = l->dado[pos];
	for (int i = pos; i < l->tam; i++) 
		l->dado[i] = l->dado[i+1];
	l->tam--;
}


void printLista(Lista *l)
{
	int i;

	for (i = 0; i < l->tam; i++)
		printAluno(l->dado[i]);
	printf("\n");
}

void ordenar(Lista *l)
{
	int i = 0, j, lSize = l->tam;
	Aluno tmp;

	for (i = lSize-1; i > 0; i--) 
		for (j = 0; j < i; j++) 
			if (l->dado[j].matricula > l->dado[j + 1].matricula) {
				tmp = l->dado[j];
				l->dado[j] = l->dado[j + 1];
				l->dado[j + 1] = tmp;
			}
}

void converterParaVetor(Lista *l, Aluno *v)
{
	for (int i = 0; i < l->tam; i++) 
		v[i] = l->dado[i];
}
