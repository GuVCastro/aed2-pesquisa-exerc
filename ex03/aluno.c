#include <stdio.h>
#include "aluno.h"

void printAluno(Aluno a)
{
	printf("{ \"Matricula\": %d, \"Nome\": %s }\n", a.matricula, a.nome);
}
