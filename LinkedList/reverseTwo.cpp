#include <iostream>
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
    ListNode* middleNode(ListNode* head) {
        // int length = 0;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     temp = temp -> next;
        //     length++;
        // }

        // int half = length/2;
        // int mid = half + 1;
        // ListNode* middle = head;
        // while(mid != 1){
        //     mid--;
        //     middle = middle -> next;
        // }

        // return middle;


        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast -> next;

            if(fast != NULL){
                fast = fast -> next;

                // now we move slow
                slow = slow -> next;
            }
        }

        return slow;
    }
};