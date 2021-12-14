#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "lista_linear.h"
#include "lista_flexivel.h"
#include "pesqSequencial.h"
#include "pesqBinaria.h"

void preenchePadroes(Lista *l)
{
	
	Aluno a[5] = {	{123452, "ana"},
					{543215, "maria"},
					{234564, "jose"},
					{654322, "rodolfo"},
					{567893, "mario"}
	};

	for (int i = 0; i < 5; i++)
		inserir(l, a[i]);
}

int main(void)
{
	int opcao = 1, res;
	Lista l;

	newLista(&l);
	
	preenchePadroes(&l);
	Aluno *v = malloc(l.tam*sizeof(Aluno));
	int n = l.tam;

	ordenar(&l);

	printf("Executar pesquisa binária(0) ou sequencial(1)? "); scanf("%d", &opcao); 

	if (opcao == 1) {
		converterParaVetor(&l, v);

		char nome[] = "rodolfo";
		printf("Nome pesquisado: %s\n", nome);

		res = pesquisarSeq(v, nome, n);
		(res == -1)	? printf("Resultado nao encontrado\n")
					: printf("Matricula encontrada: %d\n", res);
	}
	else {
		converterParaVetor(&l, v);

		int matricula = 654322;
		printf("Matricula pesquisada: %d\n", matricula);

		char res2[50];
		strcpy(res2, pesqBinariaRec(v, 0, n - 1, matricula)); 

		(strcmp(res2, "") == 0)	? printf("Resultado nao encontrado\n")
								: printf("Nome encontrado: %s\n", res2);
	}

	return 0;
}

