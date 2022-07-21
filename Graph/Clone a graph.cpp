class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        if(mp.find(node)!=mp.end())
            return mp[node];
        Node* temp = new Node(node->val);
        mp[node] = temp;
        for(auto x: node->neighbors)
                temp->neighbors.push_back(cloneGraph(x));
        return temp;
    }
};
