#include<iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* midNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL){
            fast = fast -> next;

            if(fast -> next != NULL){
                fast = fast -> next;

                // now we move slow
                slow = slow -> next;
            }
        }

        return slow;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* prv = NULL;
        ListNode* curr = head;
        ListNode* temp = head;

        while(curr != NULL){
            temp = temp -> next;
            curr -> next = prv;
            prv = curr;
            curr = temp;
        }
        return prv;
    }
    bool compareLL(ListNode* head1, ListNode* head2){
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        while(temp1 != NULL && temp2 != NULL){
            if(temp1 -> val != temp2 -> val){
                return false;
            }
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        // Find mid
        ListNode* mid = midNode(head);

        // Break the LL

        ListNode* secNode = mid -> next;
        mid -> next = NULL;

        // Reverse the LL

        ListNode* head2 = reverseLL(secNode);

        // compare both 

        bool ans = compareLL(head, head2);

        return ans;
    }
};