class Solution {
public:
    int myAtoi(string s) {
        int i=0;
int len=s.length();
    if(len==0)
        return 0;
    
    while(i<len && s[i]==' ')
        i++;
    
    if(i==len)
        return 0;
    
    int sign=1;
    if(s[i]=='-'){
        sign=0;
        i++;
    }
    
    else if(s[i]=='+')
        i++;
    
    long int out=0;
    
    while(s[i]>='0' && s[i]<='9'){
        out=out*10;
        if(out<=INT_MIN || out>=INT_MAX){
            break;
        }
        out=out+(s[i]-'0');
        i++;
    }
    
    if(sign==0)
        out=out*(-1);
    
    if(out<=INT_MIN)
        return INT_MIN;
    
     if(out>=INT_MAX)
        return INT_MAX;
    
    return int(out);
}

    };
