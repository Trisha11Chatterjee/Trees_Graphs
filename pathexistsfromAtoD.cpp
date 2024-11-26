/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Enum to represent the state of each node
enum State {
    Unvisited,
    Visiting,
    Visited
};

// Node class
class Node {
public:
    int data; // You can replace this with any data type
    State state;
    vector<Node*> adjacent; // List of adjacent nodes

    Node(int value) : data(value), state(Unvisited) {}

    void addAdjacent(Node* node) {
        adjacent.push_back(node);
    }

    vector<Node*> getAdjacent() {
        return adjacent;
    }
};

// Graph class
class Graph {
private:
    vector<Node*> nodes;

public:
    void addNode(Node* node) {
        nodes.push_back(node);
    }

    vector<Node*> getNodes() {
        return nodes;
    }
};

// Function to perform BFS and check if there's a path between `start` and `end`
bool search(Graph& g, Node* start, Node* end) {
    if (start == end) {
        return true;
    }

    // Initialize all nodes to Unvisited
    for (Node* node : g.getNodes()) {
        node->state = Unvisited;  // Reset all states before search
    }

    // Queue for BFS
    queue<Node*> q;
    start->state = Visiting;
    q.push(start);

    while (!q.empty()) {
        Node* u = q.front();
        q.pop();

        if (u != nullptr) {
            for (Node* v : u->getAdjacent()) {
                if (v->state == Unvisited) {
                    if (v == end) {
                        return true;
                    } else {
                        v->state = Visiting;
                        q.push(v);
                    }
                }
            }
            u->state = Visited;  // Mark the node as visited after processing
        }
    }
    return false;
}

// Example usage
int main() {
    // Create nodes
    Node* nodeA = new Node(1);
    Node* nodeB = new Node(2);
    Node* nodeC = new Node(3);
    Node* nodeD = new Node(4);

    // Connect nodes (directed graph)
    nodeA->addAdjacent(nodeB);
    nodeA->addAdjacent(nodeC);
    nodeB->addAdjacent(nodeD);
    nodeC->addAdjacent(nodeD);

    // Create a graph
    Graph g;
    g.addNode(nodeA);
    g.addNode(nodeB);
    g.addNode(nodeC);
    g.addNode(nodeD);

    // Search for a path between nodes
    cout << "Path exists from A to D: " << (search(g, nodeA, nodeD) ? "Yes" : "No") << endl;

    // Cleanup (optional)
    delete nodeA;
    delete nodeB;
    delete nodeC;
    delete nodeD;

    return 0;
}
