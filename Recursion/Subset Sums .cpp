{
public:
    vector<int>v;
    void fun(vector<int> arr, int i,int sum){
        if(i==arr.size())
        {    
            v.push_back(sum);
            return;
        }
        // take 
        fun(arr,i+1,sum+arr[i]);
        // not take;
        fun(arr,i+1,sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        fun(arr,0,0);
        return v;
    }
};
