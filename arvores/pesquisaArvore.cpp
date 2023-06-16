#include <iostream>
#include <iomanip>

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

// Função para calcular a média dos elementos da árvore binária
float media(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int sum = root->data;
    int count = 1;

    if (root->left != NULL) {
        sum += root->left->data;
        count++;
    }

    if (root->right != NULL) {
        sum += root->right->data;
        count++;
    }

    return static_cast<float>(sum) / count;
}

int main() {
    using namespace std;

    TreeNode* root = NULL;  // Ponteiro para a raiz da árvore

    //cout << "Digite os números a serem inseridos na árvore (digite -1 para parar): ";
    int num;
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    float avg = media(root);

    cout << "Media: " << fixed << setprecision(2) << avg << endl;

    // TODO: Função para desalocar a memória ocupada pela árvore
    // ...

    return 0;
}
