/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm> // For std::max and std::min
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to calculate the maximum depth of a binary tree
int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Function to calculate the minimum depth of a binary tree
int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Function to check if a binary tree is balanced
bool isBalanced(TreeNode* root) {
    return (maxDepth(root) - minDepth(root) <= 1);
}

// Example usage
int main() {
    // Creating a sample binary tree:
    //         1
    //        / \
    //       2   3
    //      /
    //     4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;
    cout << "Is Balanced: " << (isBalanced(root) ? "Yes" : "No") << endl;

    // Cleanup (optional, not required for small examples but good practice)
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
