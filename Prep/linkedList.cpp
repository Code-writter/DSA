#include<iostream>
#include<unordered_map>
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

Node* middleOfLL(Node* head){
    int len = lengthCount(head);

    int mid = len/2;
    Node* temp = head;
    while(mid != 0){
        mid--;
        temp = temp -> next;
    }

    return temp;
}

Node* middleOfLLMethodTwo(Node* head){
    Node* turtle = head;
    Node* hare = head;
    if(head == NULL){
        return NULL;
    }

    while(hare != NULL){
        // move hare one step
        hare = hare -> next;
        if(hare != NULL){
            // more hare one more step
            hare = hare -> next;
            turtle = turtle -> next;
        }
    }

    return turtle;
}

Node* createNewLLUsingRec(int data ) {
    if (data == NULL) {
        return NULL;
    }
    Node* head = new Node(data);
    head->next = createNewLLUsingRec(data);
    return head;
}

bool palindromeMethod1(Node* head){
    Node* head1 = head;
    Node* head2 = NULL;

    // Make new linked list
    Node* temp = head1;
    Node* head2KaNext = head2;
    // Create a reversed copy of the linked list
    while(temp != NULL){
        Node* newNode = new Node(temp->data);
        newNode->next = head2;
        head2 = newNode;
        temp = temp->next;
    }

    // Compare both linked lists
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data != temp2->data){
            cout<<"Not a palindrome"<<endl;
            return false;
        }else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}

Node* getMid(Node* head){
    Node* turtle = head;
    Node* hare = head;

    while(hare != NULL){
        hare = hare -> next;
        if(hare != NULL){
            hare = hare -> next;
            turtle = turtle -> next;
        }
    }
    return turtle;
}
Node* reverseHalf(Node* mid){
    Node* curr = mid;
    Node* temp = curr;
    Node* prev = NULL;

    while(curr != NULL){
        temp = temp -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    // prev is the new head
    return prev;
}

bool compreLL(Node* head1,Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1 -> data != temp2 -> data){
            return false;
        }else{
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    }
    return true;
}

bool palindromeMethod2(Node* head){
    // get middle
    Node* mid = getMid(head);

    Node* nextToMid = mid -> next;
    mid -> next = NULL;

    // reverse the half part
    Node* head2 = reverseHalf(nextToMid);
    // compare till one exhausts
    return compreLL(head, head2);
}


bool detectCycleMethodOne(Node* head){
    unordered_map<Node*, bool>mp;
    Node* temp = head;

    while(temp != NULL){
        if(mp.count(temp)){
            return true;
        }
        else{
            mp[temp] = true;
        }
        temp = temp -> next;
    }

    return false;
}

bool detectCycleMethodTwo(Node* head){
    Node* turtle = head;
    Node* hare = head;

    while(hare != NULL){
        hare = hare -> next;
        if(hare != NULL){
            hare = hare -> next;
            turtle = turtle -> next;
        }

        if(hare == turtle){
            return true;
        }
    }
    return false;
}

Node* detectAndRemoveCycle(Node* head){
    Node* turtle = head;
    Node* hare = head;
    bool cycleFound = false;

    // Detect cycle
    while(hare != NULL && hare->next != NULL){
        hare = hare->next->next;
        turtle = turtle->next;
        if(hare == turtle){
            cycleFound = true;
            break;
        }
    }

    if(!cycleFound) {
        return head; // No cycle
    }

    // Find start of cycle
    turtle = head;
    while(turtle != hare){
        turtle = turtle->next;
        hare = hare->next;
    }

    // Find the node before the start of cycle
    Node* prev = hare;
    while(prev->next != hare){
        prev = prev->next;
    }
    prev->next = NULL;

    return head;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insetAtPos(head, tail, 2, 1);
    insetAtPos(head, tail, 1, 2);
    insetAtPos(head, tail, 2, 3);
    insetAtPos(head, tail, 6, 4);
    insetAtPos(head, tail, 2, 5);
    insetAtPos(head, tail, 1, 6);
    insetAtPos(head, tail, 1, 7);

    // Make a cycle: tail->next points to the 3rd node
    Node* third = head;
    int pos = 3;
    while(pos > 1 && third != NULL) {
        third = third->next;
        pos--;
    }
    if (tail != NULL && third != NULL) {
        tail->next = third;
    }

    // cout<<"Before deleting"<<endl;
    // print(head);
    // cout<<"After deleting"<<endl;
    // Node* newHead = deleteFromPos(head, 1);
    // print(newHead);
    // cout<<"reversed List"<<endl;
    // Node* newHead = middleOfLLMethodTwo(head);
    // cout<<newHead -> data <<endl;
    // if(palindromeMethod1(head)){
    //     cout<<"It is a palindrome"<<endl;
    // }else{
    //     cout<<"It is not a palindrome"<<endl;
    // }
    // // Node* createNewLL = createNewLLUsingRec();
    // // print (createNewLL);
    // cout<<endl;
    // getMid(head);    
    
    // if(detectCycleMethodTwo(head)){
    //     cout<<" Cycle Present "<<endl;
    // }else{
    //     cout<<"Not Cycle "<<endl;
    // }
    // cout<<endl;

    Node* newHead = detectAndRemoveCycle(head);
    cout<<"After removed Cycle"<<endl;
    print(head);
}