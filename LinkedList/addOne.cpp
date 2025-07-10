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

Node* reverseLL(Node* &head){
    Node* prevNode = NULL;
    Node* currNode = head;
    Node* temp = currNode;
    while(currNode != NULL){
        temp = temp -> next;
        currNode -> next = prevNode;
        prevNode = currNode;
        currNode = temp;
    }

    return prevNode;
}

Node* add(Node* head){
    int carry = 1;

    Node* temp = head;
    // we will stop before the last NULL (ie we will stop at tail)
    while(temp -> next != NULL){
        int totalSum = temp -> data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        // add the last digit to the temp
        temp -> data = digit;
        // Move the temp
        temp = temp -> next;

        if(carry == 0){
            break;
        }
    }

    if(carry != 0){
        int totalSum = temp -> data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp -> data = digit;

        if(carry != 0){
            // create new node for the tail
            Node* newNode = new Node(carry);
            temp -> next = newNode;
            cout<<"\n  printing inside the if"<<endl;
            print(head);
        }

    }
    return head;
}

Node* addOne(Node* &head){
    // Reverse a LL
    Node* head1 = reverseLL(head);
    // Add One in the nodes
    Node* head2 = add(head1);
    Node* head3 = reverseLL(head2);
}


int main(){


    Node* head = NULL;
    Node* tail = NULL;


    insetAtPos(head, tail, 9, 1);
    insetAtPos(head, tail, 9, 2);
    insetAtPos(head, tail, 9, 3);

    print(head);
    cout<< "\n Before Addition "<<endl;
    Node* afterAdd = addOne(head);
    cout<<"\n After Addition"<<endl;
    print(afterAdd);

}