#include<iostream>
using namespace std;

struct TreeNode{
    int value;
    TreeNode *lchild, *rchild;
    TreeNode(int v): value(v), lchild(NULL), rchild(NULL) {}
};

TreeNode* insert(TreeNode* node, int value){
    //TO-DO
    if(node == NULL){
        return new TreeNode(value);
    }

    if(value < node->value){
        node->lchild = insert(node->lchild, value);
    }
    else{
        node->rchild = insert(node->rchild, value);
    }
    return node;
}

void inOrder(TreeNode* node){
    //TO-DO
    if(node != NULL){
        inOrder(node->lchild);
        cout << node->value << " ";
        inOrder(node->rchild);
    }
}

void preOrder(TreeNode* node){
    //TO-DO
    if(node != NULL){
        cout << node->value << " ";
        preOrder(node->lchild);
        preOrder(node->rchild);
    }
}

void postOrder(TreeNode* node){
    //TO-DO
    if(node != NULL){
        postOrder(node->lchild);
        postOrder(node->rchild);
        cout << node->value << " ";
    }
}

int main(){
    int n;
    cin >> n;

    //TO-DO
    TreeNode* root = NULL;
    int val;
    
    for(int i = 0; i < n; i++){
        cin >> val;
        root = insert(root, val);
    }

    cout << "InOrder traversal: ";
    inOrder(root);
    cout << endl;

    cout << "PreOrder traversal: ";
    preOrder(root);
    cout << endl;

    cout << "PostOrder traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}