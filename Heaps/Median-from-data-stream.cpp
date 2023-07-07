class MedianFinder {
private:
priority_queue<int>smallHeap;
priority_queue<int,vector<int>,greater<int>> largeHeap; 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);

        // every element in smallHeap should be <= largeHeap
        if(smallHeap.size()!=0 && largeHeap.size()!= 0 && smallHeap.top()> largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        // for uneven size of heaps
        if(smallHeap.size()> largeHeap.size()+1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if(largeHeap.size() > smallHeap.size()+1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(largeHeap.size()> smallHeap.size()){
            return (double)largeHeap.top();
        }
        if(smallHeap.size() > largeHeap.size()){
            return (double)smallHeap.top();
        }

        return (smallHeap.top()+largeHeap.top()) / (double)2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */