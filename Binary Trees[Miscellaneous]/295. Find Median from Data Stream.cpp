class MedianFinder {
public:
    priority_queue<double>pmax;
    priority_queue<double,vector<double>,greater<double>>pmin;
    MedianFinder() {
        
    }
    // we have top put all minm to max priority queu and all max to min priority queue
    void addNum(int num) {
        if(pmin.size()==0)
            pmin.push(num);
        else if(num<pmin.top()){
            if(pmin.size()!=pmax.size()){
                pmax.push(num);
            }
            else{
                if(pmax.top()<num)
                    pmin.push(num);
                else{
                    pmin.push(pmax.top());
                    pmax.pop();
                    pmax.push(num);
                }
            }
        }else{
            if(pmin.size()!=pmax.size()){
                pmax.push(pmin.top());
                pmin.pop();
                pmin.push(num);
            }else{
                pmin.push(num);
            }
        }
    }
    
    double findMedian() {
        if(pmin.size()>pmax.size())
            return pmin.top();
        else if(pmax.size()>pmin.size())
            return pmax.top();
        else{
            return (pmin.top()+pmax.top())/2;
        }
            
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
