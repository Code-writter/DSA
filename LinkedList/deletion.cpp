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

    // Destructor
    ~Node(){
        cout<<"\n Destructor called for : "<<this -> data<<endl;
    }

};

void print(Node* zero){
    // Note:Always make a temperory pointer to traverse the LL
    Node* temp = zero;

    while(temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    return;   
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

    if(head == NULL && tail == NULL){
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

}

void insetAtPos(Node* &head, Node* &tail, int data, int pos){
    if(pos < 1){
        cout<<"Cannot Insert"<<endl;
    }
    int length = lengthCount(head);

    if(pos = 1){
        insertAtHead(head, tail, data);
    }

    if(pos > length){
        insertAtTail(head, tail, data);
    }
    // Between
    if(pos > 1 && pos < length){
        // Create a node
        Node* temp = head;
        
        Node* prev = NULL;
        Node* curr = head;

        while(pos != 1){
            prev = curr;
            curr = curr -> next;
            pos--;
        }
        prev -> next =  temp;

        temp -> next = curr;

    }
}

void deleteNodebyPos(Node* &head, Node*&tail, int pos){
    
    int length = lengthCount(head);
    if(head == NULL){
        cout<<"Cannot delete, LL is empty"<<endl;
        return;
    }

    if(head == tail){
        Node* temp = head;

        delete(temp);

        head = NULL;
        tail = NULL;
        return;
    }
    else if(pos == 1){
        // delete from head

        // create temp
        Node* temp = head;

        // change head
        head = head -> next;

        // Point to null
        temp -> next = NULL;

        // Free space
        delete(temp);
        return;

    }else if(pos == length){
        // delete last node

        // Temp Node
        Node* temp = head;
        while(temp -> next != tail){
            temp = temp -> next;
        }

        // Isolate tail
        temp -> next = NULL;

        // Delete tail
        delete(tail);
        
        // Update tail
        tail = temp;
        return;
    }else{
        // delete from pos

        // Create Nodes
        Node* prev = NULL;
        Node*curr = head;

        while(pos != 1){
            pos--;
            prev = curr;
            curr = curr -> next;
        }

        // Jump over node
        prev -> next = curr -> next;

        // Isolate it :  Make it null
        curr -> next = NULL;

        // Delete
        delete(curr);

    }
    return;
}


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

    // insertAtHead(head, tail, 10);
    // insertAtHead(head, tail, 30);
    // insertAtHead(head, tail, 50);
    // print(head);
    // cout<<"Insert AT tail"<<endl;
    // insertAtTail(head, tail, 100);
    // insertAtTail(head, tail, 200);
    // insertAtTail(head, tail, 300);
    print(head);
    int len = lengthCount(head);
    cout<<"Length is : "<<len<<endl;
    deleteNodebyPos(head, tail, 1);
    print(head);
    cout<<"After deletion"<<endl;
    int len2 = lengthCount(head);
    cout<<"Length is : "<<len2<<endl;
    // deleteNodebyPos(head, tail, 6);
    // print(head);

    // deleteNodebyPos(head, tail, 1);
    // print(head);

}