#include <stdio.h>
#include <string.h>
#include "aluno.h"

int pesquisarSeq(Aluno *v, char *nome, int n)
{
	for (int i = 0; i < n; i++) 
		if (strcmp(v[i].nome, nome) == 0)
			return v[i].matricula;

	return -1;
}

