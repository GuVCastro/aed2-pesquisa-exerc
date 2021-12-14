#define TAM_NOME 50

typedef struct Aluno {
	int matricula;
	char nome[TAM_NOME];
} Aluno;

void printAluno(Aluno a);
