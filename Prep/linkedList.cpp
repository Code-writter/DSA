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


Node* deleteFormHead(Node* head){
    cout<<"called delte form head"<<endl;
    Node* temp = head;

    if(head == NULL){
        return NULL;
    }
    cout<<"Before deletion head "<<head -> data<<endl;
    head = head -> next;
    cout<<"After deletion head "<<head -> data<<endl;

    delete(temp);
    return head;
}

Node* deleteFromPos(Node* head, int pos){
    if(head == NULL){
        return NULL;
    }

    if(pos <= 1){
        Node* newHead = deleteFormHead(head);
        return newHead;
    }else{
        Node* curr = head;
        Node* prev = NULL;

        while(pos != 1){
            prev = curr;
            curr = curr -> next;
            pos--;
        }
        prev -> next = curr -> next;
    }
    return head;
}


Node* reverseTheLL(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head -> next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* temp = head;

    while(curr != NULL){
        temp = temp -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}


Node* reverseKNodes(Node* head, int k){
    if(head == NULL || k <= 1){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* temp = NULL;
    int count = 0;

    // Reverse first k nodes
    while(curr != NULL && count < k){
        temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
        count++;
    }

    // head is now the last node in the reversed group
    // if(temp != NULL){
    //     head -> next = reverseKNodes(temp, k);
    // }
    head -> next = temp;
    // prev is the new head of the reversed group
    return prev;
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insetAtPos(head, tail, 3, 1);
    insetAtPos(head, tail, 2, 2);
    insetAtPos(head, tail, 5, 3);
    insetAtPos(head, tail, 6, 4);
    insetAtPos(head, tail, 8, 5);
    insetAtPos(head, tail, 9, 6);
    insetAtPos(head, tail, 11, 7);

    // cout<<"Before deleting"<<endl;
    print(head);
    // cout<<"After deleting"<<endl;
    // Node* newHead = deleteFromPos(head, 1);
    // print(newHead);
    cout<<"reversed List"<<endl;
    Node* newHead = reverseKNodes(head, 3);
    print(newHead);

}