#include <stdio.h>

void bubblesort(int * vet, int qtd)
{
    int aux,pass,i;
    int trocou=1;
    for(pass=0;pass<qtd-1 && trocou==1;pass++)
    {
        trocou=0;
        for(i=0;i<qtd-1-pass;i++)
        {
            if (vet[i] > vet[i+1])
            {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                trocou=1;
            }
        }
    }
}

int main() {
	int N;
	printf("Digite N:\n");
	scanf("%d", &N);
	int numero1, numero2;
	int lista[500][500], matriz_adjacencia[500][500];

	for (int i = 0; i < 500; i++) {
		lista[i][0] = 'null';
		for (int j = 0; j < 500; j++) {
			matriz_adjacencia[i][j] = 0;
		}
	}

	int maior = 0, verticies[2 * N];
	verticies[0] = 'null';
  int aux;
	for (int i = 0; i < N; i++) {
		printf("Digite o %d par\n", i + 1);
		scanf("%d", &numero1);
		scanf("%d", &numero2);

		matriz_adjacencia[numero1][numero1] = 1;
		matriz_adjacencia[numero2][numero2] = 1;
		matriz_adjacencia[numero1][numero2] = 1;
		matriz_adjacencia[numero2][numero1] = 1;

		aux = 0;
		while (lista[numero1][aux] !='null' && lista[numero1][aux] != numero2) {
			aux++;
		}
    
		if (lista[numero1][aux] == 'null') {
			lista[numero1][aux] = numero2;
			lista[numero1][aux+1] = 'null';
		}

		aux = 0;
		while (lista[numero2][aux] != 'null' &&
			   lista[numero2][aux] != numero1) {
			aux++;
		}
		if (lista[numero2][aux] == 'null') {
			lista[numero2][aux] = numero1;
			lista[numero2][aux+1] = 'null';
      
		}

		if (numero1 == numero2) {
			for (int j = 0; j <= aux; j++) {
				if (verticies[j] == numero1) {
					break;
				}
				if (j == aux) {
					verticies[aux] = numero1;
					aux++;
					verticies[aux] = 'null';
				}
			}
		} else {
			for (int j = 0; j <= aux; j++) {
				if (verticies[j] == numero1) {
					break;
				}
				if (j == aux) {
					verticies[aux] = numero1;
					aux++;
					verticies[aux] = 'null';
          break;
				}
			}

			for (int j = 0; j <= aux; j++) {
				if (verticies[j] == numero2) {
					break;
				}
				if (j == aux) {
					verticies[aux] = numero2;
					aux++;
					verticies[aux] = 'null';
          break;
				}
			}
		}
	}
  
	bubblesort(verticies, aux);

  printf("  ");
  for(int j=0;j<aux;j++){
    printf("%d ", verticies[j]);
  }
  
  for(int i=0;i<aux;i++){
    printf("\n");
    printf("%d:", verticies[i]);
    for(int j=0;j<aux;j++){
       printf("%d ", matriz_adjacencia[verticies[i]][verticies[j]]); 
    }
  }
  printf("\n");
  for(int i=0;i<aux;i++){
    int j=0;
    printf("\n%d:", verticies[i]); 
    while(lista[verticies[i]][j]!='null'){
      printf("%d ", lista[verticies[i]][j]);
      j++;
    }
  }
	return 0;
}