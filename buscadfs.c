int visitado[10], verticie[10];
void dfs(int x){
    visitado[x]=1;
    printf("%d", x);
    int tamanholista_adj;
    for(int i=0;i<tamanholista_adj;i++){
        if(visitado[verticie[i]]==0){
            dfs(verticie[i]);
        }
    }
}


