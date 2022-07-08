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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = NULL,*temp = head,*ans =head;
        int h = 0;
        
        while(temp!=NULL){
            h++;
            temp = temp->next;
        }
        h = h-n;
        if(h==0)
            return ans->next;
        while(head!=NULL&&h>0){
                h--;
               pre = head;
               head = head->next;
        }
        pre->next = head->next;
        return ans;
    }
};
