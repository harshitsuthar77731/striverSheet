long long int ans  = 0;
    
    void merge(long long arr[],long long l,long long r){
        long long int mid = (l+(r-l)/2);
        long long temp[500001];
        long long int i = l;
        long long int j = mid+1;
        long long int t = l;
        while(i<=mid&&j<=r){
            if(arr[i]<=arr[j]){
                temp[t++] = arr[i++];
            }
            else
            {   
                //distance from the swaping point
                ans+=(mid-i+1);      // imp step additional point aotherwise same 
                temp[t++] = arr[j++];
            }
        }
        while(i<=mid){
            temp[t++] = arr[i++];
        }
        while(j<=r){
            temp[t++] = arr[j++];
        }
        
        for(int i=l;i<=r;i++){
            arr[i] = temp[i];
        }
        
    }
    void sort(long long arr[], long long l,long long r){
        if(l>=r)
            return ;
        int mid = (l+(r-l)/2);
        sort(arr,l,mid);        // we are sorting l to mid
        sort(arr,mid+1,r);  // we are sorting mid+1 to r
        
        //we assumed that our array is sorted now merge two sorted array from l to mid or mid+1 to r
        merge(arr,l,r);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        sort(arr,0,N-1);
        return ans;
    }
