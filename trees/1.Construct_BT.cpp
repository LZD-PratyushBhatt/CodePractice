#include<bits/stdc++.h>
using namespace std;

// When you dont pass by refernce, you can change the values of the pointer,
// But you cant modify the pointers
// Meaning lets say you make a function like:
//  void funct(BSTNode* root){
//     root = new BSTNode(5);
// }
// Here lets say root is a root of a very big tree 
// Here you tried to change the root node structure, I mean tried fully overriding it, 
// its links(left, right would be set to NULL) and in this way if this operation was successful
// Your big tree root was now reduced to this one node tree with value 5
// But this is not allowed.

// ANother case, what allowed here without reference is:
//  void funct(BSTNode* root){
//     root->data = 5;
// }
// This will change the value of the root(topmost node) of your big tree to 5. Rest tree will remain same
// No links will be changed. 

// SO CONCLUSION. 
// If you pass root without reference(without &), then you can only change
// value of the nodes
// Any changes to overriding the nodes(like modifying links, means modifying the object its address)
// are not comsiderd, will be ignored totally.



// IF YOU WANT TO MODIFY/OVERRIDE, then pass by reference.
// Meaning lets say you make a function like:
//  void funct(BSTNode* &root){
//     root = new BSTNode(5);
// }
// Notice the &root, here root is passed by reference.
// Now lets say the root that is passed here in function by reference, is of a big tree
// That whole tree is gone now, now the new tree is just one node with value 5.


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

class BST{
    public:
    BSTNode *root;
    BST(){
        root = NULL;
    }

    void insertNode(BSTNode* &root, int data){
        if(!root) {
            root = new BSTNode(data);
            return;
        }
        if(data < root->data)insertNode(root->left, data);
        else insertNode(root->right, data);
    }

    void displayPre(BSTNode *root){
        if(!root)return;
        cout<<root->data<< " ";
        displayPre(root->left);
        displayPre(root->right);
    }

    void displayPost(BSTNode *root){
        if(!root)return;
        displayPost(root->left);
        displayPost(root->right);
        cout<<root->data<< " ";
    }

    void displayIn(BSTNode *root){
        if(!root)return;
        displayIn(root->left);
        cout<<root->data<< " ";
        displayIn(root->right);
    }

