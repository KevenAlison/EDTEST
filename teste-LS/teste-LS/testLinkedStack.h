#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct no {
	int valor;
	struct no* prox;
};

struct linkedstack {
	struct no* topo;
	int qtdade;
};

struct linkedstack* inicializar() {
	struct linkedstack* pilha = (struct linkedstack*)malloc(sizeof(struct linkedstack));
	pilha->topo = NULL;
	pilha->qtdade = 0;

	return pilha;
}

struct no* alocarNovoNo(int valoror) {
	struct no* novoNo = (struct no*)malloc(sizeof(struct no));
	novoNo->prox = NULL;
	novoNo->valor = valoror;

	return novoNo;
}


//se a pilha estiver nula, instancie a pilha
//por causa da possibilidade de instanciacao usamos struct linkedstack**
void empilhar(struct linkedstack** pilha, int valoror) {
	struct linkedstack* pilharef;
	struct no* novoNo = alocarNovoNo(valoror);
	if (*pilha == NULL) {
		*pilha = inicializar();
	}

	pilharef = *pilha;

	if (pilharef->topo != NULL) {
		novoNo->prox = pilharef->topo;
	}
	pilharef->topo = novoNo;

	pilharef->qtdade++;
}


bool vazia(struct linkedstack* pilha) {
	if (pilha != NULL) {
		if (pilha->qtdade != 0) {
			return false;
		}
	}
	return true;
}

//decrementar qtdade se a pilha não estiver nula ou vazia
void desempilhar(struct linkedstack* pilha) {
	if (!vazia(pilha)) {
		struct no* temp = pilha->topo;
		pilha->topo = pilha->topo->prox;
		free(temp);
		pilha->qtdade--;
	}
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct linkedstack* pilha) {
	if (!vazia(pilha)) {
		int retorno = pilha->topo->valor;
		desempilhar(pilha);
		return retorno;
	}
	return INT_MIN;
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct linkedstack* pilha) {
	if (vazia(pilha)) {
		return INT_MIN;
	}

		return pilha->topo->valor;
	
}


void exibirPilha(struct linkedstack* pilha) {
	//usamos o aux para percorrer a lista
	if (!vazia(pilha)) {
		struct no* aux = pilha->topo;
		//navega partindo do topo até chegar NULL
		printf("_\n");
		do {
			printf("%d\n", aux->valor);
			aux = aux->prox;
		} while (aux != NULL);
		printf("_");
	}
	else {
		printf("A pilha está vazia!");
	}
}
