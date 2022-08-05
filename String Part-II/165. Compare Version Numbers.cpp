class Solution {
public:
    int compareVersion(string s1, string s2) {
        vector<int>vs1;
        vector<int>vs2;
        int i = 0;
        string temp = "";
        while(i<s1.size()){
            if(s1[i]!='.'){
                temp+=s1[i];
            }
            if(s1[i]=='.'||i==s1.size()-1)
            {
                reverse(temp.begin(),temp.end());
                while(temp.size()>0&&temp[temp.size()-1]=='0')
                    temp.pop_back();
                
                reverse(temp.begin(),temp.end());
                if(temp.size()>0)
                    vs1.push_back(stoi(temp));
                 else
                    vs1.push_back(0);
                temp = "";
            }
            i++;
        }
        
        i = 0;
        temp = "";
        while(i<s2.size()){
            if(s2[i]!='.'){
                temp+=s2[i];
            }
            if(s2[i]=='.'||i==s2.size()-1)
            {
                reverse(temp.begin(),temp.end());
                while(temp.size()>0&&temp[temp.size()-1]=='0')
                    temp.pop_back();
                reverse(temp.begin(),temp.end());
                if(temp.size()>0)
                    vs2.push_back(stoi(temp));
                else
                    vs2.push_back(0);
                temp = "";
            }
            i++;
        }
         i=0;
        int j =0;
        while(i<vs1.size()&&j<vs2.size()){
            if(vs1[i]==vs2[j]){
                i++;
                j++;
            }else if(vs1[i]>vs2[j]){
                return 1;
            }
            else if(vs1[i]<vs2[j]){
                return -1;
            }
        }
        if(vs1.size()>vs2.size()){
            while(i<vs1.size()){
                if(vs1[i]>0)
                    return 1;
                i++;
            }
        }
        else if(vs1.size()<vs2.size()){
            while(j<vs2.size()){
                if(vs2[j]>0)
                    return -1;
                j++;
            }
        }
        return 0;
    }
};
