#include <stdio.h>
#include <stdlib.h>

// Definição de uma estrutura para um nó da árvore
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função para criar um novo nó com o valor especificado
struct TreeNode* createTreeNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int rangeSumBST(struct TreeNode* root, int low, int high) {
    // Caso base: se o nó é nulo, retornamos 0.
    if (root == NULL) {
        return 0;
    }

    int sum = 0;

    // Verificamos se o valor do nó atual está dentro do intervalo [low, high].
    if (root->val >= low && root->val <= high) {
        sum += root->val;
    }

    // Recursivamente, somamos os valores dos nós da subárvore esquerda e direita.
    sum += rangeSumBST(root->left, low, high);
    sum += rangeSumBST(root->right, low, high);

    return sum;
}

int main() {
    // Criando a árvore corretamente
    struct TreeNode* root = createTreeNode(10);
    root->left = createTreeNode(5);
    root->left->left = createTreeNode(3);
    root->left->right = createTreeNode(7);
    root->right = createTreeNode(15);

    // Agora a árvore tem a seguinte estrutura:
    //         10
    //        /  \
    //       5   15
    //      / \
    //     3   7

    // Realize as operações desejadas com a árvore aqui.

    int low = 5;
    int high = 15;
    int result = rangeSumBST(root, low, high);

    printf("Soma dos valores no intervalo [%d, %d] na árvore: %d\n", low, high, result);

    // Não se esqueça de liberar a memória alocada quando a árvore não for mais necessária.
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
