class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        
        ListNode* temp1=A,*temp2 = B;
        while(temp1!=temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
            if(temp1==temp2)
                return temp1;
            if(temp1==NULL)
                temp1 = B;
            if(temp2==NULL)
                temp2 = A;
            
        }
        return temp1;
    }
};
