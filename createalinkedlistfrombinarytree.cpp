/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to find level-wise linked lists of nodes
vector<queue<TreeNode*>> findLevelLinkedList(TreeNode* root) {
    vector<queue<TreeNode*>> result; // Vector of queues, each representing a level
    if (root == nullptr) {
        return result;
    }

    queue<TreeNode*> currentLevel; // Queue to hold nodes at the current level
    currentLevel.push(root);       // Start with the root node

    while (!currentLevel.empty()) {
        queue<TreeNode*> nextLevel; // Queue to hold nodes for the next level
        result.push_back(currentLevel); // Add the current level to the result

        while (!currentLevel.empty()) {
            TreeNode* node = currentLevel.front(); // Get the front node
            currentLevel.pop();                    // Remove it from the queue

            // Add children to the next level's queue
            if (node->left) {
                nextLevel.push(node->left);
            }
            if (node->right) {
                nextLevel.push(node->right);
            }
        }

        // Move to the next level
        currentLevel = nextLevel;
    }

    return result;
}

// Helper function to print the level-wise linked lists
void printLevelLinkedList(const vector<queue<TreeNode*>>& result) {
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "Level " << i << ": ";
        queue<TreeNode*> level = result[i];
        while (!level.empty()) {
            cout << level.front()->val << " ";
            level.pop();
        }
        cout << endl;
    }
}

// Example usage
int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Find level linked list
    vector<queue<TreeNode*>> levelLinkedList = findLevelLinkedList(root);

    // Print the result
    printLevelLinkedList(levelLinkedList);

    // Cleanup (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
