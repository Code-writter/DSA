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

Node* mergeTwoLists(Node* left, Node* right){
    Node* ptr = left;
    Node* head = left;

    if(left == NULL && right == NULL){
        return NULL;
    }

    if(left != NULL && right == NULL){
        return left;
    }
    if(left == NULL && right != NULL){
        return right;
    }

    while(left != NULL || right != NULL){
        if(ptr -> data < right -> data){
            ptr -> next = right;
            ptr = ptr -> next;
            right = right -> next;
        }else if(ptr -> data < left -> data){
            ptr -> next = left;
            ptr = ptr -> next;
            left = left -> next;
        }
    }

    if(left != NULL){
        ptr -> next = left;
    }
    if(right != NULL){
        ptr -> next = right;
    }

    return head;
}

Node* mergeTwoLists(Node* left, Node* right){
    // MISTAKE 1: Incorrect initialization of 'ptr' and 'head'.
    // 'ptr' and 'head' are both initialized to 'left'.
    // This is problematic if 'left' is NULL, or if 'right' contains the smallest element.
    // A common and robust approach is to use a dummy node to simplify head management.
    Node* ptr = left;
    Node* head = left;

    // MISTAKE 2: Redundant and potentially incorrect base cases.
    // The main loop and subsequent checks should handle these cases naturally.
    // If left and right are both NULL, the first 'if' correctly returns NULL.
    if(left == NULL && right == NULL){
        return NULL;
    }

    // If left is not NULL and right is NULL, it correctly returns left.
    if(left != NULL && right == NULL){
        return left;
    }
    // If left is NULL and right is not NULL, it correctly returns right.
    if(left == NULL && right != NULL){
        return right;
    }

    // MISTAKE 3: The initial 'ptr' and 'head' assignment is problematic if 'right->data' is smaller.
    // If right->data is smaller than left->data, 'head' should point to 'right', not 'left'.
    // The current setup assumes 'left' will always be the start, which is false for sorted merge.
    // A dummy node helps resolve this by always starting with a known node.

    // MISTAKE 4: Incorrect loop condition and logic for merging.
    // The loop condition 'while(left != NULL || right != NULL)' is correct for iterating as long as there are elements.
    while(left != NULL || right != NULL){
        // MISTAKE 5: 'ptr->data' is being compared, but 'ptr' should be used to BUILD the new list, not compare its own data.
        // The comparison should be between 'left->data' and 'right->data'.
        // Also, 'ptr' might be NULL if both 'left' and 'right' become NULL, leading to a crash.
        // This entire 'if-else if' block is logically flawed for merging.

        // MISTAKE 6: Dereferencing 'right' without checking for NULL.
        // If 'right' becomes NULL but 'left' is still not NULL, 'right->data' will cause a crash.
        if(ptr -> data < right -> data){ // CRASH if right is NULL here
            // MISTAKE 7: Incorrect linking.
            // 'ptr->next = right' links the current node of the new list to the head of the *remaining* right list.
            // It should link to the *current smallest node* (either from left or right), then advance that list's pointer.
            ptr -> next = right;
            ptr = ptr -> next; // Moves ptr to the node that was just linked (which is 'right')
            right = right -> next; // Advances 'right'
        }
        // MISTAKE 8: Incorrect comparison.
        // This condition 'ptr -> data < left -> data' is also flawed.
        // It should compare 'left->data' and 'right->data' to decide which to add next.
        // It also causes a crash if 'left' is NULL.
        else if(ptr -> data < left -> data){ // CRASH if left is NULL here
            // MISTAKE 9: Incorrect linking. Similar to MISTAKE 7.
            ptr -> next = left;
            ptr = ptr -> next;
            left = left -> next;
        }
        // MISTAKE 10: Missing 'else' for cases where left->data <= right->data
        // The logic doesn't cover all scenarios (e.g., if left->data is smaller or equal to right->data).
        // It's trying to compare 'ptr->data' which is wrong.
    }

    // MISTAKE 11: Incorrect handling of remaining nodes.
    // After the loop, if one list is exhausted, the remaining nodes of the other list should be appended.
    // The current logic correctly checks if 'left' or 'right' is not NULL.
    // However, 'ptr' might be NULL here if the list was empty or due to previous errors.
    // Also, if both 'left' and 'right' are not NULL when the loop ends (which shouldn't happen with correct loop logic),
    // it would try to link both, which is incorrect.
    if(left != NULL){
        ptr -> next = left; // Correctly appends remaining 'left' list.
    }
    if(right != NULL){
        ptr -> next = right; // Correctly appends remaining 'right' list.
    }
    // MISTAKE 12: If both are not NULL, this would overwrite the previous link.
    // Only one of these 'if' blocks should execute.

    // MISTAKE 13: The returned 'head' might be incorrect.
    // If 'right' had the smallest element, 'head' would still point to the original 'left' node, which is wrong.
    // A dummy node approach correctly tracks the head of the new merged list.
    return head;
}

// ------- Correct Code -----------

#include <cstddef> // Required for NULL or nullptr

// Definition for singly-linked list.
struct ListNode { // Assuming Node is equivalent to ListNode as per common DSA problems
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node. This simplifies handling the head of the new merged list.
        // We'll attach the merged list to dummy.next.
        ListNode* dummy = new ListNode(0);
        // 'current' pointer will be used to build the new merged list.
        // It always points to the last node added to the merged list.
        ListNode* current = dummy;

        // Loop as long as both lists have nodes remaining.
        while (list1 != nullptr && list2 != nullptr) {
            // Compare the values of the current nodes in both lists.
            if (list1->val <= list2->val) {
                // If list1's current node is smaller or equal, append it to the merged list.
                current->next = list1;
                // Move list1's pointer to its next node.
                list1 = list1->next;
            } else {
                // If list2's current node is smaller, append it to the merged list.
                current->next = list2;
                // Move list2's pointer to its next node.
                list2 = list2->next;
            }
            // Move the 'current' pointer to the node that was just added to the merged list.
            current = current->next;
        }

        // After the loop, one of the lists might still have remaining elements.
        // Append the rest of the non-null list to the merged list.
        // Since both lists are sorted, we can just append the remaining part directly.
        if (list1 != nullptr) {
            current->next = list1;
        } else { // This else handles list2 != nullptr or both are nullptr
            current->next = list2;
        }

        // The actual head of the merged list is the node after the dummy.
        ListNode* mergedHead = dummy->next;
        // Free the dummy node to prevent memory leaks.
        delete dummy;
        // Return the head of the newly merged sorted list.
        return mergedHead;
    }
};


int main(){


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
    // print(head);

    insetAtPos(head, tail, 10, 1);
    insetAtPos(head, tail, 20, 2);
    insetAtPos(head, tail, 30, 3);
    insetAtPos(head, tail, 40, 4);
    insetAtPos(head, tail, 50, 5);

    cout<<"Value of head : "<<head->data<<endl;
    cout<<"Value of tail : "<<tail->data<<endl;
    print(head);

    

}