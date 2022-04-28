//Para Windows (MS Visual Studio):
#include "pch.h"
#include "testDoublyLinkedList.h"
#include <math.h>

class DoublyLinkedListTest : public ::testing::Test {
protected:
	virtual void TearDown() {
		struct no* auxNo;
		struct no* proxNo = lista->cabeca;
		while (proxNo != NULL) {
			auxNo = proxNo;
			proxNo = proxNo->prox;
			free(auxNo);
		}
		free(lista);
	}

	virtual void SetUp() {
		lista = inicializar();
	}

	struct doublylinkedlist* lista = NULL;
};


TEST_F(DoublyLinkedListTest, InsercaoListaVaziaFim) {
	inserirElementoNoFim(lista, 10);
	EXPECT_EQ(lista->tamanho, 1);
	EXPECT_EQ(obterElementoEmPosicao(lista, 0), 10);
}

TEST_F(DoublyLinkedListTest, InsercaoListaVaziaInicio) {
	inserirElementoNoInicio(lista, 10);
	EXPECT_EQ(lista->tamanho, 1);
	EXPECT_EQ(obterElementoEmPosicao(lista, 0), 10);
	EXPECT_EQ(lista->cabeca->valor, 10);
	EXPECT_EQ(lista->cauda->valor, 10);
}




TEST_F(DoublyLinkedListTest, InsercaoListaNaoVaziaFim) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoNoFim(lista, i);
	}
	EXPECT_EQ(lista->tamanho, numElementos);
	for (int i = 0; i < numElementos; i++) {
		EXPECT_EQ(obterElementoEmPosicao(lista, i), i);
	}
	EXPECT_EQ(lista->cabeca->valor, 0);
	EXPECT_EQ(lista->cauda->valor, numElementos - 1);
}

TEST_F(DoublyLinkedListTest, InsercaoListaNaoVaziaInicio) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoNoInicio(lista, i);
	}
	EXPECT_EQ(lista->tamanho, numElementos);
	for (int i = 0; i < numElementos; i++) {
		EXPECT_EQ(obterElementoEmPosicao(lista, i), numElementos - 1 - i);
	}
	EXPECT_EQ(lista->cabeca->valor, numElementos - 1);
	EXPECT_EQ(lista->cauda->valor, 0);
}

TEST_F(DoublyLinkedListTest, InsercaoEmPosicaoFim) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoEmPosicao(lista, i, i);
	}
	EXPECT_EQ(lista->tamanho, numElementos);
	for (int i = 0; i < numElementos; i++) {
		EXPECT_EQ(obterElementoEmPosicao(lista, i), i);
	}
	EXPECT_EQ(lista->cabeca->valor, 0);
	EXPECT_EQ(lista->cauda->valor, numElementos - 1);
}

TEST_F(DoublyLinkedListTest, InsercaoaEmPosicaoMeio) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoEmPosicao(lista, i, i);
	}

	int pos = 50;
	inserirElementoEmPosicao(lista, 9999, pos);
	EXPECT_EQ(obterElementoEmPosicao(lista, pos), 9999);

	EXPECT_EQ(lista->cabeca->valor, 0);
	EXPECT_EQ(lista->cauda->valor, numElementos - 1);
}

TEST_F(DoublyLinkedListTest, InsercaoEmPosicaoInicio) {
	int numElementos = 100;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoEmPosicao(lista, i, 0);
	}
	EXPECT_EQ(lista->tamanho, numElementos);
	for (int i = 0; i < numElementos; i++) {
		EXPECT_EQ(obterElementoEmPosicao(lista, i), numElementos - 1 - i);
	}

	EXPECT_EQ(lista->cabeca->valor, numElementos - 1);
	EXPECT_EQ(lista->cauda->valor, 0);
}


TEST_F(DoublyLinkedListTest, RemocaoFim) {
	int numElementos = 5;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoNoFim(lista, i);
	}
	EXPECT_EQ(lista->tamanho, numElementos);
	for (int i = 0; i < numElementos; i++) {
		removerElementoEmPosicao(lista, numElementos - i - 1);
		EXPECT_EQ(lista->tamanho, numElementos - i - 1);
	}
	EXPECT_EQ(lista->tamanho, 0);
	EXPECT_EQ(lista->cabeca, nullptr);
	EXPECT_EQ(lista->cauda, nullptr);
}

TEST_F(DoublyLinkedListTest, RemocaoInicio) {
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
	EXPECT_EQ(lista->cabeca, nullptr);
	EXPECT_EQ(lista->cauda, nullptr);
}
/*
TEST_F(DoublyLinkedListTest2, RemocaoMeio) {
	int numElementos = 10;
	for (int i = 0; i < numElementos; i++) {
		double tamDouble = (double)lista->qtdade;
		int pos = ceil(tamDouble / 2);
		inserirElementoEmPosicao(lista, i, pos);
	}
	EXPECT_EQ(lista->qtdade, numElementos);
	while (lista->qtdade > 0) {
		EXPECT_EQ(obterElementoEmPosicao(lista, ceil(lista->qtdade / 2)), lista->qtdade - 1);
		removerElementoEmPosicao(lista, ceil(lista->qtdade / 2));
	}
	EXPECT_EQ(lista->qtdade, 0);
	EXPECT_EQ(lista->cabeca, nullptr);
	EXPECT_EQ(lista->cauda, nullptr);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

*/