    void levelOrder(BSTNode *root){
        if(!root)return;
        queue<BSTNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            auto node = Q.front();
            cout<<node->data<<" ";
            Q.pop();
            if(node->left)Q.push(node->left);
            if(node->right)Q.push(node->right);
        }
    }

    void levelOrderEnhanced(BSTNode *root){
        if(!root)return;
        queue<BSTNode*> Q;
        Q.push(root);
        vector<vector<int>> level_order;
        while(!Q.empty()){
            vector<int> current_level;
            int size = Q.size();
            for(int i = 0;i<size;i++){
                auto node = Q.front();
                current_level.push_back(node->data);
                Q.pop();
                if(node->left)Q.push(node->left);
                if(node->right)Q.push(node->right);
            }
            level_order.push_back(current_level);
        }

        // Print the level order level by level
        for(auto vec : level_order){
            for(int x: vec)cout<<x<<" ";
            cout<<endl;
        }
    }

    void allIterative(BSTNode *root){
        stack<pair<BSTNode*, int>> S;
        vector<int> preorder;
        vector<int> postorder;
        vector<int> inorder;
        S.push({root, 0});
        while(!S.empty()){
            auto pp = S.top();
            if(pp.second == 0){ // node in preorder mode
                // Increase the state to 1
                S.pop();
                S.push({pp.first, 1});
                preorder.push_back((pp.first)->data);
                if((pp.first)->left) S.push({(pp.first)->left, 0});
            }
            else if(pp.second == 1){ // node in inorder mode
            // Increase the state to 2
                S.pop();
                S.push({pp.first, 2});
                inorder.push_back((pp.first)->data);
                if((pp.first)->right) S.push({(pp.first)->right, 0});
            }
            else if(pp.second == 2){ // node in postorder mode
                postorder.push_back((pp.first)->data);
                S.pop();
            }
        }
        // Print all tranversals
        // 1. Preorder
        for(int x: preorder)cout<<x<<" ";
        cout<<endl;
        // 2. Inorder
        for(int x: inorder)cout<<x<<" ";
        cout<<endl;
        // 3. PostOrder
        for(int x: postorder)cout<<x<<" ";
        cout<<endl;
    }

    int max_depth_BT(BSTNode *root){
        if(root == NULL)return 0;
        int left_height = max_depth_BT(root->left);
        int right_height = max_depth_BT(root->right);
        return 1 + max(left_height, right_height);
    }

    int check_if_balanced_tree(BSTNode* root){
        if(root == NULL)return 0;
        int left_height = check_if_balanced_tree(root->left);
        int right_height = check_if_balanced_tree(root->right);
        if(left_height == -1 or right_height == -1)return -1;
        if(abs(left_height - right_height) > 1) return -1;
        return 1 + max(left_height, right_height);
    }

    int diameter(BSTNode* root, int &maxi){
        // Longest path between any two nodes, may or may not pass via root.
        if(!root)return 0;
        int left_height = diameter(root->left, maxi);
        int right_height = diameter(root->right, maxi);
        maxi = max(maxi, left_height + right_height); // Current max path
        return 1 + max(left_height, right_height); // The current height
    }

    int max_path_sum(BSTNode* root, int &maxi){
        // Similar lines of the above one.
        if(!root)return 0;
        int left_sum = max_path_sum(root->left, maxi);
        int right_sum = max_path_sum(root->right, maxi);
        // IMPROTANT : Lets say left and right return negative, then ignore all these 
        // -ve from left and right and prefer to return 0, cause, its better to take 
        // Only the current node with 0 from left and right, and that will make the
        // sum larger than the one when we consider left and right negatives.(CAUTION!!)
        // For the cases where leaves are -ve
        if(left_sum < 0) left_sum = 0;
        if(right_sum < 0) right_sum = 0;
        maxi = max(maxi, left_sum + right_sum + root->data); // Current max path sum
        return root->data + max(left_sum, right_sum); // even if this becomes less/-ve still 
        // We need to have this, maybe right/left for the above node can make it max
    }

    void zig_zag_traversal(BSTNode* root){
        queue<BSTNode*> Q;
        Q.push(root);
        vector<vector<int>> zz_order;
        bool left_to_right = true;
        while(!Q.empty()){
            int size = Q.size();
            vector<int> vec(size);
            for(int i = 0; i < size; i++){
                BSTNode *cur_node = Q.front();
                Q.pop();
                int actual_index = left_to_right?i:size-i-1;
                vec[actual_index] = cur_node->data;
                if(cur_node->left)Q.push(cur_node->left);
                if(cur_node->right)Q.push(cur_node->right);
            }
            left_to_right = !left_to_right; // Toggle
            zz_order.push_back(vec);
        }
        // Print zig zag
        for(auto x: zz_order){
            for(int ele : x)cout<<ele<<" ";
            cout<<endl;
        }
    }

    bool check_if_leaf_node(BSTNode* node){
        if(node->left == NULL and node->right == NULL)return true;
        return false;
    }

    void get_left_side(BSTNode* root, vector<int> &btraversal){
        
        while(root and !check_if_leaf_node(root)){
            btraversal.push_back(root->data);
            if(root->left) root = root->left;
            else root=root->right;
        }
    }

    void get_bottom_side(BSTNode* root, vector<int> &btraversal){
        // Do preorder, left side leaves will come first, then right side leaves
        if(!root)return;
        if(check_if_leaf_node(root)){
            btraversal.push_back(root->data);
            return;
        }
        get_bottom_side(root->left, btraversal);
        get_bottom_side(root->right, btraversal);
    }

    void get_right_side(BSTNode* root, vector<int> &btraversal){
        // Do preorder, left side leaves will come first, then right side leaves
        vector<int> dum;
        while(root and !check_if_leaf_node(root)){
            dum.push_back(root->data);
            if(root->right) root = root->right;
            else root = root->left;
        }
        for(int i=dum.size()-1;i>=0;i--) btraversal.push_back(dum[i]);
    }

    vector<int> boundary_traversal(BSTNode* root){
        if(!root)return {};
        if(check_if_leaf_node(root)) return {root->data};
        vector<int> btraversal;
        btraversal.push_back(root->data);
        // Dont take leaf nodes in left and right side ones
        get_left_side(root->left, btraversal);
        get_bottom_side(root, btraversal);
        get_right_side(root->right, btraversal);
        return btraversal;
    }

    void vertical_order(BSTNode* root){
        map<int, vector<int>> hmap;
        queue<pair<BSTNode*, int>> Q;
        Q.push({root, 0});
        while(!Q.empty()){
            pair<BSTNode*, int> pp = Q.front();
            hmap[pp.second].push_back(pp.first->data);
            Q.pop();
            if((pp.first)->left) Q.push({pp.first->left, pp.second-1});
            if((pp.first)->right) Q.push({pp.first->right, pp.second+1});
        }
        for(auto it: hmap){
            cout<<it.first<<endl;
            for(int x: it.second) cout<<x<<" ";
            cout<<endl<<endl;
        }
    }

    void topView(BSTNode* root){
        map<int,int> hmap;
        queue<pair<BSTNode*, int>> Q;
        Q.push({root, 0});
        while(!Q.empty()){
            auto pp = Q.front();
            Q.pop();
            if(hmap.count(pp.second)==0) hmap[pp.second] = pp.first->data;
            if(pp.first->left)Q.push({pp.first->left, pp.second-1});
            if(pp.first->right)Q.push({pp.first->right, pp.second+1});
        }
        for(auto it: hmap) cout<<it.second<<" ";
    }

    void bottomView(BSTNode* root){
        map<int,int> hmap;
        queue<pair<BSTNode*, int>> Q;
        Q.push({root, 0});
        while(!Q.empty()){
            auto pp = Q.front();
            Q.pop();
            hmap[pp.second] = pp.first->data;
            if(pp.first->left)Q.push({pp.first->left, pp.second-1});
            if(pp.first->right)Q.push({pp.first->right, pp.second+1});
        }
        for(auto it: hmap) cout<<it.second<<" ";
    }

    void left_and_right_view(BSTNode* root){
        if(!root)return;
        vector<int> left, right;
        queue<BSTNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            int size = Q.size();
            for(int i = 0;i<size;i++){
                auto pp = Q.front();
                Q.pop();
                if(i == 0)left.push_back(pp->data);
                if(i == size-1)right.push_back(pp->data);
                if(pp->left)Q.push(pp->left);
                if(pp->right)Q.push(pp->right);
            }
        }
        cout<<"\nLeft view of the tree is: ";
        for(int x: left)cout<<x<<" ";
        cout<<"\nRight view of the tree is: ";
        for(int x: right)cout<<x<<" "; 
    }

    bool root_to_node(BSTNode* root, int node_val, vector<int> &path){
        if(!root) return false;
        // First let the left call finish, if it returns false,
        // then go to right call, else return from there, no need to explore right
        path.push_back(root->data);
        if(root->data == node_val)return true;
        bool left = root_to_node(root->left, node_val, path);
        bool right = root_to_node(root->right, node_val, path);
        // More faster way is if(root_to_node(root->left, node_val, path) or root_to_node(root->right, node_val, path))return true;
        // Cause if you found it on left, no need to go on right, unlike in this case, it will go to right
        if(left or right)return true; // if left and right both didnt have the required node
        // then it means this path is not the correct path, and next step remove this element
        path.pop_back(); // remove the last inserted
        return false;
    }

    BSTNode* LCA(BSTNode* root, int val1, int val2){
        if(!root)return NULL;
        if(root->data == val1 or root->data==val2)return new BSTNode(root->data);
        BSTNode* left = LCA(root->left, val1, val2);
        BSTNode* right = LCA(root->right, val1, val2);
        if(!left) return right;
        if(!right)return left;
        // YOu dont need to check for !left and !right, cause that returns NULL, and above first
        // if if(!left) have alreay handled that, for examples; lets say both are NULL, then 
        // YOu come inside the if as left==NULL, and you return right, which will be NULL anways.
        return root;
    }

    void max_width_of_BT(BSTNode* root){
        // Max width is the maximum width between two nodes in a level, considering its a 
        // complete tree, meaning if this is a tree:
                //       11
                //     3   2
                //   5        7
                // 22           17
        // Then max width is between 22 and 17, and its not 2, its 8, why?
        // //                  11
                //         3        2
                //      5    .    *    7
                //     22  @  @ #  # $  $  17
        // This way you have to assume its hypothetically filled like a complete BT, and then As we can see, 
        // width between 22 and 17 is 22-@-@-#-#-$-$-17 i.e. 8

        // Now one of the approach is to index the tree, for example this tree like:
        // //                    11(0)
                //         3(1)        2(2)
                //      5(3)    .    *    7(6)
                //    22(7)  @  @ #  # $  $  17(14)
        // Where if indexing is 0 based, and if parent has i index, childs has 2*i+1 and 2*i+2 index.
        // Now you can easily get the max width like 14-7+1 = 8

        // Now if we do this way, then we will reach Integer limit very fast, cause every next limit
        // is 2 times the integer value of the previpus level.

        // So, to prevent this we will do something like:
         // //                    11(0)
                //         3(1)->(1-1)=0        2(2) ->(2-1)=1
                //      5(3)->(3-3)=0    .    *     7(6)->(6-3)=3
                //    22(7)->(7-7)=0  @  @ #  # $  $  17(14)->(14-7)=7
        // Still 7-0+1 is 8. So what did we do here?
        // for the leftest index of a level, we know its the smallest for a level.
        // Then we make it 0 by subtracting its index from its index(for example in level 2,
        // We do 1-1 to make it 0), now for every other node of that level, we subtract the index of that
        // Node by this leftest node index, for example, in level 2, 2(2) now became 2(2-1) and its 
        // index became 1, follow this for every level.

        queue<pair<BSTNode*,int>> Q;
        Q.push({root, 0});
        int maxi = 0;
        while(!Q.empty()){
            int size = Q.size();
            int current_min = Q.front().second; //initially its 0, for every level it will be the min
            // since, leftest available node will have lowest id. Not necessarily it will be 0 in all
            // cases, cause suppose leftest node is not there, then it can be anything >0
            int leftest = -1;
            int rightest = -1;
            for(int i = 0;i<size;i++){
                auto pp = Q.front();
                Q.pop();
                int current_idx = pp.second - current_min; // Based on that index overflow logic, subtract by the 
                // Minimum index possible for that level.
                if(i==0) leftest = current_idx; // for level 1, it will be 0 in the first iteration.
                if(i==size-1) rightest = current_idx; // for level 1, it will be 0 in the first iteration.
                if(pp.first->left)
                    Q.push({pp.first->left, pp.second*2+1});
                if(pp.first->right)
                    Q.push({pp.first->right, pp.second*2+2});
            }
            maxi = max(maxi, rightest-leftest+1);
        }
        printf("\n%d\n", maxi);
    }

    void childern_sum_property(BSTNode* root){
        // Disclaimer: You can increase the value of a node as much as you want.(Cant decrease)

        // The goal is when you are going down, if left + right < current_node_val, 
        // Then make left = right = current_node_val, and if left+ right > current_node_val
        // Then make current_node_val rn as left+right
        // And when you are coming up, make current_node_val as left+right in all cases, whether
        // going down it followed first case or second. 
        // The reason is, while going down, you're making sure The childrens follow the property
        // By giving them a proper value, and while coming back youre making sure, parent 
        // is greater than their sum.
        // THis is Linear, cause The problem doesnt mention do it with the least cost.

        if(!root) return;
        int child_sum = 0;
        if(root->left) child_sum+=root->left->data;
        if(root->right) child_sum+=root->right->data;
        if(child_sum >= root->data) root->data = child_sum;
        else{
            if(root->left) root->left->data = root->data;
            if(root->right) root->right->data = root->data;
        }
        childern_sum_property(root->left);
        childern_sum_property(root->right);

        int tot = 0;
        if(root->left)tot+=root->left->data;
        if(root->right)tot+=root->right->data;
        if(!check_if_leaf_node(root)) root->data = tot;
    }

    pair<unordered_map<BSTNode*, BSTNode*>, BSTNode*> mark_parents_and_get_targetNode(BSTNode* root, int target){
        unordered_map<BSTNode*, BSTNode*> hmap;
        BSTNode* temp = NULL;
        queue<BSTNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            int size = Q.size();
            for(int i = 0;i<size;i++){
                auto node = Q.front();
                if(node->data == target) temp = node;
                Q.pop();
                if(node->left){
                    hmap[node->left] = node;
                    Q.push(node->left);
                }
                if(node->right){
                    hmap[node->right] = node;
                    Q.push(node->right);
                }
            }
        }
        return {hmap, temp};
    }

    vector<int> nodes_at_distance_k(BSTNode* root, int target, int distance){
        auto result = mark_parents_and_get_targetNode(root, target);
        unordered_map<BSTNode*, BSTNode*> parent_nodes = result.first;
        // Printing parents for every node
        // for(auto it: parent_nodes){
        //     cout<<it.first->data<<": "<<it.second->data;
        //     cout<<endl;
        // }

        BSTNode* target_node = result.second;
        int current_distance = 0;
        vector<int> k_distanced_nodes;
        unordered_set<BSTNode*> visited;
        queue<BSTNode*> Q;
        Q.push(target_node); //  insert the node
        visited.insert(target_node); // mark it visited
        while(!Q.empty()){
            int size = Q.size();
            if(current_distance == distance) break;
            for(int i=0;i<size;i++){
                auto node = Q.front();
                Q.pop();
                if(node->left and visited.count(node->left)==0){
                    Q.push(node->left);
                    visited.insert(node->left);
                }
                 if(node->right and visited.count(node->right)==0){
                    Q.push(node->right);
                    visited.insert(node->right);
                }
                if(parent_nodes.count(node) and visited.count(parent_nodes[node])==0){
                    Q.push(parent_nodes[node]);
                    visited.insert(parent_nodes[node]);
                }
            }
            current_distance++;
        }
        while(!Q.empty()){
            k_distanced_nodes.push_back(Q.front()->data);
            Q.pop();
        }
        return k_distanced_nodes;
    }

};

