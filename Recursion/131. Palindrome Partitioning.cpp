class Solution {
public:
    vector<vector<string>>vs;
    bool ispal(string check){
        if(check.size()==0)
            return false;
        int i=0;
        int j=check.size()-1;
        while(i<=j){
            if(check[i]!=check[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void fun(string s,int ind,vector<string>v){
        
        if(ind==s.size()){
            vs.push_back(v);
            return;
        }
        string t ="";
        for(int i=ind;i<s.size();i++){
            t+=s[i];
            if(ispal(t)){
                v.push_back(t);
                fun(s,i+1,v);
                v.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string>v;
        fun(s,0,v);
        return vs;
    }
};
