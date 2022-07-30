public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int maxm = max(arr1[n-1],arr2[m-1]);
        int minm = min(arr1[0],arr2[0]);
        
        while(minm<=maxm){
            int mid = minm + (maxm-minm)/2;
            int place = 0;
            place+=upper_bound(arr1,arr1+n,mid)-arr1;
            place+=upper_bound(arr2,arr2+m,mid)-arr2;
            if(place<k)
                minm = mid+1;
            else
                maxm = mid-1;
        }
        return minm;
    }
