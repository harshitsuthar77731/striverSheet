/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newnode = NULL;
        ListNode* temp  = NULL;
        while(head!=NULL){
            temp = head->next;
            head->next = newnode;
            newnode = head;
            head = temp;
        }
        return newnode;
    }
};
