#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado=0;
    int lista_adj[1000];
    int tam_lista_adj;
}vertice;


void dfs(vertice *x){
    tam_gp=0;
    if(x->visitado==1){
        return ;
    }
    tam_gp+=1;
    x->visitado=1;

    for(int i=0;i<x->tam_lista_adj;i++){
        dfs(x->lista_adj[i]);
    }
}
int tam_gp;
int main(){

    int funcionario, ligacoes;
    scanf("%d", &funcionario);
    scanf("%d", &ligacoes);
    vertice * funcionarios;
    funcionarios = (vertice*)calloc(funcionario+1,sizeof(vertice));
    int num1,num2;
    int lista[tam_gp];
    for(int i=0;i<funcionario;i++){
        funcionarios[i].lista_adj[0]='null';
    }
    for(int i=0;i<ligacoes;i++){
        scanf("%d", &num1);
        scanf("%d", &num2);
        int aux=0;
        while (funcionarios[num1].lista_adj[aux]!='null'){
            aux++;
        }
        funcionarios[num1].lista_adj[aux]=num2;
        funcionarios[num1].lista_adj[aux+1]='null';
        funcionarios[num1].tam_lista_adj+=1;
        aux=0;
        while (funcionarios[num2].lista_adj[aux]!='null'){
            aux++;
        }
        funcionarios[num2].lista_adj[aux]=num1;
        funcionarios[num2].lista_adj[aux+1]='null';
        funcionarios[num2].tam_lista_adj+=1;
    }
    int aux=0;
    for(int i=0;i<funcionario;i++){
        if(funcionarios[i].visitado==0){
            dfs(funcionarios[i]);
            lista[aux]=tam_gp;
            aux++;
        }
    }
    int saida=1;
    for(int i=0;i<ligacoes;i++){
        saida=saida*lista[i];
    }
    printf("%d %d", ligacoes, saida);
}