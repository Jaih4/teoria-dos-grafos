#include <stdio.h>
#include <stdlib.h>

typedef struct verticie{
  int visitado;
  int lista_adj[1000];
  int tam_lista_adj;
  int distancia;
}verticie;

void dfs(verticie * verticies, int raiz,int distancia){
  int i;
  
  if(verticies[raiz].visitado!=0){
    return;
  }
  
  verticies[raiz].visitado=1;
  verticies[raiz].distancia=distancia;

  for(i=0;i<verticies[raiz].tam_lista_adj;i++){
    if(verticies[verticies[raiz].lista_adj[i]].visitado==0){
      dfs(verticies, verticies[raiz].lista_adj[i],distancia+1);
    }
  }
} 

int main(){
  int nodes,a,b;
  verticie *verticies;
  scanf("%d", &nodes);
  verticies = (verticie*)calloc(nodes,sizeof(verticie));
  for (int i=0;i<nodes;i++){
    scanf("%d %d", &a, &b);
    verticies[a].lista_adj[verticies[a].tam_lista_adj]=b;
    verticies[a].tam_lista_adj++;
    verticies[b].lista_adj[verticies[b].tam_lista_adj]=a;
    verticies[b].tam_lista_adj++;
  }
  dfs(verticies,1,0);
  int maior_dis=0;
  for(int i=0;i<nodes;i++){
    if(verticies[maior_dis].distancia<verticies[i].distancia){
      maior_dis=i;
    }
  }
  dfs(verticies,maior_dis,0);
  int output;
  for(int i=0;i<nodes;i++){
    if(verticies[maior_dis].distancia<verticies[i].distancia){
      maior_dis=i;
      output=verticies[maior_dis].distancia;
    }
  }
  printf("%d", output);
}