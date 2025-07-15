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
    if(head == NULL) return NULL;
    Node* temp = head;

    // I have skipped M nodes
    for(int i = 0; i<M; i++){
        temp = temp -> next;
    }
    // save this mth  node
    Node* mthNode = temp;
    temp = temp -> next;

    for(int i = 0; i<N; i++){
        Node* dele = temp;
        temp = temp -> next;
        delete(dele);
    }
    mthNode -> next = temp;
    
    skipMDeleteN(temp, M, N);
    return head;
}

// This is fixed version

Node* skipMDeleteN(Node* head, int M, int N){
    // MISTAKE 1: Incorrect handling of edge case M=0 or N=0.
    // If M=0, it means delete from the head. The current logic will try to skip 0 and then delete.
    // If N=0, it means skip M and delete 0. The current logic will iterate 0 times for deletion, which is fine,
    // but the overall structure should handle these more gracefully.

    if(head == NULL) return NULL; // Correct: Base case for an empty list.

    Node* temp = head; // Correct: Initialize a temporary pointer to traverse the list.

    // --- MISTAKE 2: Loop for skipping M nodes is flawed. ---
    // This loop intends to skip M nodes.
    // If M=0, this loop won't run, 'temp' remains 'head'. This is problematic if M=0 means delete from head.
    // If M=1, 'temp' becomes 'head->next'. This means 'temp' points to the 2nd node (1-indexed).
    // The goal is usually to find the node *before* the Mth node, or the Mth node itself.
    // Also, it lacks a check for 'temp == NULL' inside the loop, which can lead to a nullptr dereference
    // if M is greater than or equal to the remaining list length.
    for(int i = 0; i<M; i++){
        // MISTAKE 3: No check for temp being NULL.
        // If the list has fewer than M nodes remaining, 'temp->next' will eventually be called on a NULL pointer, causing a crash.
        if (temp == NULL) return head; // Or handle appropriately, e.g., break and return.
        temp = temp -> next;
    }

    // MISTAKE 4: 'mthNode' is incorrectly defined/used for linking.
    // 'mthNode' is assigned 'temp' after skipping M nodes. So, it points to the (M+1)th node (1-indexed).
    // This 'mthNode' should be the node *before* the segment to be deleted, so its 'next' pointer can be updated.
    // If M=0, 'mthNode' is 'head', which is not the node *before* the deletion.
    Node* mthNode = temp;

    // MISTAKE 5: 'temp' is advanced one more time unnecessarily.
    // This line advances 'temp' to the (M+2)th node (1-indexed).
    // This creates confusion because 'temp' was just used to identify 'mthNode'.
    // In a typical skip-delete, 'temp' would either stay at 'mthNode' or be reset to the node *to be deleted*.
    temp = temp -> next;

    // --- MISTAKE 6: Loop for deleting N nodes is flawed. ---
    // This loop intends to delete N nodes.
    // It correctly advances 'temp' and deletes 'dele'.
    for(int i = 0; i<N; i++){
        // MISTAKE 7: No check for 'temp' being NULL before dereferencing.
        // If the list has fewer than N nodes remaining after skipping M, 'temp' could become NULL,
        // leading to a nullptr dereference on 'temp -> next' in the next iteration or on 'delete(dele)'.
        if (temp == NULL) break; // Or handle appropriately.
        Node* dele = temp; // Correct: Save the node to be deleted.
        temp = temp -> next; // Correct: Advance 'temp' to the next node *before* deleting 'dele'.
        delete(dele); // Correct: Delete the node to free memory.
    }

    // --- MISTAKE 8: Re-linking logic is incorrect due to previous pointer misplacements. ---
    // This line attempts to link the 'mthNode' (the node after skipping M) to the node *after* deletion.
    // However, if M=0, 'mthNode' is 'head', and you're trying to link 'head->next = temp', which is wrong.
    // If M > 0, 'mthNode' is the (M+1)th node. Its 'next' should point to 'temp' (the node after N deletions).
    // This would be correct IF 'mthNode' was the node *before* the deletion started.
    // The pointer that needs its 'next' updated is the node *at* the Mth position (or the dummy node if M=0).
    mthNode -> next = temp;

    // --- MISTAKE 9: Incorrect recursive call. ---
    // This line makes a recursive call.
    // 'temp' is the head of the *remaining* list after the current skip-delete operation.
    // However, the recursive call's return value is *discarded*. It does not update the list structure.
    // For a recursive solution, the function should return the head of the processed sublist,
    // and the caller (mthNode->next) should be assigned this result.
    // Also, the base case for recursion (when 'temp' becomes NULL) is not explicitly handled for this call.
    // This problem is typically solved iteratively for simplicity and avoiding stack overflow with long lists.
    skipMDeleteN(temp, M, N);

    // --- MISTAKE 10: Incorrect return value for M=0 case. ---
    // If M=0, nodes from the beginning of the list are deleted.
    // In this scenario, the 'head' of the list would change.
    // The function always returns the original 'head', which would be a deleted node or incorrect if the head changed.
    // A dummy node at the beginning of the list is often used to simplify head changes.
    return head;
}


