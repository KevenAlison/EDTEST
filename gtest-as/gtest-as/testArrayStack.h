
#include <stdio.h>
#include <stdlib.h>

struct arraystack {
	int* vetor;
	int qtdade;
	int tamanho;
};

struct arraystack* inicializar(int tamanho) {
	struct arraystack* pilha = (struct arraystack*)malloc(sizeof(struct arraystack));
	pilha->vetor = (int*)calloc(tamanho, sizeof(int));
	pilha->qtdade = 0;
	pilha->tamanho = tamanho;
	return pilha;
}

bool vazia(struct arraystack* pilha) {
	if (pilha != NULL) {
		if (pilha->qtdade != 0) {
			return false;
		}
	}
	return true;
}

void duplicartamanho(struct arraystack* lista) {
	lista->vetor = (int*)realloc(lista->vetor, 2 * lista->tamanho * sizeof(int));
	lista->tamanho *= 2;
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct arraystack* pilha) {
	if (vazia(pilha)) {
		return INT_MIN;
	}

	return pilha->vetor[0];

}

void empilhar(struct arraystack** pilha, int valor) {
		struct arraystack* pilharef;
		if (*pilha == NULL) {
		*pilha = inicializar(10);
		}
		pilharef = *pilha;
		if (pilharef->tamanho == pilharef->qtdade) {
			duplicartamanho(pilharef);
		}
		for (int i = 1; i > pilharef->qtdade; i--) {
			pilharef->vetor[i] = pilharef->vetor[i - 1];
		}
		pilharef->vetor[0] = valor;
		pilharef->qtdade++;
}


void desempilhar(struct arraystack* pilha) {
	if (!vazia(pilha)) {
		for (int i = 1; i < pilha->qtdade; i++) {
			pilha->vetor[i - 1] = pilha->vetor[i];
		}
	pilha->qtdade--;
	}
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct arraystack* pilha) {
	if (!vazia(pilha)) {
		int retorno = pilha->vetor[0];
		desempilhar(pilha);
		return retorno;
	}
	return INT_MIN;
}


void exibirpilha(struct arraystack* pilha) {
	printf("[");
	for (int i = 0; i < pilha->qtdade; i++) {
		printf("%d", pilha->vetor[i]);
		if (i < pilha->qtdade - 1) {
			printf(", ");
		}
	}
	printf("]");
}



