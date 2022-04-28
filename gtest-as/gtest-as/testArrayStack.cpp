//Para Windows (MS Visual Studio):
#include "pch.h"

//Para Linux:
//#include <gtest/gtest.h>

#include "testArrayStack.h"

class ArrayStackTest : public ::testing::Test {
protected:
	virtual void TearDown() {
		if (pilha != NULL) {
			if (pilha->vetor != NULL) {
				free(pilha->vetor);
			}
			free(pilha);
			pilha = NULL;
		}
	}

	virtual void SetUp() {
		pilha = inicializar(10);
	}

	struct arraystack* pilha;
};

TEST_F(ArrayStackTest, EmpilhamentoPilhaNula) {
	TearDown();

	int numQualquer = 123456;
	empilhar(&pilha, numQualquer);
	EXPECT_EQ(pilha->qtdade, 1);
	EXPECT_EQ(topo(pilha), numQualquer);
}

TEST_F(ArrayStackTest, EmpilhamentoPilhaVazia) {
	int numQualquer = 123456;
	empilhar(&pilha, numQualquer);
	EXPECT_EQ(pilha->qtdade, 1);
	EXPECT_EQ(topo(pilha), numQualquer);
}

TEST_F(ArrayStackTest, EmpilhamentoPilhaNaoVazia) {
	int numQualquer = 123456;
	empilhar(&pilha, numQualquer);
	int outroNumQualquer = 7890;
	empilhar(&pilha, outroNumQualquer);
	EXPECT_EQ(pilha->qtdade, 2);
	EXPECT_EQ(topo(pilha), outroNumQualquer);
}

TEST_F(ArrayStackTest, EmpilhamentoDobrandotamanho) {
	int numInsercoes = 2 * pilha->tamanho;
	for (int i = 0; i < numInsercoes; i++) {
		empilhar(&pilha, i);
	}
	EXPECT_EQ(pilha->qtdade, numInsercoes);
	EXPECT_EQ(topo(pilha), numInsercoes - 1);
}

TEST_F(ArrayStackTest, DesempilhamentoPilhaNula) {
	TearDown();

	EXPECT_EQ(desempilharRetornando(pilha), INT_MIN);
}

TEST_F(ArrayStackTest, DesempilhamentoPilhaVazia) {
	desempilhar(pilha);
	EXPECT_EQ(pilha->qtdade, 0);
	EXPECT_EQ(desempilharRetornando(pilha), INT_MIN);
}

TEST_F(ArrayStackTest, DesempilhamentoPilhaNaoVazia) {
	int numQualquer = 123456;
	empilhar(&pilha, numQualquer);
	int outroNumQualquer = 7890;
	empilhar(&pilha, outroNumQualquer);
	EXPECT_EQ(pilha->qtdade, 2);
	desempilhar(pilha);
	EXPECT_EQ(pilha->qtdade, 1);
	EXPECT_EQ(desempilharRetornando(pilha), numQualquer);
	EXPECT_EQ(pilha->qtdade, 0);
}

TEST_F(ArrayStackTest, TopoPilhaNula) {
	TearDown();

	EXPECT_EQ(topo(pilha), INT_MIN);
}

TEST_F(ArrayStackTest, TopoPilhaVazia) {
	EXPECT_EQ(topo(pilha), INT_MIN);
}

TEST_F(ArrayStackTest, TopoPilhaNaoVazia) {
	int numQualquer = 123456;
	empilhar(&pilha, numQualquer);
	EXPECT_EQ(topo(pilha), numQualquer);
	int outroNumQualquer = 7890;
	empilhar(&pilha, outroNumQualquer);
	EXPECT_EQ(topo(pilha), outroNumQualquer);
}

TEST_F(ArrayStackTest, VazioPilhaNula) {
	TearDown();

	EXPECT_TRUE(vazia(pilha));
}

TEST_F(ArrayStackTest, VazioPilhaVazia) {
	EXPECT_TRUE(vazia(pilha));
}

TEST_F(ArrayStackTest, VazioPilhaNaoVazia) {
	int numQualquer = 123456;
	empilhar(&pilha, numQualquer);
	EXPECT_FALSE(vazia(pilha));
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}