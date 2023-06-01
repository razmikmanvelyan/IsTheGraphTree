#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

#define LIMIT_FOR_SMALL_GRAPH 10

class Node {
public:
    int id;
    std::vector<Node*> neighbors;

    Node(int id) : id(id) {}

    void addNeighbor(Node* neighbor) {
        neighbors.push_back(neighbor);
    }
};

class Edge {
public:
    Node* from;
    Node* to;
    int weight;
    Edge(Node* from, Node* to, int weight) : from(from), to(to), weight(weight) {}
};

class Graph {
public:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
    std::vector<bool> visited;
    Graph() {}

    Graph(int numOfNodes) {
        for (int i = 0; i < numOfNodes; i++) {
            this->addNode(i);
        }
    }

    Graph(std::vector<Node*>& nodes, std::vector<Edge*>& edges) : nodes(nodes), edges(edges)
    {}

    ~Graph() {
        for(Node* node : this->nodes){
            delete node;
        }
        
        for(Edge* edge : this->edges){
            delete edge;
        }
    }

    void addNode(Node* node) {
        nodes.push_back(node);
    }

    void addNode(int nodeIndex) {
        nodes.push_back(new Node(nodeIndex));
    }
    
    void addEdge(Edge* edge) {
        edges.push_back(edge);
    }

    void addEdge(int fromNodeIndex, int toNodeIndex, int weight) {
        Node* from = nodes[fromNodeIndex - 1];
        Node* to = nodes[toNodeIndex - 1];
        Edge* edge = new Edge(from, to, weight);
        from->addNeighbor(to);
        to->addNeighbor(from);
        edges.push_back(edge);
    }
    
    void addEdge(Node* fromNode, Node* toNode, int weight) {
        Edge* edge = new Edge(fromNode, toNode, weight);
        fromNode->addNeighbor(toNode);
        toNode->addNeighbor(fromNode);
        edges.push_back(edge);
    }

    bool checkTree() {
        if (edges.size() != nodes.size() - 1) {
            return false;
        }
        this->visited = std::vector<bool>(nodes.size(), false);

        if(nodes.size() > LIMIT_FOR_SMALL_GRAPH){
            // with BFS
            std::queue<Node*> queue;
            queue.push(nodes[0]);
            visited[nodes[0]->id] = true;
            bfs(queue);
            // end with BFS
        }
        else{
            // with DFS
            std::stack<Node*> stack;
            stack.push(nodes[0]);
            visited[nodes[0]->id] = true;
            dfs(stack);
            // end with DFS
        }
        for (int i = 0; i < nodes.size(); i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
    void dfs(std::stack<Node*>& stack) {
        while (!stack.empty()) {
            Node* current = stack.top();
            stack.pop();

            for (Node* neighbor : current->neighbors) {
                if (!visited[neighbor->id]) {
                    stack.push(neighbor);
                    visited[neighbor->id] = true;
                }
            }
        }
    }
    void bfs(std::queue<Node*>& queue) {
        while (!queue.empty()) {
            Node* current = queue.front();
            queue.pop();

            for (Node* neighbor : current->neighbors) {
                if (!visited[neighbor->id]) {
                    queue.push(neighbor);
                    visited[neighbor->id] = true;
                }
            }
        }
    }

    int getLeavesCount() const{
        int count = 0;
        for (Node* node : this->nodes) {
            if (node->neighbors.size() == 1) {
                count++;
            }
        }
        return count;
    }
    int getHeight(Node* node) const{
        if (node == nullptr) {
            return 0;
        }
        
        int maxHeight = 0;
        for (int i = 1; i < node->neighbors.size(); ++i){
            int height = getHeight(node->neighbors[i]);
            maxHeight = std::max(maxHeight, height);
        }
        
        return maxHeight + 1;
    }

    int getTreeHeight() const{
        if (this->nodes.empty()) {
            return 0;
        }
        
        return getHeight(this->nodes[0]);
    }
};
