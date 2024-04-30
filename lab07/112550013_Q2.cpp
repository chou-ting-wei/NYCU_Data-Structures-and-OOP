#include<iostream>
using namespace std;
struct TreeNode{
    int value,height;
    TreeNode *lchild,*rchild;
    TreeNode(int v):value(v),height(1),lchild(NULL),rchild(NULL){}
};

int getHeight(TreeNode* root){
	// TODO
    if(!root) return 0;
    return root->height;
}

int getbalanceFactor(TreeNode* root){
    // TODO
    if(!root) return 0;
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(TreeNode* root){
    // TODO
    root->height = 1 + max(getHeight(root->lchild), getHeight(root->rchild));
}

// Rotate Left
void L(TreeNode* &root){
	// TODO
    if(!root) return;
    TreeNode* rchild = root->rchild;
    root->rchild = rchild->lchild;
    rchild->lchild = root;
    updateHeight(root);
    updateHeight(rchild);
    root = rchild;
}

// Rotate Right
void R(TreeNode* &root){
	// TODO
    if(!root) return;
    TreeNode* lchild = root->lchild;
    root->lchild = lchild->rchild;
    lchild->rchild = root;
    updateHeight(root);
    updateHeight(lchild);
    root = lchild;
}

void insert(TreeNode* &root,int v){
    if(root == NULL){
        root = new TreeNode(v);
        return;
    }
    if(v < root->value){
		// TODO
        insert(root->lchild, v);
    }else{
		// TODO
        insert(root->rchild, v);
    }
    updateHeight(root);

    int bal = getbalanceFactor(root);

    // LL
    if (bal > 1 && v < root->lchild->value){
        R(root);
    }
    // RR
    else if (bal < -1 && v > root->rchild->value){
        L(root);
    }
    // LR
    else if (bal > 1 && v > root->lchild->value){
        L(root->lchild);
        R(root);
    }
    // RL
    else if (bal < -1 && v < root->rchild->value){
        R(root->rchild);
        L(root);
    }
}

int main(){
    int n,tmp;
    TreeNode* root = NULL;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&tmp);
        insert(root,tmp);
    }
    printf("%d\n",root->value);
    return 0;
}