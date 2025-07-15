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

int mthNodeFromEnd(Node* head, int m){

    if(head == NULL){
        return 0;
    }
    Node* temp = head;
    int length = lengthCount(temp);
    int node = length - m + 1;

    while(node != 0){
        temp = temp -> next;
    }
    return temp -> data;
}

// Assuming Node structure is defined as:
// struct Node {
//     int data; // Or 'val' as per previous examples, assuming 'data' for this code.
//     Node *next;
//     Node(int x) : data(x), next(nullptr) {}
// };

// Function to count the number of nodes in a linked list.
int lengthCount(Node* head){
    Node* temp = head; // Correct: Initialize a temporary pointer to traverse the list.
    int count = 0;     // Correct: Initialize count to 0.

    // Correct: Loop continues as long as 'temp' is not NULL, iterating through each node.
    while(temp != NULL){
        count++;           // Correct: Increment count for each node.
        temp = temp -> next; // Correct: Move to the next node.
    }

    return count; // Correct: Returns the total count of nodes.
}

// Function to find the Mth node from the end of a linked list.
int mthNodeFromEnd(Node* head, int m){

    // Correct: Handles the edge case where the list is empty.
    // However, returning 0 might be ambiguous if 0 is a valid data value.
    // It's often better to throw an exception or return a special value like -1 or use a boolean return.
    if(head == NULL){
        return -1;
    }

    Node* temp = head; // Correct: Initialize a temporary pointer to traverse the list.
    int length = lengthCount(temp); // Correct: Get the total length of the list.

    // MISTAKE 1: Calculation of 'node' is correct for finding the (length - m + 1)th node from the beginning.
    // However, if 'm' is greater than 'length', 'node' will be 0 or negative.
    // This needs to be handled to prevent accessing out of bounds or infinite loops.
    // Example: List length 5, m = 6. node = 5 - 6 + 1 = 0.
    // Example: List length 5, m = 5. node = 5 - 5 + 1 = 1. (1st node from beginning)
    // Example: List length 5, m = 1. node = 5 - 1 + 1 = 5. (5th node from beginning)
    int node = length - m + 1;

    // MISTAKE 2: Missing check for invalid 'm'.
    // If 'm' is less than or equal to 0, or greater than 'length', 'node' will be out of bounds.
    // For example, if m > length, 'node' will be <= 0.
    // If 'node' is 0, the loop 'while(node != 0)' won't run, and 'temp' remains 'head'.
    // Then 'temp -> data' (head->data) is returned, which is incorrect for m > length.
    // If 'node' is negative, the loop also won't run.
    if (m <= 0 || m > length) {
        // Handle invalid 'm' (e.g., throw an exception, return a sentinel value, or print an error).
        // For now, let's return a special value to indicate error.
        // return -1; // Or throw std::out_of_range("m is out of bounds");
        // For the purpose of just checking the loop, let's assume valid m for now.
    }


    // MISTAKE 3: The loop condition 'while(node != 0)' is problematic.
    // If 'node' is calculated to be 1 (meaning the 1st node from the beginning),
    // the loop will not execute even once. 'temp' will remain 'head'.
    // The loop should iterate 'node - 1' times to reach the 'node'th position.
    // Or, it should iterate 'node' times, starting 'temp' from a dummy node or similar.
    while(node != 0){ // If node = 1, this loop is skipped. temp remains head.
                      // If node = 0, this loop is skipped. temp remains head. (MISTAKE 2 consequence)
        temp = temp -> next; // Correct: Advances temp.
        node--;              // Correct: Decrements counter.
    }
    // After this loop, 'temp' will point to the node *after* the target node if 'node' was initially > 0.
    // Example: if node = 5 (meaning 5th node from beginning), loop runs 5 times.
    // temp starts at head. After 1 iteration, temp is 2nd node. After 5 iterations, temp is 6th node (NULL if list is 5 long).
    // It should iterate 'node - 1' times to land 'temp' *on* the target node.

    // MISTAKE 4: Dereferencing 'temp' without checking for NULL.
    // If 'm' is too large (m > length), 'temp' might become NULL after the loop,
    // leading to a crash when 'temp -> data' is accessed.
    return temp -> data; // CRASH if temp is NULL.
}

// ---------------------- Correct Code ------------------------------
struct ListNode {
    int val; // Assuming 'val' as per previous examples, not 'data'.
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    // Helper function to count the number of nodes in a linked list.
    int lengthCount(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

public:
    // Function to find the Mth node from the end of a linked list using length count.
    // 'm' is 1-indexed (e.g., m=1 means the last node, m=2 means the second to last).
    ListNode* mthNodeFromEndLengthCount(ListNode* head, int m) {
        // Handle edge case: if the list is empty.
        if (head == nullptr) {
            // If the list is empty, an Mth node from the end cannot exist.
            return nullptr;
        }

        // Handle edge case: 'm' must be a positive integer.
        if (m <= 0) {
            throw std::out_of_range("m must be a positive integer.");
        }

        // Step 1: Get the total length of the linked list.
        int length = lengthCount(head);

        // Calculate the position from the beginning (1-indexed).
        // For example, if length=5 and m=2 (2nd from end),
        // nodeFromBeginning = 5 - 2 + 1 = 4 (4th node from beginning).
        int nodeFromBeginning = length - m + 1;

        // Handle edge case: If 'm' is greater than the total length of the list,
        // the Mth node from the end does not exist.
        if (nodeFromBeginning <= 0) { // This also covers m > length
            throw std::out_of_range("m is greater than the length of the list.");
        }

        // Step 2: Traverse the list to find the 'nodeFromBeginning'th node.
        ListNode* temp = head;
        // We need to move 'temp' (nodeFromBeginning - 1) times to reach the target node.
        for (int i = 0; i < nodeFromBeginning - 1; ++i) {
            // This check is a safeguard, though 'nodeFromBeginning' calculation
            // should prevent 'temp' from becoming nullptr here if 'm' is valid.
            if (temp == nullptr) {
                // This case should ideally not be reached if 'm' is within bounds.
                throw std::runtime_error("Unexpected null pointer during traversal.");
            }
            temp = temp->next;
        }

        // 'temp' now points to the Mth node from the end.
        return temp;
    }
};

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




int main(){

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