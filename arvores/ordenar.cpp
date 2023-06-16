#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};

// Função para inserir um número na árvore
TreeNode* insert(TreeNode* root, int num) {
    if (root == NULL) {
        return new TreeNode(num);
    }

    if (num < root->value) {
        root->left = insert(root->left, num);
    } else {
        root->right = insert(root->right, num);
    }

    return root;
}

// Função para encontrar o maior elemento na árvore
int findMax(TreeNode* root) {
    if (root == NULL) {
        return INT_MIN;
    }

    int maxValue = root->value;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    if (leftMax > maxValue) {
        maxValue = leftMax;
    }
    if (rightMax > maxValue) {
        maxValue = rightMax;
    }

    return maxValue;
}

// Função para encontrar o menor elemento na árvore
int findMin(TreeNode* root) {
    if (root == NULL) {
        return INT_MAX;
    }

    int minValue = root->value;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);

    if (leftMin < minValue) {
        minValue = leftMin;
    }
    if (rightMin < minValue) {
        minValue = rightMin;
    }

    return minValue;
}

int main() {
    TreeNode* root = NULL;
    int num;

    //cout << "Digite os números a serem inseridos na árvore (digite -1 para parar): ";
    while (cin >> num && num != -1) {
        root = insert(root, num);
    }

    int minValue = findMin(root);
    int maxValue = findMax(root);

    cout << minValue <<" e "<< maxValue <<endl;
    

    // TODO: Liberar memória da árvore

    return 0;
}
