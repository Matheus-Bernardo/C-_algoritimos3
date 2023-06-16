#include <iostream>

// Defini��o da estrutura do n� da �rvore bin�ria
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

// Fun��o para inserir um elemento na �rvore bin�ria
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

// Fun��o para contar o n�mero de folhas da �rvore bin�ria
int contaFolhas(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;  // � uma folha
    }

    int countLeft = contaFolhas(root->left);
    int countRight = contaFolhas(root->right);

    return countLeft + countRight;
}

int main() {
    using namespace std;

    TreeNode* root = NULL;  // Ponteiro para a raiz da �rvore

    //cout << "Digite os n�meros a serem inseridos na �rvore (digite -1 para parar): ";
    int num;
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    int leafCount = contaFolhas(root);

    //cout << "A �rvore possui " << leafCount << " folhas." << endl;
	cout <<leafCount << endl;
    // TODO: Fun��o para desalocar a mem�ria ocupada pela �rvore
    // ...

    return 0;
}
