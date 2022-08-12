 
 //method 1
 int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
      //method 2 space->O(n+k),time-> O(nlogn);
    	vector<pair<int,int>>vp;
    	for(int i=0;i<n;i++){
    	    vp.push_back({arr[i],dep[i]});
    	}
    	sort(vp.begin(),vp.end());
    	priority_queue<int,vector<int>,greater<int>>pmin;
    	pmin.push(vp[0].second);
    	int cnt = 1;
    	pair<int,int>p1;
    	for(int i=1;i<n;i++){
    	    if(vp[i].first>pmin.top()){
    	        pmin.pop();
    	        pmin.push(vp[i].second);
    	    }else{
    	        pmin.push(vp[i].second);
    	        cnt++;
    	    }
    	}
    	return cnt;
    }
    //method 2 space->O(1),time-> O(nlogn);
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int cnt = 1,i=1,j=0;
    	int res = 1;
    	while(i<n&&j<n){
    	    if(arr[i]<=dep[j])
    	    {
    	        i++;
    	        cnt++;
    	    }else{
    	        j++;
    	        cnt--;
    	    }
    	   res=max(cnt,res);
    	}
    	return res;
    }
