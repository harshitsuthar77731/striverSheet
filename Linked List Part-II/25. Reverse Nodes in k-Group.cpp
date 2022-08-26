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
// method 1 /// 

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* temp = NULL;
        ListNode* newnode = NULL;
        while(head){
            temp = head->next;
            head->next = newnode;
            newnode = head;
            head = temp;
        }
        return newnode;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* newhead = NULL;
        ListNode* nextpointer = NULL;
        while(true){
            ListNode* temphead = temp;
            ListNode* tempendNode = temp;
            int t = k-1;
            // cout<<t<<endl;
            while(tempendNode&&t--){
                tempendNode = tempendNode->next;
            }
            if(tempendNode)
            {
                temp = tempendNode->next;
                tempendNode->next = NULL;
                
                ListNode* reversed = reverse(temphead);    
                if(newhead==NULL){
                    newhead = reversed;
                    nextpointer = temphead;
                }else{
                    nextpointer->next = reversed;
                    nextpointer = temphead;
                }
            }
            else{
                if(temphead)
                    nextpointer->next = temphead;
                break;
            }
        }
        return newhead;
    }
};




















class Solution {
public:
    int len(ListNode* head){
        int h=0;
        while(head!=NULL)
        {
            h++;
            head = head->next;
        }
        return h;
    }
    ListNode* reverse(ListNode*& head, int k,int& cnt,int cycle){
            cnt++;
            ListNode* newnode = NULL;
            ListNode* temp = NULL;
            ListNode* cp = head;
            int c=k;
            while(head!=NULL&&k--){
                temp = head->next;
                head->next = newnode;
                newnode = head;
                head = temp;
            }
            if(temp!=NULL&&cnt<cycle){
                cp->next = reverse(head,c,cnt,cycle);
            }
            else
                cp->next = head;
        return newnode;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int h  = len(head);
        int t = h/k;
        if(t==0)
            return head;
        int cnt =0;
        return reverse(head,k,cnt,t); 
    }
};
