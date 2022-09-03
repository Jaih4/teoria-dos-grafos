#include <stdio.h>
#include <stdlib.h>



int visitados[999], lista[999][999];
void dfs(int x){
    visitados[x]=1;
  int tamanholista=0;
    while(lista[x][tamanholista]!='null'){
      tamanholista++;
    }
    for(int i=0;i<tamanholista;i++){
        if(visitados[lista[x][i]]==0){
          dfs(visitados[lista[x][i]]);
        }
    }
}
int main(int argc, char const *argv[])
{
  int n, a;
  scanf("%d", &n);
  for (int i=0;i<n;i++){
    lista[i][0]='null';
  }
  scanf("%d", &a);
  for (int i=0;i<a;i++){
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
  int ligacao=0;
  for(int i=0;i<n;i++){
    int aux=0;
    while(lista[i][aux]!='null'){
      if (visitados[i]==0){
        dfs(i);
        ligacao++;
      }
      aux++;
    }
  }

  
  printf("%d", ligacao);
  
  return 0;
}
