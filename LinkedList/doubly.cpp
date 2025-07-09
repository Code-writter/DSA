#include<iostream>
using namespace std;

class Node{
    public:

    Node* prev;
    int data;
    Node* next;


    Node(){
        this->prev = NULL;
        this->data = 0;
        this -> next = NULL;
    }

    Node(int data){
        this -> prev = NULL;
        this ->data = data;
        this -> next = NULL;
    }

    ~Node(){
        cout<<"Deleted Node : "<<this->data<<endl;
    }
};

void printLL(Node* head){
    // create temp
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp -> next;
    }
}

int getLength(Node* head){
    // create temp 
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp -> next;
        count++;
    }
    return count;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    // All cases
    if(head == NULL && tail == NULL){

        // create new node
        Node* newNode = new Node(data);

        head = newNode;
        tail = newNode;
        return;
    }
    else{
        // create new Node
        Node* newNode = new Node(data);

        newNode->next = head;
        head -> prev = newNode;

        head = newNode;
        return;
    }
}


void insertAtTail(Node* &head, Node* &tail, int data){
    // All cases
    if(head == NULL && tail == NULL){
        // create new node
        Node* newNode = new Node(data);

        head = newNode;
        tail = newNode;
        return;
    }
    else{
        // create new Node
        Node* newNode = new Node(data); 

        newNode -> prev = tail;
        tail -> next = newNode;

        tail = newNode;

        return ;
    }
}


void insertAtPos(Node* &head, Node* &tail, int data, int pos){
    // All cases
    if(head==NULL && tail == NULL){
        Node* newNode = new Node(data);

        head = newNode;
        tail = newNode;
    }

    int length = getLength(head);
    if(pos <= 1){

        insertAtHead(head, tail, data);
        return;
    }

    else if(pos >= length){
        insertAtTail(head, tail, data);
        return;
    }
    else{
        Node* prv = NULL;
        Node* curr = head;

        while(pos != 1){
            pos--;
            prv = curr;
            curr = curr -> next;
        }

        // Get new data node
        Node* newNode = new Node(data);

        prv -> next = newNode;
        newNode -> next = curr;
        curr -> prev = newNode;
        newNode -> prev = prv;

        return;
    }
    
    if(head == NULL && tail == NULL){
        // create new node
        Node* newNode = new Node(data);

        head = newNode;
        tail = newNode;
        return;
    }
    else{
        // create new Node
        Node* newNode = new Node(data);

        newNode -> prev = tail;
        tail -> next = newNode;

        tail = newNode;
        
        return ;
    }
}

void deleteAtHead(Node* &head, Node* &tail){
    if(head == NULL && tail == NULL){
        cout<<"Cannot be deleted"<<endl;
    }
    else{
        Node* temp = head;

        head = head -> next;

        head -> prev = NULL;
        temp -> next = NULL;

        delete(temp);
        return ;
    }
}

void deleteAtTail(Node* &head, Node* &tail){
    if(head == NULL && tail == NULL){
        cout<<"Cannot be deleted"<<endl;
    }
    else{
        Node* temp = tail;

        tail = tail -> prev;
        tail -> next = NULL;
        temp -> prev = NULL;

        delete(temp);
        return;
    }
}
void singleNode(Node* &head, Node* &tail){
    if(head == tail){
        
    }
}
void deleteAtPos(Node* &head, Node* &tail, int pos){
    int len = getLength(head);
    if(head == NULL && tail == NULL){
        cout<<"Cannot be deleted"<<endl;
    }else if(pos <=1){
        deleteAtHead(head, tail);
        return;
    }else if(pos >= len){
        deleteAtTail(head, tail);
        return;
    }
    else{
        Node* prevNode = NULL;
        Node* currNode = head;

        while(pos != 1){
            pos--;
            prevNode = currNode;
            currNode = currNode -> next;
        }

        prevNode -> next = currNode -> next;
        currNode->next->prev = currNode -> prev;

        currNode -> prev = NULL;
        currNode -> next = NULL;
        delete(currNode);
        return;
    }
}



int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtPos(head,tail, 12, 1);
    insertAtPos(head,tail, 13, 2);
    insertAtPos(head,tail, 14, 3);
    insertAtHead(head, tail, 5400);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 1200);
    insertAtTail(head, tail, 100);
    insertAtTail(head, tail, 400);
    insertAtTail(head, tail, 900);
    cout<<"Prining"<<endl;
    printLL(head);

    cout<<"\n Deletion"<<endl;

    // deleteAtHead(head, tail);
    // deleteAtTail(head, tail);
    deleteAtPos(head, tail, 9);
    printLL(head);

}