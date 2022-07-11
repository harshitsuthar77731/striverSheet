void SortedStack :: sort()
{
    vector<int>v;
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]>v[j])
                swap(v[i],v[j]);
        }
    }
    for(auto x : v)
        s.push(x);
   //Your code here
}
