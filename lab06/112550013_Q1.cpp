#include <iostream>
#include <queue>
#include <stack>

class Node {
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int d) : data(d), left(nullptr), right(nullptr) {}

    // Copy Constructor for deep copy
    Node(const Node& other) : data(other.data), left(nullptr), right(nullptr) {
        if (other.left) {
            left = new Node(*other.left);
        }
        if (other.right) {
            right = new Node(*other.right);
        }
    }

    // Destructor
    ~Node() {
        delete left;
        delete right;
    }
};

class BinaryTree {
public:
    Node *root;

    // Constructor
    BinaryTree() : root(nullptr) {}

    // Copy Constructor for deep copy
    BinaryTree(const BinaryTree& other) : root(nullptr) {
        if (other.root) {
            root = new Node(*other.root);
        }
    }

    // Destructor
    ~BinaryTree() {
        delete root;
    }

    // Insert a new node with level order traversal
    void insert(int data) {
        if(root == nullptr){
            root = new Node(data);
            return;
        }
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            if(cur->left == nullptr){
                cur->left = new Node(data);
                return;
            } else {
                q.push(cur->left);
            }
            if(cur->right == nullptr){
                cur->right = new Node(data);
                return;
            } else {
                q.push(cur->right);
            }
        }
    }

    void printInPreOrder() {
        if (!root) return;
        std::stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* cur = s.top();
            s.pop();
            if(cur != root){
                std::cout << ",";
            }
            std::cout << cur->data;
            if(cur->right != nullptr){
                s.push(cur->right);
            }
            if(cur->left != nullptr){
                s.push(cur->left);
            }
        }
        std::cout << std::endl;
    }

    void reverse() {
        if (!root) return;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            std::swap(cur->left, cur->right);
            if(cur->left != nullptr){
                q.push(cur->left);
            }
            if(cur->right != nullptr){
                q.push(cur->right);
            }
        }
    }
};

int main(void) {
    BinaryTree bt;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int data;
        std::cin >> data;
        bt.insert(data);
    }
    bt.printInPreOrder();
    bt.reverse();
    bt.printInPreOrder();

    BinaryTree bt2 = bt;
    bt2.printInPreOrder();
}