Node* skipMDeleteN(Node* head, int M, int N) {
    // Handle edge cases for M and N values.
    // M: number of nodes to skip.
    // N: number of nodes to delete.

    // If the list is empty, there's nothing to do.
    if (head == nullptr) {
        return nullptr;
    }

    // If M is 0, it means delete N nodes from the head repeatedly.
    // This is a special case: delete N, then skip 0, delete N, etc.
    // If N is 0, it means skip M nodes and delete 0. The list remains unchanged.
    // We handle N=0 by simply not entering the deletion loop.
    if (M == 0) {
        // If M is 0, we just delete N nodes from the current position.
        // This loop will effectively delete the first N nodes.
        Node* current = head;
        for (int i = 0; i < N && current != nullptr; ++i) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        // After deleting N nodes, the new head is 'current'.
        // Recursively call for the rest of the list.
        // This part needs careful thought for repeated deletion if M=0.
        // For a single pass of "skip M, delete N", if M=0, it means delete first N.
        // If the problem implies repeated operation, a full iterative loop is better.
        // Assuming "skip M, delete N" is a single operation starting from head for now.
        // If M=0, the problem usually means delete the first N nodes.
        // For the general problem, M=0 implies continuous deletion.
        // Let's assume M >= 1 for the main loop, and handle M=0 as a specific case
        // or clarify problem statement.
        // Given the common interpretation of skipMDeleteN, M is usually >= 1.
        // If M=0, it means delete N nodes, then the next N nodes, etc.
        // The current iterative loop below handles M=0 gracefully by not moving 'current' initially.
        // Let's proceed with the dummy node approach which handles M=0 naturally.
    }


    // Use a dummy node to simplify handling the head of the list,
    // especially if the head itself needs to be deleted (when M=0).
    Node* dummy = new Node(0); // Create a dummy node with value 0.
    dummy->next = head; // Link dummy to the actual head of the list.

    Node* current = dummy; // Pointer to traverse the list.
                                // Starts at dummy, so 'current->next' is the actual head.

    // Loop to repeatedly skip M nodes and delete N nodes.
    // This loop continues as long as there are nodes to process.
    while (current != nullptr) {
        // 1. Skip M nodes: Move 'current' M times.
        // 'current' will end up pointing to the node *before* the segment to be deleted.
        for (int i = 0; i < M; ++i) {
            // If we reach the end of the list while skipping, stop.
            if (current == nullptr) {
                break;
            }
            current = current->next;
        }

        // If 'current' became nullptr during skipping, it means we reached the end.
        // No more nodes to delete, so break the main loop.
        if (current == nullptr) {
            break;
        }

        // 'nodeBeforeDeletion' points to the Mth node (or dummy if M=0).
        // This node's 'next' pointer will need to be updated after deletion.
        Node* nodeBeforeDeletion = current;

        // 'deletionStart' points to the first node to be deleted (the (M+1)th node).
        Node* deletionStart = current->next;

        // 2. Delete N nodes: Move 'deletionStart' N times, deleting nodes along the way.
        Node* nodeAfterDeletion = nullptr; // Pointer to the node after the deleted segment.
        for (int i = 0; i < N && deletionStart != nullptr; ++i) {
            nodeAfterDeletion = deletionStart->next; // Save the next node before deleting current one.
            delete deletionStart; // Free memory for the node.
            deletionStart = nodeAfterDeletion; // Move to the next node to potentially delete.
        }

        // 3. Re-link the list:
        // The 'next' of the node *before* deletion should now point to the node *after* deletion.
        nodeBeforeDeletion->next = deletionStart;

        // Move 'current' to the node that was just linked (the node after the deleted segment).
        // This prepares 'current' for the next iteration of skipping M nodes.
        current = deletionStart;
    }

    // The actual head of the modified list is dummy->next.
    Node* newHead = dummy->next;
    delete dummy; // Free the dummy node.
    return newHead; // Return the new head of the list.
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


    insetAtPos(head, tail, 10, 1);
    insetAtPos(head, tail, 20, 2);
    insetAtPos(head, tail, 30, 3);
    insetAtPos(head, tail, 40, 4);
    insetAtPos(head, tail, 50, 5);

    cout<<"Value of head : "<<head->data<<endl;
    cout<<"Value of tail : "<<tail->data<<endl;
    print(head);

    

}