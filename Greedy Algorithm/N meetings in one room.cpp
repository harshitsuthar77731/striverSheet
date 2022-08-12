 int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({end[i],start[i]});
        }
        sort(vp.begin(),vp.end());
        int cnt = 1, ended = vp[0].first;
        for(int i=1;i<n;i++){
            if(ended<vp[i].second){
                cnt++;
                ended = vp[i].first;
            }
        }
        return cnt;
    }
