/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        int h1 = 0;
        int h2 = 0;
        ListNode* temp1=A,*temp2 = B;
        while(temp1!=NULL)
        {
            h1++;
            temp1 = temp1->next;
        }
        while(temp2!=NULL)
        {
            h2++;
            temp2 = temp2->next;
        }
        if(h1>=h2){
            int t = h1-h2;
            while(t>0){
                A = A->next;
                t--;
            }
            while(h2>0){
                if(A==B)
                    return A;
                A = A->next;
                B = B->next;
            }
            
        }
        if(h2>h1){
             int t = h2-h1;
            while(t>0){
                B = B->next;
                t--;
            }
            while(h1>0){
                if(A==B)
                    return A;
                A = A->next;
                B = B->next;
            }
        }
        
        return NULL;
    }
};
