#include<bits/stdc++.h>
using namespace std;

class BSTNode{
    public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void createBST(BSTNode* &root, int data){
    if(root == NULL){
        root = new BSTNode(data);
        return;
    }
    if(data < root->data)
        createBST(root->left, data);
    else
        createBST(root->right, data);
}

 void display(BSTNode* root){
        if(root==NULL) return;
        display(root->left);
        printf("%d ",root->data);
        display(root->right);
    }

// bool checkValid(TreeNode* root, long long lb, long long ub){
//         if(root == NULL)return true;
//         if(root->val >= ub or root->val <= lb)return false;
//         bool x = checkValid(root->left, lb, root->val);
//         bool y = checkValid(root->right, root->val, ub);
//         return x & y;
//     }
    
// bool isValidBST(TreeNode* root) {
//     return checkValid(root, LLONG_MIN,LLONG_MAX);
// }

int main(){
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif

    BSTNode* root = NULL;
    vector<int> vec{3,4,11,56,22,90,111,444,44,123};

    for(int x: vec){
        createBST(root, x);
    }
    display(root);

}