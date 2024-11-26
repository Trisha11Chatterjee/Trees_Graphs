#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function declarations for subTree and matchTree
bool subTree(TreeNode* r1, TreeNode* r2);
bool matchTree(TreeNode* r1, TreeNode* r2);

// Function to check if t2 is a subtree of t1
bool containsTree(TreeNode* t1, TreeNode* t2) {
    if (t2 == nullptr) {
        return true;  // The empty tree is always a subtree
    } else {
        return subTree(t1, t2);
    }
}

// Helper function to check if t2 is a subtree of t1 starting at a given node
bool subTree(TreeNode* r1, TreeNode* r2) {
    if (r1 == nullptr) {
        return false;  // big tree empty & subtree still not found.
    }
    if (r1->data == r2->data) {
        if (matchTree(r1, r2)) {
            return true;  // Trees match
        }
    }
    return (subTree(r1->left, r2) || subTree(r1->right, r2));  // Check left and right subtrees
}

// Helper function to check if two trees match
bool matchTree(TreeNode* r1, TreeNode* r2) {
    if (r2 == nullptr && r1 == nullptr) {
        return true;  // Nothing left in the subtree, match
    }
    if (r1 == nullptr || r2 == nullptr) {
        return false;  // One tree is empty while the other is not
    }
    if (r1->data != r2->data) {
        return false;  // Data doesn’t match
    }
    return (matchTree(r1->left, r2->left) && matchTree(r1->right, r2->right));  // Check both subtrees
}

// In-order traversal to print the tree
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

// Example usage
int main() {
    // Create big tree (t1)
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->left = new TreeNode(4);
    t1->left->right = new TreeNode(5);

    // Create subtree (t2)
    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(4);
    t2->right = new TreeNode(5);

    // Print the input trees
    cout << "Tree t1 (Big Tree): ";
    printTree(t1);
    cout << endl;

    cout << "Tree t2 (Subtree): ";
    printTree(t2);
    cout << endl;

    // Check if t2 is a subtree of t1
    if (containsTree(t1, t2)) {
        cout << "t2 is a subtree of t1." << endl;
    } else {
        cout << "t2 is NOT a subtree of t1." << endl;
    }

    // Cleanup (optional)
    delete t1->left->left;
    delete t1->left->right;
    delete t1->left;
    delete t1->right;
    delete t1;

    delete t2->left;
    delete t2->right;
    delete t2;

    return 0;
}
