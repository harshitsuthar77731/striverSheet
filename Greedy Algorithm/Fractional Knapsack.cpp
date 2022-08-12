 double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({(double)arr[i].value/(double)arr[i].weight,arr[i].weight});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        double ans = 0;
        for(int i=0;i<n;i++){
            int t;
            if(w>=v[i].second){
                t =v[i].second;
                w -= t;
            }else{
                t = w;
                w =0;
            }
            // cout<<t<<" "<<v[i].second<<" "<<v[i].first<<endl;
            ans+=v[i].first*t;
        }
        return ans;
    }
