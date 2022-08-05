class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(s.begin(),s.end());
        if(s==t)
            return true;
        return false;
    }
};
