class Solution {
public:
    string countAndSay(int n) {
        vector<int>v;
        v.push_back(1);
        n--;
        while(n>0){
            vector<int>temp;
            vector<int>temp1;
            vector<int>temp2;
            
            
            int curr = v[0];
            int count = 0;
            for(int i=0;i<v.size();i++){
                if(curr==v[i]){
                    count++;
                }else{
                    temp.push_back(count);
                    temp2.push_back(curr);
                    count = 1;
                    curr= v[i];
                }
            }
            temp.push_back(count);
            temp2.push_back(curr);
            
            
            for(int i=0;i<temp.size();i++){
                temp1.push_back(temp[i]);
                temp1.push_back(temp2[i]);
            }
            v.clear();
            for(auto x:temp1)
                v.push_back(x);
            n--;
        }
        string s = "";
        for(auto x:v){
            s+=to_string(x);
        }
        return s;
    }
};
