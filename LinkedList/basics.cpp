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
        cout<<temp -> data<<endl;
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

int main(){
    // Creation of Node
    // Static Creation
    // Node a;

    // Dynamic Creation
    Node* zero = new Node(23);
    Node* first = new Node(33);
    Node* second = new Node(43);
    Node* third = new Node(53);
    // NOTE: Above nodes are not connected
     

    zero->next = first; // temp -> first
    first->next = second; // first -> second
    second->next = third; // second -> third
    // Now they are connected
    print(zero);

    int ans = lengthCount(zero);
    cout << "Length is : "<<ans<<endl;
}