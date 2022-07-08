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
    ListNode* addTwoNumbers(ListNode* li1, ListNode* li2) {
        // add no.
        ListNode* newnode = NULL;
        ListNode* temp = NULL;
        int carry = 0;

        while(li1!=NULL&&li2!=NULL){
            if(newnode == NULL){
                int t = li1->val+li2->val+carry;
                carry = t/10;
                newnode = new ListNode(t%10);
                temp = newnode;
                li1 = li1->next;
                li2 = li2->next;
            }
            else{
                int t = li1->val+li2->val+carry;
                carry = t/10;
                temp->next = new ListNode(t%10);
                temp = temp->next;
                li1 = li1->next;
                li2 = li2->next;
            }
        }
        while(li1!=NULL){
            int t = li1->val+carry;
            carry = t/10;
            temp->next = new ListNode(t%10);
            temp = temp->next;     
            li1 = li1->next;
            }
        while(li2!=NULL){
            int t = li2->val+carry;
            carry = t/10;
            temp->next = new ListNode(t%10);
            temp = temp->next;
            li2 = li2->next;
        }
        while(carry>0){
            int t = carry;
            carry = t/10;
            temp->next = new ListNode(t%10);
            temp = temp->next;
        }
        return newnode;
    }
};