bool check_identical_trees(BSTNode *root1, BSTNode* root2){
    //  Can be solved by any traversal, I'm doing POST order, L R V
    if(!root1 or !root2) return root1==root2; // if both not NULL, will return false
    bool left_side = check_identical_trees(root1->left, root2->left);
    bool right_side = check_identical_trees(root1->right, root2->right);
    return (root1->data == root2->data) & left_side & right_side;
}

bool check_symmentrical_tree(BSTNode* root){
    if(!root)return true;
    return check_identical_trees(root->left, root->right);
}

int main(){
    BST t1;
    vector<int> vec{3,4,11,56,22,90,111,444,44,123};

    // 3 
    //   4 
    //     11 
    //         56 
    //       22   90 
    //        44       111 
    //                        444 
    //                      123 
    for(int x: vec) t1.insertNode(t1.root, x);

    cout<<endl<<(t1.root)->data<<endl;
    t1.displayPre(t1.root);
    cout<<endl;
    t1.displayIn(t1.root);
    cout<<endl;
    t1.displayPost(t1.root);
    cout<<endl;
    t1.levelOrder(t1.root);
    cout<<endl<<endl;
    t1.levelOrderEnhanced(t1.root);
    cout<<endl<<endl;
    t1.allIterative(t1.root);
    int tree_height = t1.max_depth_BT(t1.root);
    cout<<"\n\nTree height is : "<<tree_height<<endl;

    int is_balanced = t1.check_if_balanced_tree(t1.root);
    cout<<"\n Is Tree balanced? if -1 then no if >=0 then yes : " <<is_balanced<<endl; 

    int diameter_tree = 0;
    t1.diameter(t1.root, diameter_tree);
    cout<<"\n\n Diameter of the tree is : "<<diameter_tree<<endl;

    int max_sum = 0;
    t1.max_path_sum(t1.root, max_sum);
    cout<<"\n\n Max path sum is : "<< max_sum<<endl;

    BST t2,t3;
    vector<int> vec2 = {3,4,11,56};
    vector<int> vec3 = {3,4,111,56};
    for(int x: vec2)t2.insertNode(t2.root, x);
    for(int x: vec3)t3.insertNode(t3.root, x);

    bool check_sym = check_identical_trees(t2.root, t3.root);
    cout<<"\n\n Identical trees? : "<< check_sym<<endl;

    cout<<"\n\n Zig Zag Traversal is : "<<endl;
    t1.zig_zag_traversal(t1.root);

    cout<<"\n\n Boundary traversal: \n";
    vector<int> btrav = t1.boundary_traversal(t1.root);
    for(int x: btrav)cout<<x<<" ";

    cout<<"\n\n Vertical order traversal: \n";
    t1.vertical_order(t1.root);

    cout<<"\n\nTop view of BT\n";
    t1.topView(t1.root);

    cout<<"\n\nBottom view of BT\n";
    t1.bottomView(t1.root);

    cout<<"\n\nLeft and Right view of the Tree\n";
    t1.left_and_right_view(t1.root);

    cout<<"\n\nCheck if Binary tree is symmetrical, 0 no 1 yes: ";
    cout<<check_symmentrical_tree(t1.root);

    cout<<"\n\nGet the path from root to node: \n";
    vector<int> path;
    t1.root_to_node(t1.root, 123, path);
    for(int x: path)cout<<x<<" ";

    cout<<"\nFInding LCA of two nodes, 44 and 444: ";
    cout<<t1.LCA(t1.root, 44, 444)->data;

    cout<<"\n\nMaximum width of Binary tree: \n";
      // 3(0) 
    //         4(2) 
    //            11(6) 
    //                56(14) 
    //           22(29)      90(30) 
    //              44(60)       111(62) 
    //                                 444(126)
    //                              123(253) 
    t1.max_width_of_BT(t1.root);

    cout<<"\n\nConverting tree in accordance to children sum property: \n";
    BST child_sum;
    // child_sum.root = t1.root; Tree copy doesnt work like that, its still the same address
    // If you think child.root operations will not effect t1.root structure, you're wrong
    // Cause essentially child_sum.root is same as t1.root, all address all pointers, everything is same
    // Just name of variable is different.
    // You will have to create a new tree
    for(int x: vec) child_sum.insertNode(child_sum.root, x);
    child_sum.childern_sum_property(child_sum.root);

    // If you do it like child_sum.root = t1.root; then levelOrderEnhanced traversal for both(see below) would have been same
    // meaning child sum would have impacted t1 object too, cause of above explanation.
    // Now they both are different.
    child_sum.levelOrderEnhanced(child_sum.root);
    cout<<endl<<endl;
    t1.levelOrderEnhanced(t1.root);

    cout<<"\n\nNodes at distance K from target node, lets sayyy distance 2 from 56\n";
    vector<int> result = t1.nodes_at_distance_k(t1.root, 56, 2);
    for(int x: result)cout<<x<<" ";

}