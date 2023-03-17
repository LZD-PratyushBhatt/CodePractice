#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
        Node* head;
    public:
        LinkedList(){
            head = NULL;
        }
    
    void insert(int data){
        Node *newNode = new Node(data);

        if(!head){
            head = newNode;
            return;
        }

        Node* cur = head;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = newNode;
        return;
    }
    
    int findMiddleElement(){
        if (!head)return -1000; // -1000 just in case LL is empty, so no middle element
        Node *slow = head;
        Node *fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
    int kthElementFromTheEnd(int k){
        if(!head)return -1000;
        Node *cur = head;
        Node* answer = head;
        int counter = 0;
        // 1->2
        // k = 2
        // 
        while(cur){
            if(++counter > k) {
                answer = answer->next;
            }
            cur = cur->next;
        }
        return answer->data;
    }
    void reverseList() {
        if(!head or !head->next)return;
        Node* cur = head;
        Node* prev = NULL;
        Node* snext = head;
        while(cur){
            snext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = snext;
        }
        head = prev;
    }

    void display(){
        Node* cur = head;
        while(cur!=NULL){
            printf("%d ", cur->data);
            cur = cur->next;
        }
    }
};



int main(){
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif
    
    LinkedList l1;
    int arr[] = {1,2};
    for(int x : arr){
        l1.insert(x);
    }
    l1.display();
    int data = l1.kthElementFromTheEnd(2);
    printf("\n%d", data);
    l1.reverseList();
    printf("\n");
    l1.display();
}