class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        unordered_map<Node*,Node*>tempmp;
        int temp = head->val;
        Node* newhead = NULL;
        Node* temphead = head;
        while(temphead){
            Node* no = new Node(temphead->val);
            tempmp[temphead] = no;
            temphead = temphead->next;
            if(newhead==NULL)
                newhead = no;
        }
        temphead = newhead;
        while(head){
            if(head->next)
                temphead->next = tempmp[head->next];
            else
                temphead->next = NULL;
            if(head->random)
                temphead->random = tempmp[head->random];
            else
                temphead->random = NULL;
            temphead= temphead->next;
            head = head->next;
        }
        
        return newhead;
    }
};
