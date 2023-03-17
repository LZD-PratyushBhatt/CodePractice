#include<bits/stdc++.h>
using namespace std;

class BinaryTree{
    public:
    int data;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int data){
        this->data = data;
        left = right = NULL;
    }
};

 void display(BinaryTree* root){
        if(root==NULL) return;
        printf("%d ",root->data);
        display(root->left);
        display(root->right);
    }

void invertTree(BinaryTree* root){
    if(!root)return;
    invertTree(root->left);
    invertTree(root->right);
    BinaryTree* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void invertTreeIterative(BinaryTree* root){
    stack<pair<BinaryTree*,int>> S;
    S.push({root, 1});
    while(!S.empty()){
        auto pp = S.top();
        auto node = pp.first;
        int counter = pp.second;
        if(counter == 1){
            S.pop();
            S.push({node, 2});
            if(node->left)S.push({node->left, 2});
        } 
        else if(counter == 2){
            S.pop();
            S.push({node, 3});
            if(node->right)S.push({node->right, 3});
        }
        else {
            S.pop();
            BinaryTree* temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
    }
}

vector<vector<int>> traversalIterative(BinaryTree* root){
    stack<pair<BinaryTree*,int>> S;
    S.push({root, 1});
    vector<int> preorder,postorder,inorder;
    while(!S.empty()){
        auto pp = S.top();
        if(pp.second == 1){
            preorder.push_back(pp.first->data);
            S.pop();
            S.push({pp.first, 2});
            if((pp.first)->left)
                S.push({(pp.first)->left, 1});
        }
        else if(pp.second == 2){
            inorder.push_back(pp.first->data);
            S.pop();
            S.push({pp.first, 3});
            if((pp.first)->right)
                S.push({(pp.first)->right, 1});
        }
        else {
            postorder.push_back(pp.first->data);
            S.pop();
        }
    }
    return {preorder, postorder, inorder};
}

void levelOrder(BinaryTree* root){
    queue<BinaryTree*> Q;
    Q.push(root);
    while(!Q.empty()){
        auto it = Q.front();
        printf("%d ", it->data);
        Q.pop();
        if(it->left)Q.push(it->left);
        if(it->right)Q.push(it->right);
    }
}

void verticalOrder(BinaryTree* root){
    map<int, vector<int>> hmap;
    queue<pair<BinaryTree*,int>> Q;
    // hmap[root] = 0;
    Q.push({root, 0});
    while(!Q.empty()){
        auto it = Q.front();
        auto node = it.first;
        int height = it.second;
        hmap[height].push_back(node->data);
        Q.pop();
        if(node->left){
            Q.push({node->left, height-1});
        }
        if(node->right){
            Q.push({node->right, height+1});
        }
    }
    // Print the VOT
    for(auto it: hmap){
        for(int x: it.second) cout<<x<<" ";
    }
}

 void returnPathToLeaf(BinaryTree* root, vector<string> &paths, string current_output){
        if(root == NULL){
            return;
        }
        if(!root->left and !root->right){
            current_output.append(to_string(root->data));
            paths.push_back(current_output);
            return;
        }
        current_output = current_output.append(to_string(root->data));
        current_output = current_output.append("->");
        returnPathToLeaf(root->left, paths, current_output);
        returnPathToLeaf(root->right, paths, current_output);   
    }


int main(){
        #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(5);
    root->left->left = new BinaryTree(10);
    root->left->right = new BinaryTree(11);
    root->left->left->right = new BinaryTree(222);
    root->left->left->left = new BinaryTree(111);
    root->right->left = new BinaryTree(21);
    root->right->right = new BinaryTree(15);
    root->right->left->left = new BinaryTree(333);
    root->right->right->left = new BinaryTree(150);
    root->right->right->right = new BinaryTree(33);

    // Simple preorder iterative
    printf("\nSimple preorder traversal\n");
    display(root);
    printf("\n");
    
    // Level order traversal
    printf("\nLevel order traversal\n");
    levelOrder(root);

    // Vertical Order Traversal
    printf("\nVertical Order Traversal\n");
    verticalOrder(root);

    // invertTreeI(root);
    // printf("\nTree Inverted\n");
    // invertTreeIterative(root);

    // display(root);
    
    // 1 2 10 11 5 21 15 
    // 1 5 15 21 2 11 10 


    // ALL THE TRAVERSALS IN ITERATIVE MODE
    printf("\n\n");
    auto it = traversalIterative(root);
    auto v1 = it[0];
    auto v2 = it[1];
    auto v3 = it[2];

    // Preorder
    for(int x: v1)printf("%d ", x);
    printf("\n\n");
    // Postorder
    for(int x: v2)printf("%d ", x);
    printf("\n\n");
    // Inorder
    for(int x: v3)printf("%d ", x);
    printf("\n\n");

}