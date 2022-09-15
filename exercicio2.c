#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
	int visitado;
	int lista_adj[1000];
	int tam_lista_adj;
	int sexo;
} vertice;

int dfs(vertice *vertices, int raiz, int sexo) {
	int i;

	vertices[raiz].visitado = 1;
	vertices[raiz].sexo = sexo;

	for (i = 0; i < vertices[raiz].tam_lista_adj; i++) {
		if (vertices[vertices[raiz].lista_adj[i]].visitado == 0) {
			if (!dfs(vertices, vertices[raiz].lista_adj[i], sexo * -1)) {
				return 0;
			}
		} else {
			if (vertices[raiz].sexo ==
				vertices[vertices[raiz].lista_adj[i]].sexo)
				return 0;
		}
	}
	return 1;
}

int main() {
	int cenario, bug, relation;
	vertice *comunidade;
	scanf("%d", &cenario);
	int lista[cenario];
	for (int j = 0; j < cenario; j++) {
		scanf("%d %d", &bug, &relation);
		comunidade = (vertice *)calloc(bug + 1, sizeof(vertice));
		int bug1, bug2;

		for (int i = 0; i < relation; i++) {
			scanf("%d %d", &bug1, &bug2);
			comunidade[bug1].lista_adj[comunidade[bug1].tam_lista_adj] = bug2;
			comunidade[bug1].tam_lista_adj++;
			comunidade[bug2].lista_adj[comunidade[bug2].tam_lista_adj] = bug1;
			comunidade[bug2].tam_lista_adj++;
		}

		if (dfs(comunidade, 1, 1)) {
			lista[j] = 1;
		} else {
			lista[j] = 0;
		}
	}

	for (int j = 0; j < cenario; j++) {
		if (lista[j]) {
			printf("Scenario #%d:\nSuspicious bugs found!\n", j + 1);
		} else {
			printf("Scenario #%d:\nSuspicious bugs found!\n", j + 1);
		}
	}
}