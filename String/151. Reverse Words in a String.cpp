class Solution {
public:
    string reverseWords(string s) {
        string ans= "";
        bool flag= true;
        string temp = "";
        vector<string>vs;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '&&temp.size()>0){
                reverse(temp.begin(),temp.end());
                vs.push_back(temp);
                temp = "";
            }
            else if(s[i]!=' '){
                temp+=s[i];
                flag=false;
            }
        }
        reverse(temp.begin(),temp.end());
        if(temp.size()>0)
            vs.push_back(temp);
        flag = true;
        for(auto x:vs){
            ans+=x;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};
