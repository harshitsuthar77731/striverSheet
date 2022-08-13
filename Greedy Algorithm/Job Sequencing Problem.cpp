vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int maxp[101] = {0};
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({arr[i].profit,arr[i].dead});
        }
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        int maxd = -1;
        for(int i=0;i<vp.size();i++){
            maxd = max(vp[i].second,maxd);
            if(maxp[vp[i].second-1]==0){
                maxp[vp[i].second-1] = vp[i].first;
            }
            else{
                for(int j=vp[i].second-2;j>=0;j--){
                    if(maxp[j]<vp[i].first){
                        maxp[j] = vp[i].first;
                        break;
                    }
                }
            }
        }
        int count = 0;
        int netp = 0;
        for(int i=0;i<maxd+1;i++){
            if(maxp[i]>0){
                count++;
                netp+=maxp[i];
            }
        }
        return {count,netp};
