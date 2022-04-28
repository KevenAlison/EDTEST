#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct no {
	int val;
	struct no* prox;
};

struct linkedqueue {
	struct no* frente;
	struct no* tras;
	int qtdade;
};

struct linkedqueue* inicializar() {
	struct linkedqueue* fila = (struct linkedqueue*)malloc(sizeof(struct linkedqueue));
	fila->frente = NULL;
	fila->tras = NULL;
	fila->qtdade = 0;

	return fila;
}

struct no* alocarNovoNo(int valor) {
	struct no* novoNo = (struct no*)malloc(sizeof(struct no));
	novoNo->prox = NULL;
	novoNo->val = valor;

	return novoNo;
}

bool vazia(struct linkedqueue* fila) {
	if (fila != NULL) {
		if (fila->qtdade != 0) {
			return false;
		}
	}
	return true;
}

//se a fila estiver nula, instancie a fila
//por causa da possibilidade de instanciacao usamos struct linkedqueue**
void enfileirar(struct linkedqueue** fila, int val) {
	struct no* novoNo = alocarNovoNo(val);
	struct linkedqueue* filaref;
	if (*fila==NULL) {
		*fila = inicializar();
	}
	filaref = *fila;
	if (filaref->frente == NULL && filaref->tras == NULL) {
		filaref->tras = novoNo;
		filaref->frente = novoNo;
	}
	else {

		filaref->tras->prox = novoNo;
		filaref->tras = novoNo;
	}
	filaref->qtdade++;

}

//retorne a constante INT_MIN se a fila for nula ou vazia
//lembrem de desalocar o nó removido (free)
int desenfileirar(struct linkedqueue* fila) {
	if (!vazia(fila)) {
		int retorno = fila->frente->val;
		struct no* temp = fila->frente;
		fila->frente = fila->frente->prox;
		free(temp);
		fila->qtdade--;
		return retorno;
	}
	return INT_MIN;
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct linkedqueue* fila) {
	if (vazia(fila)) {
		return INT_MIN;
	}

	return fila->frente->val;
}