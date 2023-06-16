#include <iostream>

// Definição da estrutura do nó da árvore binária
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

// Função para inserir um elemento na árvore binária
void insert(TreeNode*& root, int value) {
    if (root == NULL) {
        root = new TreeNode(value);
        return;
    }

    if (value < root->data) {
        insert(root->left, value);
    } else if (value > root->data) {
        insert(root->right, value);
    }
}

// Função para contar o número de folhas da árvore binária
int contaFolhas(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;  // É uma folha
    }

    int countLeft = contaFolhas(root->left);
    int countRight = contaFolhas(root->right);

    return countLeft + countRight;
}

int main() {
    using namespace std;

    TreeNode* root = NULL;  // Ponteiro para a raiz da árvore

    //cout << "Digite os números a serem inseridos na árvore (digite -1 para parar): ";
    int num;
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    int leafCount = contaFolhas(root);

    //cout << "A árvore possui " << leafCount << " folhas." << endl;
	cout <<leafCount << endl;
    // TODO: Função para desalocar a memória ocupada pela árvore
    // ...

    return 0;
}
