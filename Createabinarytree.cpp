/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to add nodes to the tree recursively
TreeNode* addToTree(const vector<int>& arr, int start, int end) {
    if (end < start) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(arr[mid]);

    // Recursively build the left and right subtrees
    node->left = addToTree(arr, start, mid - 1);
    node->right = addToTree(arr, mid + 1, end);

    return node;
}

// Function to create the minimal BST from a sorted array
TreeNode* createMinimalBST(const vector<int>& array) {
    return addToTree(array, 0, array.size() - 1);
}

// Helper function to print the tree in-order (for testing purposes)
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

// Example usage
int main() {
    // Example sorted array
    vector<int> array = {-10, -3, 0, 5, 9};

    // Create the minimal BST
    TreeNode* root = createMinimalBST(array);

    // Print the tree in-order
    cout << "In-order traversal of the BST: ";
    inOrderTraversal(root);
    cout << endl;

    // Clean up the memory (optional)
    delete root; // For simplicity, assuming we clean up here.

    return 0;
}
