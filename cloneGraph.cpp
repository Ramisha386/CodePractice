#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> clones;
    
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        return dfs(node);
    }

    Node* dfs(Node* node) {
        if (clones.find(node) != clones.end())
            return clones[node];

        Node* copy = new Node(node->val);
        clones[node] = copy;

        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor));
        }

        return copy;
    }
};

// Helper function to print the graph (BFS)
void printGraph(Node* node) {
    if (!node) return;

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << "Node " << curr->val << " neighbors: ";
        for (Node* neighbor : curr->neighbors) {
            cout << neighbor->val << " ";
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        cout << endl;
    }
}

int main() {
    // Build a sample graph
    // 1 -- 2
    // |    |
    // 4 -- 3

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    cout << "Original graph:" << endl;
    printGraph(node1);

    Solution sol;
    Node* clonedGraph = sol.cloneGraph(node1);

    cout << "\nCloned graph:" << endl;
    printGraph(clonedGraph);

    return 0;
}
