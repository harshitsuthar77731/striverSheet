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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newnode = NULL;
        ListNode* temp;
        while(list1!=NULL&&list2!=NULL){
            if(list1->val<=list2->val){
                if(newnode==NULL){
                    newnode = new ListNode(list1->val);
                    temp = newnode;
                    list1 = list1->next;
                }
                else{
                    temp->next = new ListNode(list1->val);
                    temp =temp->next;
                    list1 = list1->next;
                }
                
            }else{
                if(newnode==NULL){
                     newnode = new ListNode(list2->val);
                    temp = newnode;
                    list2 = list2->next;
                }
                else{
                     temp->next = new ListNode(list2->val);
                    temp =temp->next;
                    list2 = list2->next;
                }
            }
        }
        
        
        while(list1!=NULL){
            if(newnode==NULL){
                    newnode = new ListNode(list1->val);
                    temp = newnode;
                    list1 = list1->next;
                }
                else{
                    temp->next = new ListNode(list1->val);
                    temp =temp->next;
                    list1 = list1->next;
                }
            
        }
        while(list2!=NULL){
           if(newnode==NULL){
                     newnode = new ListNode(list2->val);
                    temp = newnode;
                    list2 = list2->next;
                }
                else{
                     temp->next = new ListNode(list2->val);
                    temp =temp->next;
                    list2 = list2->next;
                }
            
        }
        return newnode;
    }
};
