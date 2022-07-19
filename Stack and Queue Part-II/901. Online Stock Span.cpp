class StockSpanner {
public:
    vector<int>arr;
    stack<int>st;
    int i = 0;
    StockSpanner() {
    }
    
    int next(int price) {
        arr.push_back(price);
        int temp = 1;
        while(st.size()>0&&arr[st.top()]<=arr[i]){
            st.pop();
            if(st.size()>0)
                temp = i-st.top();
            else
                temp = i+1;
        }
        st.push(i);
        i++;
        return temp;
    }
};
