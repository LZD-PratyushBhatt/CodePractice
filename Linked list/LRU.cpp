#include<bits/stdc++.h>
using namespace std;

class LRUDLL{
    public:
        int key;
        int value;
        LRUDLL *next;
        LRUDLL *prev;
        LRUDLL(int key, int val){
            this->key = key;
            this->value = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

class LRU{
    public:
        LRUDLL *head;
        LRUDLL *tail;
        int lru_size;
        unordered_map<int, LRUDLL*> hashmap;
        LRU(int size){
            head = new LRUDLL(-1,-1);
            tail = new LRUDLL(-2,-2);
            head->next = tail;
            tail->prev = head;
            this->lru_size = size;
        }

        void rearrange(int key, int value){
            // Earlier the DLL would be like HEAD -><- old_node -><-......
            // This new node will come just after the HEAD, like HEAD -><- new_node -><- old_node......
            LRUDLL *new_node = new LRUDLL(key, value); // make a new node
            new_node->next = head->next; // since the node that was earlier next to head is moved to right by one place
            // and our new node is coming to its place, that old node will be to the next of this node,
            // Hence this step.
            head->next->prev = new_node; // By doing head->next you are going to the old node, that was earlier
            // just to the next of head, and when you do ->prev of that, its same as doing, old_node->prev and since that 
            // node is after our new node, its prev will point to our new_node
            head->next = new_node; // head's next  now points to this new node
            new_node->prev = head; // this new node's previous now points to head
            hashmap[key] = new_node; // store this node in hashmap.
        }

        void put(int key, int value){
            if(hashmap.count(key)){ // if key is present in the hashmap.
                LRUDLL* node = hashmap[key]; // retrieve the node from the hashmap
                node->prev->next = node->next; // that node's previous's next will point to the node's next
                node->next->prev = node->prev; // That node's next's previous will point to node's prev
                // WHY? because say DLL was like ...-><- node1 -><- node -><- node2 -><-... , now you want this node to be gone and
                // final result you want like ...-><- node1 -><- node2 -><- .... for this you need to change the 
                // pointers, so node->prev in first statement will give you node1, and you now want its next, i.e.
                // node1->next to be pointing to node2 which is nothing but node->next.
                //  Similarly, node->next in second statement gives you node2, and now you want is prev, i.e.,
                // node2->prev to be pointing to node1 which is nothing but node->prev;
                delete node; // Then delete the old node.
                hashmap.erase(key); // Remove it from hashmap
                rearrange(key, value); // Call the rearrange function
            }
            else{
                if(hashmap.size() == lru_size){
                    // When LRU reaches its capacity, remove the element that is previous to the TAIL pointer.
                    int to_delete_key = tail->prev->key; // Get the value of key previous to tail, to
                    // delete it from the hashmap.
                    hashmap.erase(to_delete_key);
                    // Lets say the DLL was like ....-><- node2 -><- node1 -><- TAIL, now LRU is full, so you will
                    // remove node1 as its the nearest of TAIL. We want the final result like: 
                    // ....-><- node2 -><- TAIL, by doing node1->prev you get nothing but node2, and again when you do a ->next
                    // its same as node2->next, you want the next of node2 to be pointing to TAIL directly.
                    // for the second statement tail->prev you want to point to node2 ultimately, and node1->prev gives you node2 only.
                    LRUDLL* node1 = tail->prev;
                    delete node1; // delete the node to avoid memory leak
                    node1->prev->next = tail;
                    tail->prev = node1->prev;
                    
                    rearrange(key, value);  // call the rearrange function.
                    
                }
                else{
                    // if capacity is not full and key is not present in the hashmap, 
                    // just insert a new node next to HEAD.
                    rearrange(key, value); // call the rearrange function.
                }
            }
        }

        int get(int key){
            // When you access a key and if it is present, it becomes the most recently used,
            // and then it will be taken next to HEAD.
            if(hashmap.count(key)){ // key is there 
                int result = hashmap[key]->value; // get the result
                LRUDLL* node = hashmap[key]; // get the node
                // Same explanation as line 48.
                node->prev->next = node->next;
                node->next->prev = node->prev;
                delete node;
                hashmap.erase(key);
                rearrange(key, result);
                return result;
            }
            return -1;
        }

        void display_lru(LRUDLL* head){
            LRUDLL* temp = head;
            while(temp){
                cout<<temp->key<<":"<<temp->value<<endl;
                temp=temp->next;
            }
        }
};

int main(){
    LRU l1(2); // LRU cache of size 2
    cout<<"Doing a put of key 1 and value 15\n";
    l1.put(1,15);
    cout<<"Doing a put of key 2 and value 222\n";
    l1.put(2,222);
    cout<<"\nLRU Cache is looking like: \n";
    l1.display_lru(l1.head);
    cout<<"\nHashmap content is :\n";
    for(auto x: l1.hashmap) cout<<x.first<<" "<<x.second<<endl;
    cout<<endl;
    int result = l1.get(1);
    cout<<"The get query result is : "<<result<<endl;
    cout<<"\nLRU Cache is looking like: \n";
    l1.display_lru(l1.head);
    cout<<"\nHashmap content is :\n";
    for(auto x: l1.hashmap) cout<<x.first<<" "<<x.second<<endl;
    cout<<endl;
    cout<<"Doing a put of key 3 and value 30\n";
    l1.put(3,30);
    cout<<"\nLRU Cache is looking like: \n";
    l1.display_lru(l1.head);
    cout<<"\nHashmap content is :\n";
    for(auto x: l1.hashmap) cout<<x.first<<" "<<x.second<<endl;
    cout<<endl;
    result = l1.get(2);
    cout<<"The get query result is : "<<result<<endl;
    cout<<"\nLRU Cache is looking like: \n";
    l1.display_lru(l1.head);
    cout<<"\nHashmap content is :\n";
    for(auto x: l1.hashmap) cout<<x.first<<" "<<x.second<<endl;
    cout<<endl;
    cout<<"Doing a put of key 4 and value 44\n";
    l1.put(4,44);
    cout<<"\nLRU Cache is looking like: \n";
    l1.display_lru(l1.head);
    cout<<"\nHashmap content is :\n";
    for(auto x: l1.hashmap) cout<<x.first<<" "<<x.second<<endl;
    cout<<endl;
    result = l1.get(1);
    cout<<"The get query result is : "<<result<<endl;
    cout<<"\nLRU Cache is looking like: \n";
    l1.display_lru(l1.head);
    cout<<"\nHashmap content is :\n";
    for(auto x: l1.hashmap) cout<<x.first<<" "<<x.second<<endl;
    cout<<endl;
    result = l1.get(3);
    cout<<"The get query result is : "<<result<<endl;
    cout<<"\nLRU Cache is looking like: \n";
    l1.display_lru(l1.head);
    cout<<"\nHashmap content is :\n";
    for(auto x: l1.hashmap) cout<<x.first<<" "<<x.second<<endl;
    cout<<endl;
    result = l1.get(4);
    cout<<"The get query result is : "<<result<<endl;
    cout<<"\nLRU Cache is looking like: \n";
    l1.display_lru(l1.head);
    cout<<"\nHashmap content is :\n";
    for(auto x: l1.hashmap) cout<<x.first<<" "<<x.second<<endl;
    cout<<endl;
}