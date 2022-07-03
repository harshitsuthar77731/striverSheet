vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int arr[A.size()+1]={0};
    for(int i=0;i<A.size();i++){
        arr[A[i]]++;
    }
    int a = -1;
    int b = -1;
    for(int i=1;i<=A.size();i++){
        if(arr[i]==2)
            a = i;
        if(arr[i]==0)
            b = i;
    }
    return {a,b};
}
