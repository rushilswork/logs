#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


// 5 1 8 9 2

/*

    1 2 5 - 8 9
*/
class MedianFinder{
    private:
    // for first half
        priority_queue<int> maxheap;
    // for second half
        priority_queue<int, vector<int>,greater<int>> minheap;
    public:
        void addNum(int num){
            // first push it to max heap then balance
            // always make sure that the maxheap size should be >= minheap, == for the even case and > for the odd case to get the median from the top()
            maxheap.push(num);
            // for the first time, initial case and for the case where diff is > 1
            if(maxheap.size() - minheap.size() > 1){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            // for the cases after the initial case, balance based on the value
            if(!maxheap.empty() && !minheap.empty() && maxheap.top() > minheap.top()){
                int x = maxheap.top();
                maxheap.pop();
                int y = minheap.top();
                minheap.pop();

                maxheap.push(y);
                minheap.push(x);
            }


            // cout << "The median is: " << findMedian() << endl;
        }

        // no checks for empty heaps were made cuz, there wont be a case where it crashes
        double findMedian(){
            if(maxheap.size() - minheap.size() == 1){
                return double(maxheap.top());
            }
            else{
                return double((maxheap.top() + minheap.top())/2.0);
            }
        }
};


void TCSOLVE(){
    MedianFinder mf;    

    // im trying to print median for every push
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    for(auto x: v){
        mf.addNum(x);
    }
    // mf.addNum(3);

    cout << "The median is: " << mf.findMedian();
}

int main(){
    ll n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 1;
    while(n--){
        TCSOLVE();
    }
}
