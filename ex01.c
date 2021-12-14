#include <stdio.h>

int pesqBinariaRec(int *v, int esq, int dir, int x)
{
	if (dir >= esq) {
		int meio = esq + (dir - esq) / 2;
		
		if (v[meio] == x) return meio;
		if (v[meio] > x) return pesqBinariaRec(v, esq, meio - 1, x);
		return pesqBinariaRec(v, meio + 1, dir, x);
	}
	return -1;
}

int main(void)
{
	int vetOrdenado[] = {0,1,3,4,5,6,7,12,13,35};
	int n = sizeof(vetOrdenado) / sizeof(vetOrdenado[0]);
	int x = 13;

	int res = pesqBinariaRec(vetOrdenado, 0, n - 1, x); 
	(res == -1) ? printf("Elemento nao encontrado\n")
				: printf("Elemento encontrado no indice: %d\n", res);
	return 0;
}
