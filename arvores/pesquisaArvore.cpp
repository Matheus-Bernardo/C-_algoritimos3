#include <iostream>
#include <iomanip>

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

// Fun��o para calcular a m�dia dos elementos da �rvore bin�ria
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

    TreeNode* root = NULL;  // Ponteiro para a raiz da �rvore

    //cout << "Digite os n�meros a serem inseridos na �rvore (digite -1 para parar): ";
    int num;
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    float avg = media(root);

    cout << "Media: " << fixed << setprecision(2) << avg << endl;

    // TODO: Fun��o para desalocar a mem�ria ocupada pela �rvore
    // ...

    return 0;
}
