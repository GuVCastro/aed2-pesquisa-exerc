#include <stdio.h>
#include "aluno.h"

char *pesqBinariaRec(Aluno *v, int esq, int dir, int x)
{
	if (dir >= esq) {
		int meio = esq + (dir - esq) / 2;

		if (v[meio].matricula == x) {
			char *res = v[meio].nome; 
			return res;
		}

		if (v[meio].matricula > x) 
			return pesqBinariaRec(v, esq, meio - 1, x);

		return pesqBinariaRec(v, meio + 1, dir, x);
	}

	char res[] = "\0";
	char *res2 = res;
	return res2;
}

