//Para Windows (MS Visual Studio):
#include "pch.h"
#include "testLinkedList.h"
#include <math.h>

class LinkedListTest : public ::testing::Test {
protected:
	virtual void TearDown() {
		struct no* aux;
		struct no* proxNo = lista->cabeca;
		while (proxNo != NULL) {
			aux = proxNo;
			proxNo = proxNo->prox;
			free(aux);
		}
		free(lista);
	}

	virtual void SetUp() {
		lista = inicializar();
	}

	struct linkedlist* lista = NULL;
};

TEST_F(LinkedListTest, InsercaoListaVaziaFim) {
	inserirElementoNoFim(lista, 10);
	EXPECT_EQ(lista->tamanho, 1);
	EXPECT_EQ(obterElementoEmPosicao(lista, 0), 10);
}

TEST_F(LinkedListTest, InsercaoListaNaoVaziaFim) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoNoFim(lista, i);
	}
	EXPECT_EQ(lista->tamanho, numElementos);
	for (int i = 0; i < numElementos; i++) {
		EXPECT_EQ(obterElementoEmPosicao(lista, i), i);
	}
}

TEST_F(LinkedListTest, InsercaoListaNaoVaziaInicio) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoNoInicio(lista, i);
	}
	EXPECT_EQ(lista->tamanho, numElementos);
	for (int i = 0; i < numElementos; i++) {
		EXPECT_EQ(obterElementoEmPosicao(lista, i), numElementos - 1 - i);
	}
}


TEST_F(LinkedListTest, InsercaoEmPosicaoFim) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoEmPosicao(lista, i, i);
	}
	EXPECT_EQ(lista->tamanho, numElementos);
	for (int i = 0; i < numElementos; i++) {
		EXPECT_EQ(obterElementoEmPosicao(lista, i), i);
	}
}


TEST_F(LinkedListTest, InsercaoaEmPosicaoMeio) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoEmPosicao(lista, i, i);
	}

	int pos = 50;
	inserirElementoEmPosicao(lista, 9999, pos);
	EXPECT_EQ(obterElementoEmPosicao(lista, pos), 9999);
}

TEST_F(LinkedListTest, InsercaoEmPosicaoInicio) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoEmPosicao(lista, i, 0);
	}
	EXPECT_EQ(lista->tamanho, numElementos);
	for (int i = 0; i < numElementos; i++) {
		EXPECT_EQ(obterElementoEmPosicao(lista, i), numElementos - 1 - i);
	}
}

//obterElementoEmPosicao ja foi testado em todos os casos de teste

TEST_F(LinkedListTest, RemocaoFim) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoNoFim(lista, i);
	}
	EXPECT_EQ(lista->tamanho, numElementos);
	for (int i = 0; i < numElementos; i++) {
		removerElementoEmPosicao(lista, numElementos - i - 1);
		EXPECT_EQ(lista->tamanho, numElementos - i - 1);
	}
	EXPECT_EQ(lista->tamanho, 0);
}

TEST_F(LinkedListTest, RemocaoInicio) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoNoFim(lista, i);
	}
	EXPECT_EQ(lista->tamanho, numElementos);
	for (int i = 0; i < numElementos; i++) {
		removerElementoEmPosicao(lista, 0);
		EXPECT_EQ(lista->tamanho, numElementos - i - 1);
		if (lista->tamanho > 0)
			EXPECT_EQ(obterElementoEmPosicao(lista, 0), i + 1);
	}
	EXPECT_EQ(lista->tamanho, 0);
}

TEST_F(LinkedListTest, RemocaoMeio) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		double tamDouble = (double)lista->tamanho;
		int pos = ceil(tamDouble / 2);
		inserirElementoEmPosicao(lista, i, pos);
	}
	EXPECT_EQ(lista->tamanho, numElementos);
	while (lista->tamanho > 0) {
		EXPECT_EQ(obterElementoEmPosicao(lista, ceil(lista->tamanho / 2)), lista->tamanho - 1);
		removerElementoEmPosicao(lista, ceil(lista->tamanho / 2));
	}
	EXPECT_EQ(lista->tamanho, 0);
}
