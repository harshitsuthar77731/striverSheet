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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int h = 0;
        ListNode* temp = head;
        while(temp){
            h++;
            temp = temp->next;
        }

        k = k%h;
        if(k==0)
            return head;
        ListNode* end = head;
        ListNode* start = head;
        int t = h-k-1;
        while(t--){
            end = end->next;
        }
        start = end->next;
        end->next = NULL;
        temp = start;
        while(temp!=NULL&&temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = head;
        return start;
        
        
    }
};
