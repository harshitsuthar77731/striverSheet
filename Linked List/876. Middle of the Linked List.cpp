
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int  h = 0;
        ListNode* temp = head;
        while(temp){
            h++;
            temp = temp->next;
        }
        h = h/2;
        while(h>0){
            h--;
            head = head->next;
        }
        return head;
    }
};
