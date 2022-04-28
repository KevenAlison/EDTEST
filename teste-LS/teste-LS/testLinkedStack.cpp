//Para Windows (MS Visual Studio):
#include "pch.h"

//Para Linux:
//#include <gtest/gtest.h>

#include "testLinkedStack.h"

class testLinkedStack : public ::testing::Test {
protected:
	virtual void TearDown() {
		while (topo(pilha) != INT_MIN)
			desempilhar(pilha);

		if (pilha != NULL) {
			free(pilha);
			pilha = NULL;
		}
	}

	virtual void SetUp() {
		pilha = inicializar();
	}

	struct linkedstack* pilha;
};

TEST_F(testLinkedStack, EmpilhamentoPilhaNula) {
	TearDown();

	int numQualquer = 123456;
	empilhar(&pilha, numQualquer);
	EXPECT_EQ(pilha->qtdade, 1);
	EXPECT_EQ(topo(pilha), numQualquer);
}

TEST_F(testLinkedStack, EmpilhamentoPilhaVazia) {
	int numQualquer = 123456;
	empilhar(&pilha, numQualquer);
	EXPECT_EQ(pilha->qtdade, 1);
	EXPECT_EQ(topo(pilha), numQualquer);
}

TEST_F(testLinkedStack, EmpilhamentoPilhaNaoVazia) {
	int numQualquer = 123456;
	empilhar(&pilha, numQualquer);
	EXPECT_EQ(topo(pilha), numQualquer);
	int outroNumQualquer = 7890;
	empilhar(&pilha, outroNumQualquer);
	EXPECT_EQ(pilha->qtdade, 2);
	EXPECT_EQ(topo(pilha), outroNumQualquer);
	//pra certificar que topo() nao remove da pilha
	EXPECT_EQ(topo(pilha), outroNumQualquer);
}


TEST_F(testLinkedStack, DesempilhamentoPilhaNula) {
	TearDown();

	EXPECT_EQ(desempilharRetornando(pilha), INT_MIN);
}

TEST_F(testLinkedStack, DesempilhamentoPilhaVazia) {
	desempilhar(pilha);
	EXPECT_EQ(pilha->qtdade, 0);
	EXPECT_EQ(desempilharRetornando(pilha), INT_MIN);
}

TEST_F(testLinkedStack, DesempilhamentoPilhaNaoVazia) {
	int numQualquer = 123456;
	empilhar(&pilha, numQualquer);
	int outroNumQualquer = 7890;
	empilhar(&pilha, outroNumQualquer);
	desempilhar(pilha);
	EXPECT_EQ(pilha->qtdade, 1);
	EXPECT_EQ(desempilharRetornando(pilha), numQualquer);
}

TEST_F(testLinkedStack, TopoPilhaNula) {
	TearDown();

	EXPECT_EQ(topo(pilha), INT_MIN);
}

TEST_F(testLinkedStack, TopoPilhaVazia) {
	EXPECT_EQ(topo(pilha), INT_MIN);
}

TEST_F(testLinkedStack, TopoPilhaNaoVazia) {
	int numQualquer = 123456;
	empilhar(&pilha, numQualquer);
	EXPECT_EQ(topo(pilha), numQualquer);
	int outroNumQualquer = 7890;
	empilhar(&pilha, outroNumQualquer);
	EXPECT_EQ(topo(pilha), outroNumQualquer);
}

TEST_F(testLinkedStack, FuncVazioPilhaNula) {
	TearDown();

	EXPECT_TRUE(vazia(pilha));
}

TEST_F(testLinkedStack, FuncVazioPilhaVazia) {
	EXPECT_TRUE(vazia(pilha));
}

TEST_F(testLinkedStack, FuncVazioPilhaNaoVazia) {
	int numQualquer = 123456;
	empilhar(&pilha, numQualquer);
	EXPECT_FALSE(vazia(pilha));
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}