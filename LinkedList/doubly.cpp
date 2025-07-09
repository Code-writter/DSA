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

    }
};


int main(){
    
}