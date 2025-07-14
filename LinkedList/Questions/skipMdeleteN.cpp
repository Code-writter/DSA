#include<iostream>
using namespace std;

class Node{
    public : 
    int data;
    Node* next;

    // Default Constructor
    Node(){
        this-> next = NULL;
    }

    // Parameterized Constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};

void print(Node* zero){
    // Note:Always make a temperory pointer to traverse the LL
    Node* temp = zero;

    while(temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }   
}

int lengthCount(Node* head){
    Node* temp = head;
    int count = 0;
   // While temp not equal to null 
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }

    return count;
}

// Note: stat node should be pass as a reference
void insertAtHead(Node* &head,Node* &tail ,int data){

    // Check empty linked List

    if(head == NULL){
        // Create new Node
        Node* newNode = new Node(data);
        // Upate head
        head = newNode;
        tail = newNode;
        return;
    }

    // create a new node
    Node* newNode = new Node(data);

    // Attach to the head
    newNode -> next = head;

    // make new node head
    head = newNode;
    return;
}

void insertAtTail(Node* & head, Node* &tail, int data){
    // Edge case
    if(head == NULL){
        // create new node
        Node* newNode = new Node(data);

        tail = newNode;
        head = newNode;
        return;
    }

    // Create new Node
    Node* newNode = new Node(data);

    tail -> next = newNode;
    tail = newNode;

    return;
}

void createTail(Node* & head, Node* & tail, int data){
    Node* temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    tail = temp;
    return;
}

void insetAtPos(Node* &head, Node* &tail, int data, int pos){
    if(pos < 1){
        cout<<"Cannot Insert"<<endl;
    }
    int length = lengthCount(head);

    if(pos <= 1){
        insertAtHead(head, tail, data);
        return;
    }
    else if(pos >= length){
        insertAtTail(head, tail, data);
        return;
    }
    else{
            // Create a node
        Node* temp = head;

        Node* prev = NULL;
        Node* curr = head;

        while(pos != 1){
            prev = curr;
            curr = curr -> next;
            pos--;
        }
        temp -> next = curr;
        prev -> next =  temp;

        return;
    }    
}

Node* skipMDeleteN(Node* head, int M, int N){
    if(!head) return;

    Node* it = head;

    // Reaching the M node
    for(int i = 0; i<M-1; i++){
        if(!it) return;
        it = it -> next;
    }

    if(!it) return;

    // peg the current Node
    Node* MthNode = it;
    it = it -> next;

    // Now delete the Nth nodes
    for(int i = 0; i<N; i++){
        if(!it) return;

        // peg the Next to it
        Node* temp = it -> next;
        delete(it);
        it = temp;
    }

    // Rejoin the pointer with the Mth Node
    MthNode -> next = it;
    return skipMDeleteN(it, M, N);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if(left == NULL) return right;
        if(right == NULL) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while(left && right){
            if(left -> val <= right -> val){
                mptr -> next = left;
                mptr = left;
                left = left -> next;
            }
            else{
                mptr -> next = right;
                mptr = right;
                right = right -> next;
            }
        }

        if(left){
            mptr -> next = left;
        }

        if(right){
            mptr -> next = right;
        }

        return ans -> next;    
    }

};


int main(){
    // Creation of Node
    // Static Creation
    // Node a;

    // Dynamic Creation
    // Node* zero = new Node(23);
    // Node* first = new Node(33);
    // Node* second = new Node(43);
    // Node* third = new Node(53);
    // // NOTE: Above nodes are not connected
     

    // zero->next = first; // temp -> first
    // first->next = second; // first -> second
    // second->next = third; // second -> third
    // // Now they are connected
    // print(zero);

    // int ans = lengthCount(zero);
    // cout << "Length is : "<<ans<<endl;

    // // insertAtHead(zero, third, 299);
    // insertAtTail(zero, third, 999);

    // print(zero);


    Node* head = NULL;
    Node* tail = NULL;


    insetAtPos(head, tail, 10, 1);
    insetAtPos(head, tail, 20, 2);
    insetAtPos(head, tail, 30, 3);
    insetAtPos(head, tail, 40, 4);
    insetAtPos(head, tail, 50, 5);

    cout<<"Value of head : "<<head->data<<endl;
    cout<<"Value of tail : "<<tail->data<<endl;
    print(head);

    

}