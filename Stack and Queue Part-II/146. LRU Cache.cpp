class ddl{
    public : 
        int _key;
        int _val;
        ddl* pre;
        ddl* next; 
    ddl(int key,int val)
    {
        _key = key;
        _val = val;
    }
};

class LRUCache {
public:
    unordered_map<int,ddl*>mp;
    ddl* head = new ddl(-1,-1);
    ddl* tail = new ddl(-1,-1);
    int cap;
   
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->pre  = head;
    }
    
     void addnode(ddl* newnode){
        ddl*temp = head->next;
        head->next = newnode;
        newnode->pre = head;
        newnode->next = temp;
        temp->pre = newnode;
    }
    void delnode(ddl* node){
        mp.erase(node->_key);
        ddl* temp = node->pre;
        ddl* temp2 = node->next;
        temp->next = temp2;
        temp2->pre = temp;
    }
    
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
         {  
            ddl* temp = mp[key];
            int ans = mp[key]->_val;
            delnode(mp[key]);
            addnode(temp);
            mp[key]= head->next;
            return ans;
         }
        return -1;
    }
    
    void put(int key, int value) {
            if(mp.find(key)!=mp.end()){
                delnode(mp[key]);
                mp.erase(key);
            }
            if(cap==mp.size())
            {
                mp.erase(tail->pre->_key);
                delnode(tail->pre);
            }
        if(mp.find(key)!=mp.end()){
            delnode(mp[key]);
        }
        addnode(new ddl(key,value));
        mp[key] = head->next;
    }
};
