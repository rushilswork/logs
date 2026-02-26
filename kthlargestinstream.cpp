#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

class KthLargest{
    public:
        priority_queue<int,vector<int>,greater<int>> pq;
        
        int kt = 0;
        KthLargest(int k, vector<int>nums){
            kt = k;
            for(int i =0 ;i<nums.size();i++){
                pq.push(nums[i]);
                if(pq.size() > kt){
                    pq.pop();
                }
           }
        }

        void add(int val){
            pq.push(val);
            if(pq.size() > kt){
                pq.pop();
            }
            cout <<  kt << " Largest element is: " << pq.top() << endl;;
        }
};

void TCSOLVE(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    ll k;
    cin >> k;

    KthLargest kthlargest(k,v);
    kthlargest.add(2);
    kthlargest.add(6);
    kthlargest.add(60);
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
