// most optimal
#include<bits/stdc++.h>
vector<int> Solution::repeatedNumber(const vector<int> &nums) {
    int x=0,y=0;
    int bit = 0;
    for(int i=0;i<nums.size();i++){
        bit = nums[i]^(i+1)^bit;
    }
    int set_bit = bit&~(bit-1);
    for(int i=0;i<nums.size();i++){
        //all the nums[i] where position of set bit of bit is same else remaining
        if(set_bit&nums[i])
            x = x^nums[i];
        else
            y = y^nums[i];
    }
    // filtering the x and y
    for(int i=0;i<nums.size();i++){
        if(set_bit&(i+1))
            x = x^(i+1);
        else
            y = y^(i+1);
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i]==x)
            return {x,y};
    }
    return {y,x};
}
// 2nd most optimal
// approach two equation x-y and x^2-y^2 solve them;

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> ret(2);
    long long sumOfA = 0, sumOfA2 = 0;
    long long temp;
    int retA, retB;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        temp = A[i];
        sumOfA += temp;
        sumOfA2 += temp*temp;
        temp = i + 1;
        sumOfA -= temp;
        sumOfA2 -= temp*temp;
    }
    sumOfA2 = sumOfA2/sumOfA;
    retA = (int)((sumOfA + sumOfA2)/2);
    retB = (int)(sumOfA2-retA);
    ret[0] = retA;
    ret[1] = retB;
    return ret;
}




// final approach

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
