#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};

// Fun��o para inserir um n�mero na �rvore
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

// Fun��o para encontrar o maior elemento na �rvore
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

// Fun��o para encontrar o menor elemento na �rvore
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

    //cout << "Digite os n�meros a serem inseridos na �rvore (digite -1 para parar): ";
    while (cin >> num && num != -1) {
        root = insert(root, num);
    }

    int minValue = findMin(root);
    int maxValue = findMax(root);

    cout << minValue <<" e "<< maxValue <<endl;
    

    // TODO: Liberar mem�ria da �rvore

    return 0;
}
