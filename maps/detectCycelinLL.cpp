#include<iostream>
#include<map>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // map<ListNode*, bool> table;

        // ListNode* temp = head;

        // while(temp != NULL){
        //     if(table[temp] == false){
        //         table[temp] = true;
        //     }else{
        //         // Loop present
        //         return true;
        //     }
        //     temp = temp -> next;
        // }
        // // Loop not present
        // return false;


        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            // Move fast one move
            fast = fast -> next;
            if(fast != NULL){
                // Now fast have moved 2 steps then move slow one step
                fast = fast -> next;

                // move slow one step

                slow = slow -> next;

                if(fast == slow){
                    return true;
                }
            }
        }
        return false;
    }
};