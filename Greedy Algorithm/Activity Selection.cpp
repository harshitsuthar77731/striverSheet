  public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++)
            vp.push_back({end[i],start[i]});
        sort(vp.begin(),vp.end());
        int count = 1;
        int dep = vp[0].first;
        for(int i=1;i<n;i++){
            if(vp[i].second>dep){
                count++;
                dep = vp[i].first;
            }
        }
        return count;
    }
