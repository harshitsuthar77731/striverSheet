
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* pre = NULL;
        while(node->next!=NULL){
            node->val = node->next->val;
            pre = node;
            node = node->next;
        }
        pre->next = NULL;
    }
};
