//insert node
//search a node
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    node *left;
    node *right;
    int data;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
bool search(node *root,int val){
    if(root->data==val)return true;

    while(!root && root->data!=val){
    root=root->data>val?root->left:root->right;}
 return false;
}
node *insert(node *root,int val){
    if(!root)return new node(val);
    node *cur=root;
    while(true){
    if(cur->data>=val){
        if(cur->left){cur=cur->left;}
        else{
            cur->left=new node(val);
            break;
        }
    }
    else{
        if(cur->right){cur=cur->right;}
        else{
            cur->right=new node(val);
            break;
        }}
    }return root;
}
void levelordeprint(node *root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node *n=q.front();
        cout<<n->data<<" ";
        q.pop();
        if(n->left)q.push(n->left);
        if(n->right)q.push(n->right);
    }
}

// My addition
void levelOrderEnhanced(node *root){
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        int size = Q.size();
        for(int i=0;i<size;i++){
            auto pp = Q.front();
            Q.pop();
            cout<<pp->data<<" ";
            if(pp->left)Q.push(pp->left);
            if(pp->right)Q.push(pp->right);
        }
        cout<<endl;
    }
}
void inorder(node *root){
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node *root=NULL;
    // root=insert(root,10);
    // insert(root,30);
    // insert(root,20);
    vector<int> nodes{10,30,20,9,16};
    for(int x: nodes) root = insert(root, x);
    // levelordeprint(root);
    levelOrderEnhanced(root);
    cout<<endl;
    cout<<"SEARCH"<<endl;
    cout<<search(root,30)<<endl;
    cout<<"\n\nINORDER PRINT\n";
    inorder(root);
}