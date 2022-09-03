#include <stdio.h>
#include <stdlib.h>

int visitado[1000], distancia[1000];
int lista[1000][1000];
void dfs(int x, int dis){
    visitado[x]=1;
    distancia[x]=dis;
    int aux=0;
    while(lista[x][aux]!='null'){
        if(visitado[lista[x][aux]]==0){
            dfs(lista[x][aux],dis+1);
        }
      aux++;
    }
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    
    for (int i=1;i<=N;i++){
        lista[i][0]='null';
    }

    for (int i=1;i<N;i++){
      int num1, num2;
      scanf("%d", &num1);
      scanf("%d", &num2);
      int aux = 0;
	    while (lista[num1][aux] !='null' && lista[num1][aux] != num2) {
			  aux++;
		  }
    
		  if (lista[num1][aux] == 'null') {
			  lista[num1][aux] = num2;
			  lista[num1][aux+1] = 'null';
		  }

		  aux = 0;
		  while (lista[num2][aux] != 'null' &&
			  lista[num2][aux] != num1) {
			  aux++;
        }
		  if (lista[num2][aux] == 'null') {
			  lista[num2][aux] = num1;
			  lista[num2][aux+1] = 'null';
  		}
    }
  dfs(1,0);
  int Q;
  scanf("%d", &Q);
  int listaQ[Q];
  for(int i=0;i<Q;i++){
    scanf("%d", &listaQ[i]);
  }
  
    int menor_dis=N+2, indice;
    for(int i=0;i<Q;i++){
      if(menor_dis>distancia[listaQ[i]]){
        menor_dis=distancia[listaQ[i]];
        indice=i;
      }
      if(menor_dis==distancia[listaQ[i]] && i<indice){
        indice=i;
      }
    }
    printf("%d", indice+1);
    return 0;
}