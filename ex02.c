#include <stdio.h>

int pesqBinariaRec(int *v, int esq, int dir)
{
	if (dir >= esq) {
		int meio = esq + (dir - esq) / 2;
		int res;
		
		if (v[meio] == meio) return meio;
		if (v[dir] >= meio + 1) res = pesqBinariaRec(v, meio + 1, dir);
		if (res != -1) return res;
		if (v[esq] <= meio - 1) return pesqBinariaRec(v, esq, meio - 1);
	}
	return -1;
}

int main(void)
{
	int vetOrdenado[] = {1,2,3,4,5,5,8,12,13,35};
	int n = sizeof(vetOrdenado) / sizeof(vetOrdenado[0]);

	int res = pesqBinariaRec(vetOrdenado, 0, n - 1); 
	(res == -1) ? printf("Elemento nao encontrado\n")
				: printf("Elemento encontrado no indice: %d\n", res);
	return 0;
}
