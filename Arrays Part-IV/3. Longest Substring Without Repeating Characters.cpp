class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int i = 0;
        int j = 0;
        int count = 0;
        int ans = 0;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp[s[j]]>1){
                while(mp[s[j]]>1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            if(ans<mp.size())
                ans = mp.size();
            j++;
        }
        return ans;
    }
};
