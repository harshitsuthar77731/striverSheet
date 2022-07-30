int Solution::findMedian(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    int k = (r*c+1)/2;
    
    int minm = INT_MAX;
    int maxm = INT_MIN;
    for(int i=0;i<r;i++){
        minm = min(A[i][0],minm);
        maxm = max(A[i][c-1],maxm);
    }
    
    while(minm<maxm){
        int mid = minm+(maxm-minm)/2;
        int place = 0;
        // find count no. of element less than or equal to current element
        for(int i=0;i<r;i++)
            place+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        
        if(place<k){
            minm = mid+1;
        }else
            maxm = mid;        
    }
    return minm;
}
